"""Compare iris images."""
import argparse
import logging
import os
import queue
import threading
import queue
import yaml

from datetime import datetime
from test_iriscompare import IrisCompare
import report

logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
                    level=logging.DEBUG)
logger = logging.getLogger(__name__)

PASS = 'Pass'
FAIL = 'Fail'

def parse_arg():
   parser = argparse.ArgumentParser(description=__doc__.strip(),
                                    formatter_class=argparse.ArgumentDefaultsHelpFormatter)
   parser.add_argument('-y', '--yaml-file', required=True,
                       help='YAML test case file')
   parser.add_argument('-d', '--output-dir', default='reports',
                       help='Test output dir. Default: reports')
   parser.add_argument('-o', '--output-file', default='bulk-output',
                       help='Test output file with out ext. Default: bulk-output')
   parser.add_argument('-w', '--num-workers', default=10,
                       help='Number of concurrent works. Default=10, but will be adjusted at execution time.')
   return parser.parse_args()

class IrisCompareTest(object):
    def __init__(self, test_yaml_file):
        with open(test_yaml_file, 'r') as f:
            data = yaml.load(f, Loader=yaml.FullLoader)
        self._config = data.get('config')
        self._tests = data.get('tests')
        logger.info('Test file is parsed: %s' % args.yaml_file)

        now = datetime.now()
        self.dt_string = now.strftime('%m/%d/%Y %H:%M:%S')
        logger.debug(self._config)
        logger.debug(self._tests)

    def run_tests(self):
        base_iris_img = self._config.get('iris_img_data_path')
        compare = IrisCompare()
        for _, v in self._tests.items():
            dir_name = v.get('dir')
            side = v.get('side')
            expected_res = v.get('expected_result')

            compare.set_base_img(os.path.join(base_iris_img,
                dir_name, side, v.get('base_img')))
            compare.set_target_img(os.path.join(base_iris_img,
                dir_name, side, v.get('target_img')))

            res = compare.run_test()
            if expected_res == res:
                print(PASS)
            else:
                print(FAIL)

class IrisCompareWorker(threading.Thread):
    def __init__(self, config, test_queue, res_queue, name):
        super(IrisCompareWorker, self).__init__(name=name)
        self._config = config
        self._test_queue = test_queue
        self._res_queue = res_queue
        self._stop_event = threading.Event()
        self._thread_name = name

    def stop(self):
        return(self._stop_event.is_set())

    def _run_test(self, base_iris_img, test):
        test_type = test.get('type')
        if test_type == 'P':
            target_dir_name = base_dir_name = test.get('dir')
            target_side = base_side = target_side = test.get('side')
        elif test_type == 'N-A':
            target_dir_name = base_dir_name = test.get('dir')
            base_side = test.get('base_side')
            target_side = test.get('target_side')
        elif test_type == 'N-B':
            base_dir_name = test.get('base_dir')
            target_dir_name = test.get('target_dir')
            base_side = test.get('base_side')
            target_side = test.get('target_side')

        expected_res = test.get('expected_result')

        compare = IrisCompare()
        compare.set_base_img(os.path.join(base_iris_img,
            base_dir_name, base_side, test.get('base_img')))
        compare.set_target_img(os.path.join(base_iris_img,
            target_dir_name, target_side, test.get('target_img')))
        result, dist = compare.run_test()
        res = result == expected_res
        return (res, dist)

    def run(self):
        base_iris_img = self._config.get('iris_img_data_path')
        while True:
            try:
                t = self._test_queue.get_nowait()
                test_case = t[0]
                test = t[1]
            except queue.Empty:
                break

            logging.info('Test case %s start on thread %s' % (test_case, self._thread_name))
            res, dist = self._run_test(base_iris_img, test)
            logging.debug('test case: %s, result: %s, %s'% (test_case, res, dist))
            self._res_queue.put([test_case, res, dist])
            self._test_queue.task_done()
            logging.info('Test case %s on thread %s done' % (test_case, self._thread_name))

class BulkIrisCompare(object):
    def __init__(self, args):
        self.test_queue = queue.Queue()
        self.res_queue = queue.Queue()
        self.workers = []
        self.num_workers = args.num_workers
        self._test_yaml_file = args.yaml_file
        self.results = []
        self.__output_dir = args.output_dir
        self.__output_file = args.output_file
        self.decimal_points = 3

    def run(self):
        with open(self._test_yaml_file) as f:
            data = yaml.load(f, Loader=yaml.FullLoader)
            self.config = data.get('config')
            tests = data.get('tests') # {test1: {test content}, ...}

        for test in tests.items():
            self.test_queue.put(test)

        n = self.num_workers if len(tests) > self.num_workers else len(tests)
        logging.info('Using %d threads for tests.', n)
        for i in range(n):
            worker = IrisCompareWorker(self.config,
                                       self.test_queue,
                                       self.res_queue,
                                       'worker-%d' % i)
            self.workers.append(worker)
            worker.start()

        fn = 0 # false negative
        fp = 0 # false positive
        tp = 0 # true positive
        tn = 0 # true negative
        while tests:
            case, res, dist = self.res_queue.get()
            c = tests[case]
            if c.get('type') == 'P':
                self.results.append({
                    'type': 'P',
                    'case': case,
                    'dir': c.get('dir'),
                    'side': c.get('side'),
                    'base_img': c.get('base_img'),
                    'target_img': c.get('target_img'),
                    'expected_result': c.get('expected_result'),
                    'test_result': PASS if res else FAIL,
                    'hamming_dist': str(dist).split(':')[-1].strip()
                })
            elif c.get('type') == 'N-A':
                self.results.append({
                    'type': 'N-A',
                    'case': case,
                    'dir': c.get('dir'),
                    'base_side': c.get('base_side'),
                    'base_img': c.get('base_img'),
                    'target_side': c.get('target_side'),
                    'target_img': c.get('target_img'),
                    'expected_result': c.get('expected_result'),
                    'test_result': PASS if res else FAIL,
                    'hamming_dist': str(dist).split(':')[-1].strip()
                })
            elif c.get('type') == 'N-B':
                self.results.append({
                    'type': 'N-B',
                    'case': case,
                    'base_dir': c.get('base_dir'),
                    'base_side': c.get('base_side'),
                    'base_img': c.get('base_img'),
                    'target_dir': c.get('target_dir'),
                    'target_side': c.get('target_side'),
                    'target_img': c.get('target_img'),
                    'expected_result': c.get('expected_result'),
                    'test_result': PASS if res else FAIL,
                    'hamming_dist': str(dist).split(':')[-1].strip()
                })

            # calculate stat
            if c.get('expected_result'):
                if res:
                    tp += 1
                else:
                    fn += 1
            else:
                if res:
                    fp += 1
                else:
                    tn += 1

            del tests[case]

        while self.workers:
            self.workers.pop().join()

        tot = len(self.results)
        precision = round(tp/(tp+fp), self.decimal_points)
        recall = round(tp/(tp+fn), self.decimal_points)
        f1 = 2 * ((precision * recall) / (precision + recall))
        f1_score = round(f1, self.decimal_points)

        self.stat = {
            'total': tot,
            'tp': tp,
            'tp_rate': round(float(tp/tot), self.decimal_points),
            'fp': fp,
            'fp_rate': round(float(fp/tot), self.decimal_points),
            'fn': fn,
            'fn_rate': round(float(fn/tot), self.decimal_points),
            'tn': tn,
            'tn_rate': round(float(tn/tot), self.decimal_points),
            'precision': precision,
            'recall': recall,
            'f1_score': f1_score
        }
        self.results = sorted(self.results, key=lambda k: k['hamming_dist'], reverse=True)

    def show_results(self):
        print(self.stat)
        for res in self.results:
            print(res)

    def store_result_as_yaml(self):
        r = report.YamlReport(self.__output_dir, self.__output_file,
                              self.config, self.results, self.stat)
        r.generate()

    def store_result_as_html(self):
        r = report.HtmlReport(self.__output_dir, self.__output_file,
                              self.config, self.results, self.stat)
        r.generate()

def main(args):
    # iriscompare = IrisCompareTest(args.yaml_file)
    # iriscompare.run_tests()

    iriscompare = BulkIrisCompare(args)
    iriscompare.run()
    iriscompare.show_results()
    iriscompare.store_result_as_yaml()
    iriscompare.store_result_as_html()


if __name__ == '__main__':
    args = parse_arg()
    main(args)

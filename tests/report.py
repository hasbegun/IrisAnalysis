"""Generate test reports"""
import argparse
import logging
import os
import yaml

from datetime import datetime
from jinja2 import Template

logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
                    level=logging.DEBUG)
logger = logging.getLogger(__name__)

class Report(object):
    def __init__(self, output_dir, output_file):
        self.__output_dir = output_dir
        self.check_out_dir()
        now = datetime.now()
        self.dt_string = now.strftime('%m/%d/%Y %H:%M:%S')

    def check_out_dir(self):
        if not os.path.exists(self.__output_dir):
            os.mkdir(self.__output_dir)


class YamlReport(Report):
    def __init__(self, output_dir, output_file, config, results, stat):
        super(YamlReport, self).__init__(output_dir, output_file)
        self._template_file = os.path.join('templates', 'yaml_report.jinja')
        self._config = config
        self._results = results
        self._stat = stat
        self._output_dir = output_dir
        self._output_file = output_file
        self._ext = 'yaml'

    def generate(self):
        with open(self._template_file, 'r') as fh_:
            tm = Template(fh_.read())

        # FIXME: need to remap to the home dir....
        self._config['iris_img_data_path'] = '/Users/inho.choi/devel/alphablocks/datasets/iris/CASIA-Iris-Interval'

        t = tm.render(config=self._config, test_date_time=self.dt_string,
            results=self._results, stat=self._stat)
        with open(os.path.join(self._output_dir,
            '%s.%s' % (self._output_file, self._ext)), 'w') as fh_:
            fh_.write(t)

class HtmlReport(Report):
    def __init__(self, output_dir, output_file, config, results, stat):
        super(HtmlReport, self).__init__(output_dir, output_file)
        self._template_file = os.path.join('templates', 'html_report.jinja')
        self._config = config
        self._results = results
        self._stat = stat
        self._output_dir = output_dir
        self._output_file = output_file
        self._ext = 'html'

    def generate(self):
        with open(self._template_file, 'r') as fh_:
            tm = Template(fh_.read())

        t = tm.render(config=self._config,
            test_date_time=self.dt_string,
            results=self._results, stat=self._stat)
        with open(os.path.join(self._output_dir,
            '%s.%s' % (self._output_file, self._ext)), 'w') as fh_:
            fh_.write(t)

        logger.info("%s is generated." % os.path.join(self._output_dir,
            '%s.%s' % (self._output_file, self._ext)))

def parse_yaml(yaml_file):
    with open(yaml_file, 'r') as f:
        data = yaml.load(f, Loader=yaml.FullLoader)
    config = data.get('config')
    stat = data.get('stat')
    results = []

    for r in data.get('test_results').items():
        t = r[1].get('type')
        if t == 'A':
            results.append({'case': r[0],
                'type': 'A',
                'dir': r[1].get('dir'),
                'side': r[1].get('side'),
                'base_img': r[1].get('base_img'),
                'target_img': r[1].get('target_img'),
                'expected_result': r[1].get('expected_result'),
                'test_result': r[1].get('test_result'),
                'hamming_dist': r[1].get('hamming_dist')
            })
        elif t=='B':
            results.append({'case': r[0],
                'type': 'B',
                'dir': r[1].get('dir'),
                'base_side': r[1].get('base_side'),
                'base_img': r[1].get('base_img'),
                'target_side': r[1].get('target_side'),
                'target_img': r[1].get('target_img'),
                'expected_result': r[1].get('expected_result'),
                'test_result': r[1].get('test_result'),
                'hamming_dist': r[1].get('hamming_dist')
            })

    now = datetime.now()
    dt_string = now.strftime('%m/%d/%Y %H:%M:%S')
    return (config, results, dt_string, stat)

def parse_arg():
    parser = argparse.ArgumentParser(description=__doc__.strip(),
                                    formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument('-y', '--yaml_file', required=True,
                       help='yaml file to read')
    parser.add_argument('-d', '--output-dir', default='reports',
                       help='Test output dir. Default: reports')
    parser.add_argument('-o', '--output-file', default='bulk-output',
                       help='Test output file with out ext. Default: bulk-output')
    parser.add_argument('-t', '--test-datetime', default=None,
                       help='Test datatime')
    return parser.parse_args()

def main():
    args = parse_arg()
    # parse_yaml(args.yaml_file)
    config, results, dt_string, stat = parse_yaml(args.yaml_file)
    o = HtmlReport(args.output_dir, args.output_file, config, results, stat)
    o.generate()

if __name__ == '__main__':
    main()

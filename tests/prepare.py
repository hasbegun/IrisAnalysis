"""Read iris image database and generate yaml test files

"""
import argparse
from jinja2 import Template
import logging
import os
import yaml

logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
                    level=logging.DEBUG)
logger = logging.getLogger(__name__)


class GenerateIrisIntervalTestCases(object):
    def __init__(self, img_db_path, output_file):
        if img_db_path[0] == '~':
            self._img_db_path = os.path.join(os.getenv, img_db_path)
        else:
            self._img_db_path = img_db_path
        self._output_file = output_file
        self.raw_data = {}
        self.true_cases = {}
        self.false_cases = {}
        self.cnt = 1
        self.tests = []
        self._config = {
            'irisImgDataPath': '/home/developer/projects/datasets/iris/CASIA-Iris-Interval',
            'defaultIrisImgQuality': 0.30,
            'defaultHammingDistThreshold': 0.39,
            'execPath': os.path.join(os.sep, 'usr', 'local', 'alphablocks')}
        self.supporting_img_types = ['png', 'jpg', 'jpeg', 'bmp']
        logger.info('Image db path: %s', self._img_db_path)

    def _lower_triangle_cases(self, vector):
        """Take the lower triangle of the square matrix
            1 | 2  3  4      ... n
            --+-------------------
            1 | 0
            2 | 1  0
            3 | 1  1  0
            4 | 1  1  1  0
            . | ...
            . | ...
            . | ...
            n | 1  1  1  1  ... 0
            ----------------------
        """
        if not vector: vector = []
        n = len(vector)
        for i in range(n):
            for j in range(i+1, n):
                yield [vector[i], vector[j]]

    def _lower_triangle_cases2(self, vector1, vector2):
        """Take the lower triangle of the matrix
            1 | 2  3  4      ... n
            --+-------------------
            1 | 0
            2 | 1  0
            3 | 1  1  0
            4 | 1  1  1  0
            . | ...
            . | ...
            . | ...
            m | 1  1  1  1  ... 0
            ----------------------
        """
        if not vector1: vector1 = []
        if not vector2: vector2 = []
        n = len(vector1)
        m = len(vector2)
        for i in range(n):
            for j in range(i+1, m):
                yield [vector1[i], vector2[j]]

    def _generate_positive_cases(self):
        """ Generate true cases
            final data structure is
            {case 1: [file1, file2],
             case 2: [file1, file3], ...}
        """
        case_type = 'P'
        for k, v in self.raw_data.items():
            for side, files in v.items():
                for case in self._lower_triangle_cases(files):
                    key = '%s-%d' % (case_type, self.cnt)
                    if str(case[0]).split('.')[-1] not in self.supporting_img_types:
                        logger.warn('%s is not supported format. Ingored', case[0])
                        continue
                    if str(case[1]).split('.')[-1] not in self.supporting_img_types:
                        logger.warn('%s is not supported format. Ingored', case[1])
                        continue
                    self.cnt += 1
                    self.tests.append({
                        'type': case_type,    # positive
                        'case': key,
                        'dir': str(k),
                        'side': side,
                        'base_img': case[0],
                        'target_img': case[1],
                        'expected_result': True
                    })

    def _false_cases_type_1(self, vectors):
        # permute L and R in the same case.
        R = vectors.get('R')
        L = vectors.get('L')
        if not R: R = []
        if not L: L = []
        for r in R:
            for l in L:
                yield("R", r, "L", l)

    def _false_cases_type_3(self):
        keys = list(self.raw_data.keys())
        sides = ['R', 'L']
        case_type = 'N-B'
        for dcase in self._lower_triangle_cases(keys):
            # [case 1, case 2]
            # generate case1-r - case2-r
            #          case1-r - case2-l
            #          case1-l - case2-l
            #          case1-l - case2-r
            n = self.raw_data.get(dcase[0])
            m = self.raw_data.get(dcase[1])
            for n_side in sides:
                n_vec = n.get(n_side)
                for m_side in sides:
                    m_vec = m.get(m_side)
                    for case in self._lower_triangle_cases2(n_vec, m_vec):
                        if str(case[0]).split('.')[-1] not in self.supporting_img_types:
                            logger.warn('%s is not supported format. Ingored', case[0])
                            continue
                        if str(case[1]).split('.')[-1] not in self.supporting_img_types:
                            logger.warn('%s is not supported format. Ingored', case[1])
                            continue
                        self.cnt += 1
                        self.tests.append({
                            'type': case_type,
                            'case': '%s%d' % (case_type, self.cnt),
                            'base_dir': dcase[0],
                            'base_side': n_side,
                            'base_img': case[0],
                            'target_dir': dcase[1],
                            'target_side': m_side,
                            'target_img': case[1],
                            'expected_result': False
                        })

    def _false_cases_type_1n2(self):
        # Generate type 1 and 2
        case_type = 'N-A'
        for k, v in self.raw_data.items():
            for base_side, base_img, target_side, target_img in self._false_cases_type_1(v):
                if base_img.split('.')[-1] not in self.supporting_img_types:
                    logger.info('%s is not supported format. Ingored', base_img)
                    continue
                if target_img.split('.')[-1] not in self.supporting_img_types :
                    logger.info('%s is not supported format. Ingored', target_img)
                    continue
                self.cnt += 1
                self.tests.append({
                    'type': case_type,    # negative type A: permute L and R
                    'case': '%s%d' % (case_type, self.cnt),
                    'dir': str(k),
                    'base_side': base_side,
                    'base_img': base_img,
                    'target_side': target_side,
                    'target_img': target_img,
                    'expected_result': False
                })

    def _generate_negative_cases(self):
        self._false_cases_type_1n2()
        self._false_cases_type_3()

    def _write(self):
        with open(os.path.join('templates', 'testcases.jinja')) as fh_:
            tm = Template(fh_.read())
        t = tm.render(config=self._config, tests=self.tests)
        with open(os.path.join(self._output_file), 'w') as fh_:
            fh_.write(t)
        logger.info('Written the test file: %s' % self._output_file)

    def _prepare(self):
        for d in os.listdir(self._img_db_path): # case numbers
            self.raw_data[d] = {}
            if d in ['.DS_Store']: continue
            for s in os.listdir(os.path.join(self._img_db_path, d)): # L and R
                if s in ['.DS_Store']: continue
                p = os.path.join(self._img_db_path, d, s)
                for (_, _, filenames) in os.walk(p): # files in list [...]
                    self.raw_data[d][s] = filenames

    def generate(self):
        self._prepare()
        self._generate_positive_cases()
        self._generate_negative_cases()
        self._write()

def parse_arg():
   parser = argparse.ArgumentParser(description=__doc__.strip(),
                                    formatter_class=argparse.ArgumentDefaultsHelpFormatter)
   parser.add_argument('-d', '--img-db-path',
                       default='/home/developer/projects/datasets/iris/CASIA-Iris-Interval',
                       help='Image database path.')
   parser.add_argument('-o', '--output-file',
                       default='tests.yaml',
                       help='Image database path.')
   return parser.parse_args()

def main():
    args = parse_arg()
    test = GenerateIrisIntervalTestCases(args.img_db_path, args.output_file)
    test.generate()


if __name__ == '__main__':
    main()
"""Compare iris and return its result."""
import argparse
import logging
import subprocess, os

logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
                    level=logging.DEBUG)
logger = logging.getLogger(__name__)

class IrisCompare(object):
    def __init__(self, base_img=None, target_img=None, exec_path='/usr/local/alphablocks'):
        self._base_img = base_img
        self._target_img = target_img

        self.runtime_env = os.environ.copy()
        self.runtime_env["PATH"] = "%s/bin:" % exec_path + self.runtime_env["PATH"]

    def set_base_img(self, img):
        self._base_img = img

    def set_target_img(self, img):
        self._target_img = img

    def run_test(self):
        res = 0
        if self._base_img and self._target_img:
            cmd = ['IrisCompare', '-b', self._base_img, '-t', self._target_img]
            p = subprocess.Popen(cmd, env=self.runtime_env, stdout=subprocess.PIPE)
            out, err = p.communicate()
            logger.debug("out: %s\nerr: %s" %(out, err))
            out = str(out).split('\\n')
            res, dist = self.__parse_output(out)
            res = True if res == '1' else False
        return(res, dist)

    def __parse_output(self, out):
        return(out[-2], out[-3])

def parse_arg():
   parser = argparse.ArgumentParser(description=__doc__.strip(),
                                    formatter_class=argparse.ArgumentDefaultsHelpFormatter)
   parser.add_argument('-b', '--base-img', required=True,
                       help='Base iris image.')
   parser.add_argument('-t', '--target-img', required=True,
                       help='Target iris image to compare.')
   parser.add_argument('-i', '--img-quality', type=float, default=0.30,
                       help='Minimum image quality done by Sobel.')
   parser.add_argument('-d', '--hamming-dist', type=float, default=0.39,
                       help='Hamming dist threshold value.')
   parser.add_argument('-e', '--exec-path', default='/usr/local/alphablocks',
                       help='IrisComare executible path. Default: /usr/local/alphsblocks')
   return parser.parse_args()

def main():
    args = parse_arg()
    test = IrisCompare(args.base_img, args.target_img, args.exec_path)
    res = test.run_test()
    print(res)

if __name__ == '__main__':
    main()
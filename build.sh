#!/usr/bin/env bash

echo "Build IrisAnalysis Qt App."
BUILD_DIR="build"

if [ -d ${BUILD_DIR} ]; then
	echo "==================="
	echo "remove build dir..."
	echo "==================="
	rm -rf ${BUILD_DIR}
fi
mkdir ${BUILD_DIR}
cd build
qmake ../IrisAnalysis.pro
# cmake ..
make -j4

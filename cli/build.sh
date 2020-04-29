BLD_DIR=build

if [ "$1" = "clean" ]; then
    if [ -d "${BLD_DIR}" ]; then
        rm -rf ${BLD_DIR}
    fi
    mkdir ${BLD_DIR}
fi

cd ${BLD_DIR}
cmake ..
make

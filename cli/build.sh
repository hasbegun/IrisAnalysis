BLD_DIR=build

if [ "$1" = "clean" ]; then
    if [ -d "${BLD_DIR}" ]; then
        rm -rf ${BLD_DIR}
    fi
    mkdir ${BLD_DIR}
fi

cd ${BLD_DIR}
cmake -DCMAKE_INSTALL_PREFIX=/usr/local/alphablocks ..
make -j$(nproc) && sudo make install

set -e

mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release -j8

ctest
./bin/validate
./bin/run_experiments

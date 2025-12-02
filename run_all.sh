set -e

mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release -j8

ctest
/usr/bin/time -l ./bin/main 2 -n
/usr/bin/time -l ./bin/main 2 -s 2
/usr/bin/time -l ./bin/main 4 -n
/usr/bin/time -l ./bin/main 4 -s 2
/usr/bin/time -l ./bin/main 8 -n
/usr/bin/time -l ./bin/main 8 -s 2
/usr/bin/time -l ./bin/main 8 -s 4
/usr/bin/time -l ./bin/main 16 -n
/usr/bin/time -l ./bin/main 16 -s 2
/usr/bin/time -l ./bin/main 16 -s 4
/usr/bin/time -l ./bin/main 16 -s 8
/usr/bin/time -l ./bin/main 64 -n
/usr/bin/time -l ./bin/main 64 -s 2
/usr/bin/time -l ./bin/main 64 -s 4
/usr/bin/time -l ./bin/main 64 -s 8
/usr/bin/time -l ./bin/main 64 -s 16
/usr/bin/time -l ./bin/main 64 -s 32
/usr/bin/time -l ./bin/main 128 -n
/usr/bin/time -l ./bin/main 128 -s 2
/usr/bin/time -l ./bin/main 128 -s 4
/usr/bin/time -l ./bin/main 128 -s 8
/usr/bin/time -l ./bin/main 128 -s 16
/usr/bin/time -l ./bin/main 128 -s 32
/usr/bin/time -l ./bin/main 128 -s 64
/usr/bin/time -l ./bin/main 512 -n
/usr/bin/time -l ./bin/main 512 -s 4
/usr/bin/time -l ./bin/main 512 -s 8
/usr/bin/time -l ./bin/main 512 -s 16
/usr/bin/time -l ./bin/main 512 -s 32
/usr/bin/time -l ./bin/main 512 -s 64
/usr/bin/time -l ./bin/main 512 -s 128
/usr/bin/time -l ./bin/main 512 -s 256
/usr/bin/time -l ./bin/main 1024 -n
/usr/bin/time -l ./bin/main 1024 -s 8
/usr/bin/time -l ./bin/main 1024 -s 16 
/usr/bin/time -l ./bin/main 1024 -s 32
/usr/bin/time -l ./bin/main 1024 -s 64
/usr/bin/time -l ./bin/main 1024 -s 128
/usr/bin/time -l ./bin/main 1024 -s 256
/usr/bin/time -l ./bin/main 1024 -s 512

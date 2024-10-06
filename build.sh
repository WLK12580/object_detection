#bash/bin/
#  gcc window.cpp -lglut -lGL -lGLU -o test
cmake -B build
cmake --build build/
./build/test
@echo off
if not exist build mkdir build
pushd build
gcc -c ..\src\*.c -g -Wall -m64 & g++ *.o -o main.exe -lmingw32 -lgdi32
popd
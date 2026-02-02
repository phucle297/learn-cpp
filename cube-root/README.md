# Document

https://github.com/vqhBook/C/blob/master/BikipC_Q1.pdf

# Build and run

```sh
cd cube-root

cmake -S . -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
./build/cube-root
```

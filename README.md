# Introduction

This repository is a template used for autotools projects. It's designed around C and C++ projects and Google Test but can be easily adapted to other scenarios. 

This repository has a github action to run the unit tests on commits to branches main and dev. 

# Dependencies 

This depends on having standard autotools available along with Google Test, Google Benchmark, C++ Boost and the GNU MultiPrecision library. 

# Building

```
autoreconf -vfi
./configure
make check
```

This will run the unit tests. To run benchmarks simply run 

```
src/benchmark
```

## includes and libs 

Recall if you need to add include and library paths

```
./configure CPPFLAGS="-I/opt/homebrew/include" LDFLAGS="-L/opt/homebrew/lib"
```

bin_PROGRAMS = test benchmark

benchmark_SOURCES = benchmark.cpp 
# I would love for this to be found by configure but you try getting autoconf to find C++ only libraries 
# we depend on finding the header file there
benchmark_LDADD = -lbenchmark
test_SOURCES = test.cpp fibonacci_test_data.cpp
TESTS = test


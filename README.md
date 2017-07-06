# Computing beta inequalities

This package provides a Python and C++ library to compute Pr(X >= Y), where X and Y are beta distributions, exactly.
It is based on the following reference.

## Dependencies

* Modern C++ compiler
* Boost
* Boost-Python

## Compilation instructions

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Usage instructions

```
$ ipython

In [1]: import beta_difference as bd

In [2]: bd.prob(10,10,10,10)
Out[2]: 0.5

In [3]: bd.prob(10,89,10,15)
Out[3]: 0.0003591730113861047
```

[1] Cook, J. (2005) Exact calculation of beta inequalities. *Technical report.* UT MD Anderson Cancer Center Department of Biostatistics.

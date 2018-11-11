# crdt

[![Build Status](https://travis-ci.org/dgkimura/crdt.svg?branch=master)](https://travis-ci.org/dgkimura/crdt)

The crdt project implements various conflict-free (convergent) replicated
data-types. It provides a library for maintaining consistency within a
distributed system.

## Build
You will need a compiler with full C++11 support. You can then use CMake to
generate MakeFiles for this project.
```
$ mkdir build && cd build
$ cmake ..
$ make && ./unittests/all_unittests
```

## Data Types
- gcounter
- pncounter
- lwwregister
- orset

## References
- [A comprehensive study of Convergent and Commutative Replicated Data Types](https://hal.inria.fr/inria-00555588/document)

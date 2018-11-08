# crdt

[![Build Status](https://travis-ci.org/dgkimura/crdt.svg?branch=master)](https://travis-ci.org/dgkimura/crdt)

## Build
You will need a compiler with full C++11 support. You can then use CMake to
generate MakeFiles for this project.
```
$ mkdir build && cd build
$ cmake ..
$ make && ./unittests/all_unittests
```

## References
- [A comprehensive study of Convergent and Commutative Replicated Data Types](https://hal.inria.fr/inria-00555588/document)

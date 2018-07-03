# Conflict-free Replicated Data Types (CRDTs)

[![release-version](https://img.shields.io/badge/release-beta--version-red.svg)]()
[![build-status-master](https://travis-ci.org/CollabServer/collab-data-crdts.svg?branch=master)](https://travis-ci.org/CollabServer/collab-data-crdts)
[![license](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](https://github.com/CollabServer/collab-data-crdts/blob/master/LICENSE.txt)

| master | dev |
| :-----: | :----: |
| [![build-status-master](https://travis-ci.org/CollabServer/collab-data-crdts.svg?branch=master)](https://travis-ci.org/CollabServer/collab-data-crdts) | [![build-status-dev](https://travis-ci.org/CollabServer/collab-data-crdts.svg?branch=dev)](https://travis-ci.org/CollabServer/collab-data-crdts) |


## Description
Defines a set of basic CRDTs that may be used to build your more complex data (on top of these structures).
CRDTs stands for Conflict-free Replicated Data Structure.
The letter C in CRDT may either stands for "Commutative" or "Convergent".
Commutative is implemented as Operation based CRDT (CmRDT) whereas Convergent is the State based (CvRDT).
To learn more about CRDTs, checkout the links at the end of this readme.


## Features
- CmRDT (Operation-based)
    - LWWGraph: Last-Write-Wins Graph
    - LWWMap: Last-Write-Wins Map
    - LWWRegister: Last-Write-Wins Register
    - LWWSet: Last-Write-Wins Set
- CvRDT (State-based. See warning)
    - 2PSet: Add / Remove set (Two-phases Set)
    - GCounter: Grow-only counter
    - GGraph: Grow-only graph
    - GMap: Grow-only map
    - GSet: Grow-only set
    - LWWRegister: Last-Write-Wins Register
    - PNCounter: Increment / Decrement counter
- custom
    - CollabData: Example of SuperType for data built on tope of CRDTs.
    - Operation: Interface to represents modification on data built on top of CRDTs.
    - OperationObserver: Interface for Operation observer.
    - Timestamp: Example of custom timestamp.
    - SimpleGraph: Example of a directed graph with attributes.

> Warning: I wrote the CvRDTs as an example. They are not meant to be used.
> (At least, some changes may be required).


## Requirements
- C++11
- `pragma once` support
- Tested with gcc 4.8.4
- Tested with clang 5.0.0
- Tested only on Linux. Not support certified for Mac and Windows


## Build instructions

### Build and run tests with CMake
- [GoogleTest](https://github.com/google/googletest)
(Automatically downloaded and built by CMake and placed in project's root
folder `dependencies`)
- Tests naming rule: `MethodName_stateUnderTest`


```bash
# Build and run manually
mkdir build
cd build
cmake -Dcollab_tests=ON ..
make -j4
make runTests

# Build and run from shell script
./build.sh
```


### Build and run examples with CMake
```bash
mkdir build
cd build
cmake -Dcollab_examples=ON ..
make -j4
make runExamplesCmRDT

# Build and run from shell script
./build.sh
cd build
make runExamplesCmRDT
```


## Usage

### Overview
Todo: documentation in-coming.

### Integrate in your project
CRDTs are header only, you need to include the right header.
Include the this project `include` folder in your project path, then include
the data type your want to use.

For instance, to use CmRDT::LWWSet: `#include "collabdata/CmRDT/LWWSet.h"`


### Generate documentation
- [Doxygen](https://www.stack.nl/~dimitri/doxygen/)

Generate documentation with `doxygen Doxyfile`.
Generated files are places in `doc` folder.


## Resources

### CRDTs theoretical description

- **State-based object (CvRDT)** \
CvRDT stands for Convergent Replicated Data Types.
Updates are applied locally, then the whole data state is sent to others.
A merge method integrate two states so that all replicates convergent.

```
    State CvRDT is defined by (S s0 q u m)
        S   -> Global State
        s0  -> State at beginning
        q   -> Query method
        u   -> Update method
        m   -> Merge method
```

- **Operation-based object (CmRDT)** \
CmRDT stands for Commutative Replicated Data Types.
Only delta of change (Operation) are broadcasted and applied to others.
All operations are commutative.

```
    Operation CmRDT is defined by (S s0 q t u P)
        S   -> Global State
        s0  -> State at beginning
        q   -> Query method
        t   -> Side-effect-free prepare update method
        u   -> Effect update method (downstream)
        P   -> Delivery relation P for communication protocol
```


### Papers and web articles
- Conflict-free Replicated Data Types \
(https://pages.lip6.fr/Marc.Shapiro/papers/CRDTs_SSS-2011.pdf)
- A comprehensive study of Convergent and Commutative Replicated Data Types \
(https://pages.lip6.fr/Marc.Shapiro/papers/Comprehensive-CRDTs-RR7506-2011-01.pdf)
- A Look at Conflict-Free Replicated Data Types (CRDT) \
(https://medium.com/@istanbul_techie/a-look-at-conflict-free-replicated-data-types-crdt-221a5f629e7e)
- CRDT for collaborative editing by Irisate \
(https://irisate.com/crdt-for-real-time-collaborative-apps/)


## Author
- Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))

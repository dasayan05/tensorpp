![](./extra/logo.png)

| Linux |
| ----- |
| [![Build Status](https://travis-ci.com/crystalcpp/tensorpp.svg?branch=master)](https://travis-ci.com/crystalcpp/tensorpp) |

### 1. Introduction
This is a community driven project and developed collaboratively under **Crystal, a programming community**, which provides `Tensor` manipulation functionality in modern C++. The design goals of this project are:

1. Designing a `tensor` API similar to that of `torch`
2. Clean API: "Easy to use, hard to misuse"
3. Extendability: Ability to add custom functionality or extending available ones
4. Performance: Quality code generation on varity of platforms and environments

### 2. Dependencies

1. OS: Linux/Windows (not tested on Mac). **Linux** recommended.
2. `CMake >= 3.1`, i.e. modern CMake.
3. Any one of:
	* `Intel MKL`. Get it [here](https://software.intel.com/en-us/mkl). If not found, then
	* `OpenBLAS`. Execute `sudo apt install libopenblas-dev libopenblas-base` to install the *OpenBLAS*.

### 3. Instructions for Building and Running

1. Clone the Repository with:
   1. **(HTTP)** `git clone https://github.com/crystalcpp/tensorpp.git --recursive`
   2. **(SSH)** `git clone git@github.com:crystalcpp/tensorpp.git --recursive`
2. Enter the repository folder with `cd tensorpp`
3. Create a build directory and enter it with: `mkdir build; cd build`
4. Generate Makefile with `cmake ..`, optionally you can configure the build with:
   1. `-DBUILD_BINARIES=OFF` to exclude binaries from building
   2. `-DBUILD_TESTS=OFF` to excludes tests from building
5. Run `make` to build it. Optionally with `-j<N>` flag to parallelize the build on multi-core processors.
6. Run tests with `ctest`. (only possible if `-DBUILD_TESTS=ON` was selected in step 4 which is the default setting).

#### Collaborators

1. Ayan Das

#### Discussion
Join our `slack` [group](https://join.slack.com/t/crystal-code/shared_invite/enQtMzgyOTk3NTc1NDYxLTYwOWVhMGRjNGVmODJhMGQ0OTM5ZGJhOWZhMzhmZWEyMTk0ZGMwZGZjZjM0MzZlNDVkZDkwZjBjYjFjNTRiMTI) for discussion regarding the project. For any other query, mail me at dasayan05@hotmail.com with a subject of **tensorpp**.

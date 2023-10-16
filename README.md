# Calculator

[![CMake on multiple platforms](https://github.com/sergey-brd/calculator/actions/workflows/cmake-multi-platform.yml/badge.svg?branch=main)](https://github.com/sergey-brd/calculator/actions/workflows/cmake-multi-platform.yml)

This is console calculator. This application written in C++. It is intended to perform basic mathematical operations through the command line.

## Installation

To use this calculator, follow these steps:

1. Clone the repository using the following command:

```
git clone https://github.com/sergey-brd/calculator.git
```

2. Navigate to the directory with the application and build it:

```
cd calculator
mkdir build
cd build
cmake --build .
```

3. Run the Unit Tests.

```
./unit_test
```

4. Run the application following the instructions in the "Usage" section.

```
./calculator
```

## Usage

To use the console calculator, follow these steps:

1. Enter the mathematical expression you want to evaluate.

2. Press Enter.

3. View the result on the screen.

Calculator supports the following operations: +, -, *, /, sin, cos

Calculator uses C++ rule for return value:

```
-5 / 2 == -2
-5 / 2. == -2.5
```

For exit enter empty line or press Ctrl+D (for Linux) or Ctrl+Z (for Windows)

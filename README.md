# Parallel Prime Factorization

This project implements a parallel prime factorization algorithm in C++ using OpenMP. The algorithm efficiently computes the prime factors of a given number by leveraging multiple threads for faster computation.

## Features

- **Parallel Processing**: Utilizes OpenMP to perform prime factorization concurrently across multiple threads.
- **Dynamic Scheduling**: Distributes work dynamically among threads for balanced load.
- **Efficient Factorization**: Removes redundant factors to provide a clean list of prime factors.
- **Interactive CLI**: Allows users to input numbers and specify the number of threads interactively.

## Requirements

- C++ compiler (supporting C++11 or later)
- OpenMP library

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/parallel-prime-factorization.git
    cd parallel-prime-factorization
    ```

2. Compile the program with OpenMP support:
    ```bash
    g++ -o factorize factorize.cpp -fopenmp
    ```

    **Note**: Ensure that OpenMP support is enabled in your C++ compiler options. If you are using an IDE, make sure to set OpenMP support to "Yes" or enable it in the project's build settings.

    - For **Visual Studio**:
      1. Right-click on your project in the Solution Explorer and select "Properties".
      2. Go to `Configuration Properties` > `C/C++` > `Language`.
      3. Set `OpenMP Support` to `Yes`.

    - For **Code::Blocks**:
      1. Open your project and go to `Project` > `Build options`.
      2. Select your project in the left pane, then go to the `Compiler settings` tab.
      3. In the `Compiler Flags` tab, check `-fopenmp`.

    - For **CLion**:
      1. Go to `File` > `Settings` > `CMake`.
      2. Add `-fopenmp` to the `CMake options` field.

## Usage

Run the compiled executable:
```bash
./factorize

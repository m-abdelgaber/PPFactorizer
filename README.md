The following text was written using chatGPT, but reviewed and edited by me. 
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
```
The program will prompt you to enter a number to factorize and the number of threads to use:
```bash
Enter the number to factorize: 100
Enter the number of threads: 4
Prime factors of 100 are: 2 2 5 5
Execution time: 0.000123 seconds
```


## Code Overview

### Main Functions

- `parallel_prime_factorization(long long number, int num_threads)`: Performs prime factorization using multiple threads.
- `reduce_factors()`: Reduces the list of factors by combining results from all threads.
- `remove_divisibles(vector<long long>& factors)`: Removes any divisible factors from the list to ensure uniqueness.
- `print_factors(const vector<long long>& factors)`: Prints the list of prime factors.

### Helper Functions

- `factorize_subrange(long long number, int start, int end, vector<long long>& local_factors)`: Factorizes a subrange of numbers.
- `get_max_size_subset_index()`: Gets the index of the subset with the maximum size.
- `countElements(const vector<long long>& vec)`: Counts the occurrences of each element in a vector.
- `getExtraElements(const unordered_map<long long, int>& hashtable1, const unordered_map<long long, int>& hashtable2)`: Finds extra elements in one hashtable compared to another.

## Performance

The execution time of the algorithm depends on the input number and the number of threads used. By increasing the number of threads, you can achieve faster computation times for larger numbers.



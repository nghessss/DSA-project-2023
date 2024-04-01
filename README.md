
# Sorting Algorithm Time Measurement and Comparison
## Overview
This project is designed to measure the execution time and compare the performance of a specific sorting algorithm. Sorting algorithms are essential in computer science for arranging elements in a specified order. This README provides instructions on how to use the provided code to measure the time complexity and compare the efficiency of the chosen sorting algorithm against others.
## To measure the time complexity and compare the efficiency
### 1. Algorithm mode: In this mode, you are asked to run a specified sorting algorithm on the input data, which is either given or generated automatically, and present the resulting running time and/or number of comparisons.
* Command 1: Run a sorting algorithm on the given input data.
    * Prototype: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]
- Ex: a.exe -a radix-sort input.txt -both
- Console output:

![image](https://github.com/nghessss/DSA-project-2023/assets/63101593/954e10e9-2e7a-459d-af2d-23d7fc1afb3d)

* Command 2: Run a sorting algorithm on the data generated automatically with specified size and order.
    * Prototype: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
    * Ex: a.exe -a selection-sort 50 -rand -time
    * Console output:

![image](https://github.com/nghessss/DSA-project-2023/assets/63101593/0b1b22ae-3dca-4aba-ac06-2025f5be380d)

* Command 3: Run a sorting algorithm on ALL data arrangements of a specified size.
    * Prototype: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]
    * Ex: a.exe -a binary-insertion-sort 70000 -comp
    * Console output:
  
![image](https://github.com/nghessss/DSA-project-2023/assets/63101593/f3bc701f-2538-4e80-8b23-c62232fe52f1)


### 2. Comparison mode: In this mode, you have to run TWO specified sorting algorithms on the input data, which is either given or generated automatically, and present the resulting running times and/or numbers of comparisons.
* Command 4: Run two sorting algorithms on the given input.
    * Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]
    * Ex: a.exe -c heap-sort merge-sort input.txt
    * Console output:
  
![image](https://github.com/nghessss/DSA-project-2023/assets/63101593/efb4b077-a9d5-4960-8d63-7ba38d2d4586)

* Command 5: Run two sorting algorithms on the data generated automatically.
    * Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
    * Ex: a.exe -c quick-sort merge-sort 100000 -nsorted
    * Console output:

![image](https://github.com/nghessss/DSA-project-2023/assets/63101593/63313e2f-395c-45e3-acec-1e134dea574c)
### 3. Input arguments: The following arguments are applied for both modes.
* Mode:
    * a: Algorithm mode
    * Comparison mode
* Algorithm name: Lowercase, words are connected by "-" (Ex: selection-sort, binaryinsertion-sort, ...)
    * Input size:
        * Integer (≤ 1, 000, 000)
    * Input order:
        * -rand: randomized data
        * -nsorted: nearly sorted data
        * -sorted: sorted data
        * -rev: reverse sorted data
    * Given input (file): Path to the input file. The file format is as follows.
        * 1st line: an integer n, indicating the number of elements in the input data
        * 2nd line: n integers, separated by a single space.
    * Output parameters
        * -time: algorithms’s running time.
        * -comp: number of comparisions.
        * -both: both above options.

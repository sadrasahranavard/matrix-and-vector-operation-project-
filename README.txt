
              Computer Programming Final Project

Name: Sadra Sahranavard Khatibani
Student ID: 1404010121011

Submission Date: 1404/11/24 - 2026-02-13

                    Project Overview

This project is a basic C++ library for matrix and vector operations.
The user can choose from menu: Matrix Operations or Vector Operations.
Then user enters dimensions and values, and the program does all operations.
Output is shown in terminal and also HTML file.
The HTML file is also basic it is only report of all calculations.

                    Project Files

1. matrix_library.h
   - Header file.
   - Function declarations.

2. matrix_library.cpp
   - Functions implementation.
   - Matrix and Vector operations code.

3. demonstration.cpp
   - Main program file.
   - Including menu, input, output, HTML.
   - HTML style: white background, center aligned, red errors.

4. report_sample.html
   - Created by the program.
   - When you run the program, this file is generated.

5. test_cases.txt
   - This file has sample inputs and outputs.
   - Shows operations and errors.

6. README.txt
   - Student information and project description.

                    Operations

This project has 7 matrix and vector operations:

1. addMatrix - Addition of two matrices
2. subtractMatrix - Subtraction of two matrices
3. scalarMultiplyMatrix : Multiply a matrix by a number
4. multiplyMatrix : Multiply two matrices
5. transposeMatrix : Transpose of a matrix
6. determinant : Determinant of a matrix (recursive method)
7. inverseMatrix : Inverse of a matrix

1. addVector : Addition of two vectors
2. subtractVector : Subtraction of two vectors
3. scalarMultiplyVector : Multiply a vector by a number
4. dotProduct : Inner product
5. crossProduct : Cross product (only 3D vectors)
6. magnitude : Length of a vector
7. normalize : Convert vector to unit vector

                    Error Handling

I used if statements and print errors with cout.
If an error happens, the function returns an empty matrix or vector.

I handled these errors:

Matrix:
- Addition & Subtraction when dimensions are not equal
- Multiplication when A cols ≠ B rows
- Determinant & Inverse when matrix is not square
- Inverse when determinant is zero
Vector:
- Addition/Subtraction/Dot product when sizes are not equal
- Cross product when vectors are not 3D
- Normalize when vector is zero
Also:
- If user enters size more than 5
- If user enters size zero or negative
- If user chooses wrong menu option

                    Project Limitations

1. Maximum size for matrices and vectors: 5
   - I did this to keep the program simple.

2. Determinant is calculated with recursive method

3. Cross product is only for 3D vectors
   - This is mathematics rule.

                    How to Run the Program?

1. Put these files in one folder:
   - matrix_library.h
   - matrix_library.cpp
   - demonstration.cpp

2. Compile:
   If you use g++:
   g++ -o project.exe matrix_library.cpp demonstration.cpp

3. Run:
   On Windows: project.exe
   On Linux or Mac: ./project.exe

4. In menu, choose 1 or 2:
   1 = Matrix Operations
   2 = Vector Operations

5. Enter dimensions and values.

6. See output in terminal.
   The file report_sample.html is created in same folder.

                       Sources

How to create a library in C++ :
https://www.geeksforgeeks.org/cpp/how-do-i-create-a-library-in-cpp/

Basic HTML & CSS :
https://m.youtube.com/watch?v=qz0aGYrrlhU&pp=ygUdaHRtbCBjc3MgYmFzaWNzIGZvciBiZWdpbm5lcnM%3D
https://m.youtube.com/watch?v=xv-bBxaa7WU&pp=ygURY3NzIGZvciBiZWdpbm5lcnM%3D

Determinant :
https://youtu.be/c0N0itfpjFU?si=ANd9BM4ALcm_vvbj

Inverse : 
https://youtu.be/P3l7gGeHXC8?si=lKFyvkfutymPJgK_

w3schools.com
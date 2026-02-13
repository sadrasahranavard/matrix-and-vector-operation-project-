#ifndef MATRIX_LIBRARY_H
#define MATRIX_LIBRARY_H

#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

// Matrix
vector<vector<double>> addMatrix(const vector<vector<double>>& A, const vector<vector<double>>& B);
vector<vector<double>> subtractMatrix(const vector<vector<double>>& A, const vector<vector<double>>& B);
vector<vector<double>> scalarMultiplyMatrix(const vector<vector<double>>& A, double scalar);
vector<vector<double>> multiplyMatrix(const vector<vector<double>>& A, const vector<vector<double>>& B);
vector<vector<double>> transposeMatrix(const vector<vector<double>>& A);
double determinant(const vector<vector<double>>& A);
vector<vector<double>> inverseMatrix(const vector<vector<double>>& A);

// Vector
vector<double> addVector(const vector<double>& A, const vector<double>& B);
vector<double> subtractVector(const vector<double>& A, const vector<double>& B);
vector<double> scalarMultiplyVector(const vector<double>& A, double scalar);
double dotProduct(const vector<double>& A, const vector<double>& B);
vector<double> crossProduct(const vector<double>& A, const vector<double>& B);
double magnitude(const vector<double>& A);
vector<double> normalize(const vector<double>& A);

#endif

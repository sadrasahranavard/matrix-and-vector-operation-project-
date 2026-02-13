#include "matrix_library.h"
#include <iostream>

using namespace std;

// Matrix

// addition
vector<vector<double>> addMatrix(const vector<vector<double>>& A, const vector<vector<double>>& B)
{
    int r = A.size();
    int c = A[0].size();

    if (r != B.size() || c != B[0].size())
    {
        cout << "Error: Dimensions do not match for addition." << endl;
        vector<vector<double>> empty;
        return empty;
    }

    vector<vector<double>> result(r, vector<double>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// subtraction
vector<vector<double>> subtractMatrix(const vector<vector<double>>& A, const vector<vector<double>>& B)
{
    int r = A.size();
    int c = A[0].size();

    if (r != B.size() || c != B[0].size())
    {
        cout << "Error: Dimensions do not match for subtraction." << endl;
        vector<vector<double>> empty;
        return empty;
    }

    vector<vector<double>> result(r, vector<double>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

// scalar
vector<vector<double>> scalarMultiplyMatrix(const vector<vector<double>>& A, double scalar)
{
    int r = A.size();
    int c = A[0].size();

    vector<vector<double>> result(r, vector<double>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            result[i][j] = A[i][j] * scalar;
        }
    }

    return result;
}

// multiplication
vector<vector<double>> multiplyMatrix(const vector<vector<double>>& A, const vector<vector<double>>& B)
{
    int r1 = A.size();
    int c1 = A[0].size();
    int r2 = B.size();
    int c2 = B[0].size();

    if (c1 != r2)
    {
        cout << "Error: Invalid dimensions for multiplication." << endl;
        vector<vector<double>> empty;
        return empty;
    }

    vector<vector<double>> result(r1, vector<double>(c2, 0));

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// transpose
vector<vector<double>> transposeMatrix(const vector<vector<double>>& A)
{
    int r = A.size();
    int c = A[0].size();

    vector<vector<double>> result(c, vector<double>(r));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            result[j][i] = A[i][j];
        }
    }

    return result;
}

// determinant recursive
double determinant(const vector<vector<double>>& A)
{
    int n = A.size();

    if (n != A[0].size())
    {
        cout << "Error: Matrix must be square for determinant." << endl;
        return 0;
    }

    if (n == 1)
        return A[0][0];

    if (n == 2)
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];

    double det = 0;

    for (int p = 0; p < n; p++)
    {
        vector<vector<double>> sub(n-1, vector<double>(n-1));

        for (int i = 1; i < n; i++)
        {
            int colIndex = 0;

            for (int j = 0; j < n; j++)
            {
                if (j == p) continue;

                sub[i-1][colIndex] = A[i][j];
                colIndex++;
            }
        }

        double sign;
        if (p % 2 == 0)
            sign = 1;
        else
            sign = -1;

        det += sign * A[0][p] * determinant(sub);
    }

    return det;
}

// inverse
vector<vector<double>> inverseMatrix(const vector<vector<double>>& A)
{
    int n = A.size();

    if (n != A[0].size())
    {
        cout << "Error: Matrix must be square for inverse." << endl;
        vector<vector<double>> empty;
        return empty;
    }

    double det = determinant(A);

    if (det == 0)
    {
        cout << "Error: Determinant is zero. No inverse exists." << endl;
        vector<vector<double>> empty;
        return empty;
    }

    vector<vector<double>> adj(n,vector<double>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vector<vector<double>> sub(n-1, vector<double>(n-1));
            int r = 0;

            for (int row = 0; row < n; row++)
            {
                if (row == i) continue;

                int c = 0;

                for (int col = 0; col < n; col++)
                {
                    if (col == j) continue;

                    sub[r][c] = A[row][col];
                    c++;
                }

                r++;
            }

            double sign;
            if ((i + j) % 2 == 0)
                sign = 1;
            else
                sign = -1;

            adj[j][i] = sign * determinant(sub);
        }
    }

    return scalarMultiplyMatrix(adj, 1.0/det);
}

// vector

// addition
vector<double> addVector(const vector<double>& A, const vector<double>& B)
{
    if (A.size() != B.size())
    {
        cout << "Error: Vector sizes must match for addition." << endl;
        vector<double> empty;
        return empty;
    }

    vector<double> result(A.size());

    for (int i = 0; i < A.size(); i++)
    {
        result[i] = A[i] + B[i];
    }

    return result;
}

// subtraction
vector<double> subtractVector(const vector<double>& A, const vector<double>& B)
{
    if (A.size() != B.size())
    {
        cout << "Error: Vector sizes must match for subtraction." << endl;
        vector<double> empty;
        return empty;
    }

    vector<double> result(A.size());

    for (int i = 0; i < A.size(); i++)
    {
        result[i] = A[i] - B[i];
    }

    return result;
}

// scalar
vector<double> scalarMultiplyVector(const vector<double>& A, double scalar)
{
    vector<double> result(A.size());

    for (int i = 0; i < A.size(); i++)
    {
        result[i] = A[i] * scalar;
    }

    return result;
}

// dot product
double dotProduct(const vector<double>& A, const vector<double>& B)
{
    if (A.size() != B.size())
    {
        cout << "Error: Vector sizes must match for dot product." << endl;
        return 0;
    }

    double sum = 0;

    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i] * B[i];
    }

    return sum;
}

// cross product
vector<double> crossProduct(const vector<double>& A, const vector<double>& B)
{
    if (A.size() != 3 || B.size() != 3)
    {
        cout << "Error: Cross product only for 3D vectors." << endl;
        vector<double> empty;
        return empty;
    }

    vector<double> result(3);

    result[0] = A[1] * B[2] - A[2] * B[1];
    result[1] = A[2] * B[0] - A[0] * B[2];
    result[2] = A[0] * B[1] - A[1] * B[0];

    return result;
}

// magnitude
double magnitude(const vector<double>& A)
{
    double sum = 0;

    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i] * A[i];
    }

    return sqrt(sum);
}

// normalization
vector<double> normalize(const vector<double>& A)
{
    double mag = magnitude(A);

    if (mag == 0)
    {
        cout << "Error: Cannot normalize zero vector." << endl;
        vector<double> empty;
        return empty;
    }

    vector<double> result(A.size());

    for (int i = 0; i < A.size(); i++)
    {
        result[i] = A[i] / mag;
    }

    return result;
}

#include <iostream>
#include <fstream>
#include <vector>
#include "matrix_library.h"

using namespace std;

// functions

void printMatrixConsole(const vector<vector<double>>& M)
{
    if (M.size() == 0) return;

    cout << "----------------------------------------" << endl;
    for (int i = 0; i < M.size(); i++)
    {
        for (int j = 0; j < M[0].size(); j++)
            cout << M[i][j] << "\t";
        cout << endl;
    }
    cout << "----------------------------------------" << endl;
}

void printMatrixHTML(const vector<vector<double>>& M, ofstream& html)
{
    if (M.size() == 0)
    {
        html << "<p class='error'>Operation failed</p>";
        return;
    }

    html << "<table>";
    for (int i = 0; i < M.size(); i++)
    {
        html << "<tr>";
        for (int j = 0; j < M[0].size(); j++)
            html << "<td style='text-align:center;'>" << M[i][j] << "</td>";
        html << "</tr>";
    }
    html << "</table>";
}

void printVectorConsole(const vector<double>& V)
{
    if (V.size() == 0) return;

    cout << "[ ";
    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";
    cout << "]" << endl;
}

void printVectorHTML(const vector<double>& V, ofstream& html)
{
    if (V.size() == 0)
    {
        html << "<p class='error'>Operation failed</p>";
        return;
    }

    html << "<p style='text-align:center;'>[";
    for (int i = 0; i < V.size(); i++)
    {
        html << V[i];
        if (i != V.size() - 1) html << ", ";
    }
    html << "]</p>";
}

// main
int main()
{
    // HTML file
    ofstream html("report_sample.html");

    html << "<!DOCTYPE html>";
    html << "<html>";
    html << "<head>";
    html << "<meta charset='UTF-8'>";
    html << "<title>Matrix and Vector Report</title>";
    html << "<style>";
    html << "body{font-family:arial;margin:30px;background:white;}";
    html << "h1{font-size:24px;font-weight:bold;}";
    html << "h2{font-size:20px;font-weight:bold;}";
    html << "section{margin-bottom:30px;}";
    html << "table{border-collapse:collapse;margin-top:10px;margin-left:auto;margin-right:auto;}";
    html << "td{border:1px solid black;padding:8px;text-align:center;}";
    html << ".error{color:red;font-weight:bold;text-align:center;}";
    html << "p{text-align:center;}";
    html << "</style>";
    html << "</head>";
    html << "<body>";

    html << "<h1 style='text-align:center;'>Matrix and Vector Operations Report</h1>";

    int choice;
    cout << "========================================" << endl;
    cout << "1. Matrix Operations" << endl;
    cout << "2. Vector Operations" << endl;
    cout << "========================================" << endl;
    cout << "Choose: ";
    cin >> choice;

    // check valid choice
    if (choice != 1 && choice != 2)
    {
        cout << "========================================" << endl;
        cout << "Error: Invalid choice." << endl;
        cout << "========================================" << endl;
        html << "<section><p class='error'>Error: Invalid choice.</p></section>";
        html << "</body></html>";
        html.close();
        return 1;
    }

    // matrix
    if (choice == 1)
    {
        int r1, c1, r2, c2;

        cout << "========================================" << endl;
        cout << "Matrix A rows and cols (max 5): ";
        cin >> r1 >> c1;
        cout << "Matrix B rows and cols (max 5): ";
        cin >> r2 >> c2;
        cout << "========================================" << endl;

        // check size limits
        if (r1 > 5 || c1 > 5 || r2 > 5 || c2 > 5)
        {
            cout << "========================================" << endl;
            cout << "Error: Maximum size is 5." << endl;
            cout << "========================================" << endl;
            html << "<section><p class='error'>Error: Maximum size is 5.</p></section>";
            html << "</body></html>";
            html.close();
            return 1;
        }

        if (r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0)
        {cout << "========================================" << endl;
            cout << "Error: Dimensions must be positive." << endl;
            cout << "========================================" << endl;
            html << "<section><p class='error'>Error: Dimensions must be positive.</p></section>";
            html << "</body></html>";
            html.close();
            return 1;
        }

        vector<vector<double>> A(r1, vector<double>(c1));
        vector<vector<double>> B(r2, vector<double>(c2));

        cout << "Enter Matrix A:" << endl;
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c1; j++)
                cin >> A[i][j];

        cout << "Enter Matrix B:" << endl;
        for (int i = 0; i < r2; i++)
            for (int j = 0; j < c2; j++)
                cin >> B[i][j];

        cout << "========================================" << endl;

        // input section
        html << "<section>";
        html << "<h2 style='text-align:center;'>Input Matrices</h2>";
        html << "<p>A (" << r1 << " * " << c1 << ")</p>";
        printMatrixHTML(A, html);
        html << "<p>B (" << r2 << " * " << c2 << ")</p>";
        printMatrixHTML(B, html);
        html << "</section>";

        // Addition
        html << "<section>";
        html << "<h2 style='text-align:center;'>A + B</h2>";
        if (r1 == r2 && c1 == c2)
        {
            vector<vector<double>> sum = addMatrix(A, B);
            cout << "A + B:" << endl;
            printMatrixConsole(sum);
            printMatrixHTML(sum, html);
        }
        else
        {
            cout << "Error: Addition requires equal dimensions." << endl;
            html << "<p class='error'>Error: Addition requires equal dimensions.</p>";
        }
        html << "</section>";

        // Subtraction
        html << "<section>";
        html << "<h2 style='text-align:center;'>A - B</h2>";
        if (r1 == r2 && c1 == c2)
        {
            vector<vector<double>> sub = subtractMatrix(A, B);
            cout << "A - B:" << endl;
            printMatrixConsole(sub);
            printMatrixHTML(sub, html);
        }
        else
        {
            cout << "Error: Subtraction requires equal dimensions." << endl;
            html << "<p class='error'>Error: Subtraction requires equal dimensions.</p>";
        }
        html << "</section>";

        // Multiplication
        html << "<section>";
        html << "<h2 style='text-align:center;'>A * B</h2>";
        if (c1 == r2)
        {
            vector<vector<double>> mul = multiplyMatrix(A, B);
            cout << "A * B:" << endl;
            printMatrixConsole(mul);
            printMatrixHTML(mul, html);
        }
        else
        {
            cout << "Error: Multiplication requires columns of A = rows of B." << endl;
            html << "<p class='error'>Error: Multiplication requires columns of A = rows of B.</p>";
        }
        html << "</section>";

        // Transpose
        html << "<section>";
        html << "<h2 style='text-align:center;'>Transpose of A</h2>";
        vector<vector<double>> trans = transposeMatrix(A);
        cout << "Transpose of A:" << endl;
        printMatrixConsole(trans);
        printMatrixHTML(trans, html);
        html << "</section>";

        // Scalar
        double scalar;
        cout << "Enter scalar for A: ";
        cin >> scalar;
        cout << "========================================" << endl;

        html << "<section>";
        html << "<h2 style='text-align:center;'>Scalar * A</h2>";
        vector<vector<double>> scaled = scalarMultiplyMatrix(A, scalar);
        cout << "Scalar * A:" << endl;
        printMatrixConsole(scaled);
        printMatrixHTML(scaled, html);
        html << "</section>";

        // Determinant
        html << "<section>";
        html << "<h2 style='text-align:center;'>Determinant</h2>";
        if (r1 == c1)
        {
            double det = determinant(A);
            cout << "Determinant:" << det << endl;
            cout << "========================================" << endl;
            html << "<p style='text-align:center;'>" << det << "</p>";
        }
        else
        {
            cout << "Error: Determinant requires square matrix." << endl;
            cout << "========================================" << endl;
            html << "<p class='error'>Error: Determinant requires square matrix.</p>";
        }
        html << "</section>";

        // Inverse
        html << "<section>";
        html << "<h2 style='text-align:center;'>Inverse</h2>";
        if (r1 == c1)
        {
            double det = determinant(A);
            if (det != 0)
            {
                vector<vector<double>> inv = inverseMatrix(A);
                cout << "Inverse:" << endl;
                printMatrixConsole(inv);
                printMatrixHTML(inv, html);
            }
            else
            {
                cout << "Error: Determinant is zero. No inverse." << endl;
                cout << "========================================" << endl;
                html << "<p class='error'>Error: Determinant is zero. No inverse.</p>";
            }
        }
        else
        {
            cout << "Error: Inverse requires square matrix." << endl;
            cout << "========================================" << endl;
            html << "<p class='error'>Error: Inverse requires square matrix.</p>";
        }
        html << "</section>";
    }

    // vector
    else if (choice == 2)
    {
        int n1, n2;

        cout << "========================================" << endl;
        cout << "Vector A size (max 5): ";
        cin >> n1;
        cout << "Vector B size (max 5): ";
        cin >> n2;
        cout << "========================================" << endl;

        // check size limits
        if (n1 > 5 || n2 > 5)
        {
            cout << "========================================" << endl;
            cout << "Error: Maximum size is 5." << endl;
            cout << "========================================" << endl;
            html << "<section><p class='error'>Error: Maximum size is 5.</p></section>";
            html << "</body></html>";
            html.close();
            return 1;
        }

        if (n1 <= 0 || n2 <= 0)
        {
            cout << "========================================" << endl;
            cout << "Error: Size must be positive." << endl;
            cout << "========================================" << endl;
            html << "<section><p class='error'>Error: Size must be positive.</p></section>";
            html << "</body></html>";
            html.close();
            return 1;
        }

        vector<double> A(n1);
        vector<double> B(n2);

        cout << "Enter Vector A:" << endl;
        for (int i = 0; i < n1; i++)
            cin >> A[i];

        cout << "Enter Vector B:" << endl;
        for (int i = 0; i < n2; i++)
            cin >> B[i];

        cout << "========================================" << endl;

        // input section
        html << "<section>";
        html << "<h2 style='text-align:center;'>Input Vectors</h2>";
        html << "<p>A (" << n1 << ")</p>";
        printVectorHTML(A, html);
        html << "<p>B (" << n2 << ")</p>";
        printVectorHTML(B, html);
        html << "</section>";

        // Addition
        html << "<section>";
        html << "<h2 style='text-align:center;'>A + B</h2>";
        if (n1 == n2)
        {
            vector<double> sum = addVector(A, B);
            cout << "A + B:" << endl;
            printVectorConsole(sum);
            printVectorHTML(sum, html);
        }
        else
        {
            cout << "Error: Addition requires equal sizes." << endl;
            html << "<p class='error'>Error: Addition requires equal sizes.</p>";
        }
        html << "</section>";

        // Subtraction
        html << "<section>";
        html << "<h2 style='text-align:center;'>A - B</h2>";if (n1 == n2)
        {
            vector<double> sub = subtractVector(A, B);
            cout << "A - B:" << endl;
            printVectorConsole(sub);
            printVectorHTML(sub, html);
        }
        else
        {
            cout << "Error: Subtraction requires equal sizes." << endl;
            html << "<p class='error'>Error: Subtraction requires equal sizes.</p>";
        }
        html << "</section>";

        // Dot product
        html << "<section>";
        html << "<h2 style='text-align:center;'>Dot Product</h2>";
        if (n1 == n2)
        {
            double dot = dotProduct(A, B);
            cout << "Dot Product: " << dot << endl;
            cout << "========================================" << endl;
            html << "<p style='text-align:center;'>" << dot << "</p>";
        }
        else
        {
            cout << "Error: Dot product requires equal sizes." << endl;
            cout << "========================================" << endl;
            html << "<p class='error'>Error: Dot product requires equal sizes.</p>";
        }
        html << "</section>";

        // Cross product
        html << "<section>";
        html << "<h2 style='text-align:center;'>Cross Product</h2>";
        if (n1 == 3 && n2 == 3)
        {
            vector<double> cross = crossProduct(A, B);
            cout << "Cross Product:" << endl;
            printVectorConsole(cross);
            printVectorHTML(cross, html);
        }
        else
        {
            cout << "Error: Cross product only for 3D vectors." << endl;
            cout << "========================================" << endl;
            html << "<p class='error'>Error: Cross product only for 3D vectors.</p>";
        }
        html << "</section>";

        // Scalar
        double scalar;
        cout << "Enter scalar for A: ";
        cin >> scalar;
        cout << "========================================" << endl;

        html << "<section>";
        html << "<h2 style='text-align:center;'>Scalar * A</h2>";
        vector<double> scaled = scalarMultiplyVector(A, scalar);
        cout << "Scalar * A:" << endl;
        printVectorConsole(scaled);
        printVectorHTML(scaled, html);
        html << "</section>";

        // Magnitude
        html << "<section>";
        html << "<h2 style='text-align:center;'>Magnitude</h2>";
        double mag = magnitude(A);
        cout << "Magnitude: " << mag << endl;
        cout << "========================================" << endl;
        html << "<p style='text-align:center;'>" << mag << "</p>";
        html << "</section>";

        // Normalize
        html << "<section>";
        html << "<h2 style='text-align:center;'>Normalized Vector</h2>";
        if (mag != 0)
        {
            vector<double> norm = normalize(A);
            cout << "Normalized Vector:" << endl;
            printVectorConsole(norm);
            printVectorHTML(norm, html);
        }
        else
        {
            cout << "Error: Cannot normalize zero vector." << endl;
            cout << "========================================" << endl;
            html << "<p class='error'>Error: Cannot normalize zero vector.</p>";
        }
        html << "</section>";
    }

    html << "</body></html>";
    html.close();

    cout << "HTML file generated: report_sample.html" << endl;
    cout << "========================================" << endl;

    return 0;
}

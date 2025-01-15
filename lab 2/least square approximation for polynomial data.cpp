#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;


// Function to solve the normal equations for polynomial least squares
void solveNormalEquations(const vector<vector<double>>& matrix, vector<double>& coefficients, int degree) {
    int n = degree + 1;
   vector<double> result(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[j][i] != 0) {
                double ratio = matrix[j][i] / matrix[i][i];
                for (int k = i; k <= n; k++) {
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        result[i] = matrix[i][n] / matrix[i][i];
        for (int j = 0; j < i; j++) {
            matrix[j][n] -= matrix[j][i] * result[i];
        }
    }

    coefficients = result;
}

// Function to calculate least squares approximation for polynomial data
void leastSquaresPolynomial(const vector<double>& x, const vector<double>& y, vector<double>& coefficients, int degree) {
    int n = x.size();
    int m = degree + 1;

    vector<vector<double>> matrix(m, vector<double>(m + 1, 0));

    // Construct the normal equations
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                matrix[i][j] += std::pow(x[k], i + j);
            }
        }
        for (int k = 0; k < n; k++) {
            matrix[i][m] += pow(x[k], i) * y[k];
        }
    }

    // Solve the system of linear equations
    solveNormalEquations(matrix, coefficients, degree);
}

int main() {
    int n, degree;

    // Input the number of data points
    cout << "Enter the number of data points: ";
   cin >> n;

    vector<double> x(n), y(n);

    // Input data points
   cout << "Enter the data points (x and y) separated by space:\n";
    for (int i = 0; i < n; i++) {
       cin >> x[i] >> y[i];
    }

    // Input the degree of the polynomial
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    vector<double> coefficients;

    // Perform least squares approximation for polynomial data
    leastSquaresPolynomial(x, y, coefficients, degree);

    // Display the result
    cout << fixed << setprecision(4);
    cout << "The polynomial approximation is: y = ";
    for (int i = 0; i <= degree; i++) {
        if (i > 0) {
            cout << " + ";
        }
       cout << coefficients[i] << "x^" << i;
    }
    cout << endl;

    return 0;
}


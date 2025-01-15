#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// Function to calculate the coefficients of least squares approximation for non-linear data
void leastSquaresNonLinear(const vector<double>& x, const vector<double>& y, double& a, double& b) {
    int n = x.size();

    double sumX = 0, sumLogY = 0, sumXLogY = 0, sumX2 = 0;

    // Compute the summations, taking the natural log of y
    for (int i = 0; i < n; i++) {
        double logY = log(y[i]);
        sumX += x[i];
        sumLogY += logY;
        sumXLogY += x[i] * logY;
        sumX2 += x[i] * x[i];
    }

    // Calculate coefficients a and b for ln(y) = ln(a) + b * x
    b = (n * sumXLogY - sumX * sumLogY) / (n * sumX2 - sumX * sumX);
    double lnA = (sumLogY - b * sumX) / n;
    a = exp(lnA); // Convert back from ln(a) to a
}

int main() {
    int n;

    // Input the number of data points
    cout << "Enter the number of data points: ";
    cin >> n;

   vector<double> x(n), y(n);

    // Input data points
    cout << "Enter the data points (x and y) separated by space:\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    double a, b;

    // Perform least squares approximation for non-linear data
    leastSquaresNonLinear(x, y, a, b);

    // Display the result
   cout << fixed << setprecision(4);
    cout << "The exponential approximation is: y = " << a << " * e^(" << b << "x)" << endl;

    return 0;
}


//implement least square approximation for linear data.

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Function to calculate the coefficients of the least squares approximation
void leastSquaresLinear(const vector<double>& x, const vector<double>& y, double& a, double& b) {
    int n = x.size();

    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    // Compute the summations
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    // Calculate coefficients a and b
    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = (sumY - b * sumX) / n;
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

    // Perform least squares approximation
    leastSquaresLinear(x, y, a, b);

    // Display the result
   cout << fixed << setprecision(4);
   cout << "The linear approximation is: y = " << a << " + " << b << "x" << endl;

    return 0;
}


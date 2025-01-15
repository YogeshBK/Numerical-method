#include <iostream>
#include <vector>
using namespace std;

// Function to calculate Central Differences
void CDTable(double x[], double y[], int n) {
    
    for (int i = 1; i < n - 1; i++) {
        y[i] = (y[i + 1] - y[i - 1]) / (x[i + 1] - x[i - 1]);
    }
}

// Function for Centered Difference Interpolation
double CDI(double x[], double y[], int n, double xValue) {
   
    int i = 0;
    while (i < n - 1 && x[i + 1] < xValue) {
        i++;
    }
    
    // Use central difference interpolation formula
    double result = y[i];
    double h = x[i + 1] - x[i];
    double s = (xValue - x[i]) / h;

  
    double fact = 1;
    for (int j = 1; j < n - 1; j++) {
        fact *= (s - j);
        result += fact * y[j];
    }

    return result;
}

int main() {
    int n;
    
    cout << "Enter the size of the data: ";
    cin >> n;
    
    double x[n], y[n];
    
    cout << "Enter the x values:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }
    
    cout << "Enter the y values:\n";
    for (int i = 0; i < n; i++) {
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }
    
    
    CDTable(x, y, n);
    
    double xValue;
    cout << "Enter the value of x to interpolate: ";
    cin >> xValue;
    
    double result = CDI(x, y, n, xValue);
    
    cout << "The interpolated value at x = " << xValue << " is: " << result << endl;
    
    return 0;
}


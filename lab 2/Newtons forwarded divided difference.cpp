#include <iostream>
using namespace std;


void FDDT(double x[], double y[], int n) {

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            y[i] = (y[i] - y[i - 1]) / (x[i] - x[i - j]);
        }
    }
}


double NFI(double x[], double y[], int n, double xValue) {
    double result = y[0]; 
    double h = x[1] - x[0];
    double s = (xValue - x[0]) / h; 

    
    double fact = 1; 
    for (int i = 1; i < n; i++) {
        fact *= (s - (i - 1));
        result += fact * y[i];
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

    
    cout << "Enter the y vlaues:\n";
    for (int i = 0; i < n; i++) {
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }

   
    FDDT(x, y, n);

  
    double xValue;
    cout << "Enter the value of x to interpolate: ";
    cin >> xValue;

  
    double result = NFI(x, y, n, xValue);

    cout << "The interpolated value at x = " << xValue << " is: " << result << endl;

    return 0;
}



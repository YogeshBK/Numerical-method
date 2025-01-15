#include <iostream>
using namespace std;


double lagrange(double x[], double y[], int n, double xValue) {
    double result = 0;

    
    for (int i = 0; i < n; i++) {
        double term = y[i];

        
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (xValue - x[j]) / (x[i] - x[j]);
            }
        }

      
        result += term;
    }

    return result;
}

int main() {
    int n;

    
    cout << "Enter the size of the data: ";
    cin >> n;

   
    double x[n], y[n];

   
    cout << "Enter the x values:"<<endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }

    cout << "Enter the y values:"<<endl;
    for (int i = 0; i < n; i++) {
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }

  
    double xValue;
    cout << "Enter the value of x to interpolate: ";
    cin >> xValue;

    
    double result = lagrange(x, y, n, xValue);

    cout << "The interpolated value at x = " << xValue << " is: " << result << endl;

    return 0;
}

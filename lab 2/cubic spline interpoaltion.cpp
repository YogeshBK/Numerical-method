#include <iostream>
#include <vector>

using namespace std;

void CSI(const vector<double>& x, const vector<double>& y, int n, vector<double>& S) {
   
    vector<double> h(n - 1), alpha(n - 1), l(n), mu(n - 1), z(n);

    for (int i = 0; i < n - 1; i++) {
        h[i] = x[i + 1] - x[i];
    }

   
    for (int i = 1; i < n - 1; i++) {
        alpha[i] = (3.0 / h[i]) * (y[i + 1] - y[i]) - (3.0 / h[i - 1]) * (y[i] - y[i - 1]);
    }

    l[0] = 1.0;
    mu[0] = 0.0;
    z[0] = 0.0;

    for (int i = 1; i < n - 1; i++) {
        l[i] = 2.0 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }

    l[n - 1] = 1.0;
    z[n - 1] = 0.0;
    S[n - 1] = 0.0;


    for (int j = n - 2; j >= 0; j--) {
        S[j] = z[j] - mu[j] * S[j + 1];
    }
}


double interpolate(double xValue, const vector<double>& x, const vector<double>& y, int n, const vector<double>& S) {
    
    int i = n - 2;
    while (xValue < x[i] && i >= 0) {
        i--;
    }

 
    double dx = xValue - x[i];
    double result = y[i] + S[i] * dx;
    return result;
}

int main() {
    int n;

    cout << "Enter the number of data points: ";
    cin >> n;

    
    vector<double> x(n), y(n);

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

    vector<double> S(n); 
    CSI(x, y, n, S);

    
    double xValue;
    cout << "Enter the value of x to interpolate: ";
    cin >> xValue;

    double result = interpolate(xValue, x, y, n, S);

    
    cout << "The interpolated value at x = " << xValue << " is: " << result << endl;

    return 0;
}






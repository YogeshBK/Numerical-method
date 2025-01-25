#include<iostream>
#include<cmath>
using namespace std;

// Function to calculate the determinant of a 3x3 matrix
double determinant(double a1, double b1, double c1, double a2, double b2, double c2, double a3, double b3, double c3) {
    return a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
}

int main() {
    int arrx[10], arry[10], i, n;
    float sumx = 0, sumy = 0, sum_sqrx = 0, sum_cubex = 0, sum_x4 = 0, sumxy = 0, sum_sqrx_y = 0;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input the x and y values
    for (i = 0; i < n; i++) {
        cout << "arrx[" << i << "]: ";
        cin >> arrx[i];
        cout << "arry[" << i << "]: ";
        cin >> arry[i];
    }

   
    for (i = 0; i < n; i++) {
       
        sumx += arrx[i];
        sumy += arry[i];
        sum_sqrx += pow(arrx[i], 2);
        sum_cubex += pow(arrx[i], 3);
        sum_x4 += pow(arrx[i], 4);
        sumxy += arrx[i] * arry[i];
        sum_sqrx_y += pow(arrx[i], 2) * arry[i];
    }

    // Output the sums
    
    // Set up the coefficients of the system of equations
    double a1 = n, b1 = sumx, c1 = sum_sqrx, d1 = sumy;
    double a2 = sumx, b2 = sum_sqrx, c2 = sum_cubex, d2 = sumxy;
    double a3 = sum_sqrx, b3 = sum_cubex, c3 = sum_x4, d3 = sum_sqrx_y;

    // Calculate the determinants using Cramer's rule
    double delta = determinant(a1, b1, c1, a2, b2, c2, a3, b3, c3);
    double deltaX = determinant(d1, b1, c1, d2, b2, c2, d3, b3, c3);
    double deltaY = determinant(a1, d1, c1, a2, d2, c2, a3, d3, c3);
    double deltaZ = determinant(a1, b1, d1, a2, b2, d2, a3, b3, d3);

    // Check if the determinant is 0 (if so, no unique solution exists)
    if (abs(delta) < 1e-9) {
        cout << "No unique solution exists." << endl;
    } else {
        // Solve for x, y, and z using Cramer's Rule
        double x = deltaX / delta;
        double y = deltaY / delta;
        double z = deltaZ / delta;

        // Output the coefficients of the fitted polynomial
        cout << "The quadratic regression equation is: y = " << x << " + " << y << "x + " << z << "x^2" << endl;
    }

    return 0;
}


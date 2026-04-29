#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    float x[n], y[n][n];

    cout << "Enter x values:\n";
    for(int i = 0; i < n; i++)
        cin >> x[i];

    cout << "Enter y values:\n";
    for(int i = 0; i < n; i++)
        cin >> y[i][0];

    // Backward difference table
    for(int j = 1; j < n; j++) {
        for(int i = n-1; i >= j; i--) {
            y[i][j] = y[i][j-1] - y[i-1][j-1];
        }
    }

    float value;
    cout << "Enter value to interpolate: ";
    cin >> value;

    float h = x[1] - x[0];
    float u = (value - x[n-1]) / h;

    float result = y[n-1][0];
    float u_term = 1;
    int fact = 1;

    for(int i = 1; i < n; i++) {
        u_term = u_term * (u + (i - 1));
        fact = fact * i;
        result = result + (u_term * y[n-1][i]) / fact;
    }

    cout << "\nInterpolated value = " << result << endl;

    return 0;
}
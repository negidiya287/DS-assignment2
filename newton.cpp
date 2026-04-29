#include <iostream>
#include <cmath>
using namespace std;

// Function: f(x) = x^3 - x - 2
double f(double x) {
    return x*x*x - x - 2;
}

// Derivative: f'(x) = 3x^2 - 1
double df(double x) {
    return 3*x*x - 1;
}

int main() {
    double x0, x1;
    int i = 0;

    cout << "Enter initial guess: ";
    cin >> x0;

    do {
        x1 = x0 - f(x0) / df(x0);

        cout << "Iteration " << i << ": x = " << x1 << endl;

        if (fabs(x1 - x0) < 0.0001)
            break;

        x0 = x1;
        i++;

    } while (true);

    cout << "\nRoot is: " << x1;

    return 0;
}
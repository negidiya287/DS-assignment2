#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float x = 0, y = 0, z = 0; // initial guess
    float x1, y1, z1;
    int i = 0;

    cout << "Iterations:\n";

    do {
        // Gauss-Seidel formulas
        x1 = (12 - y - z) / 10;
        y1 = (13 - 2*x1 - z) / 10;
        z1 = (14 - 2*x1 - 2*y1) / 10;

        cout << "Iteration " << i << ": ";
        cout << "x=" << x1 << " y=" << y1 << " z=" << z1 << endl;

        if (fabs(x1 - x) < 0.001 &&
            fabs(y1 - y) < 0.001 &&
            fabs(z1 - z) < 0.001)
            break;

        x = x1;
        y = y1;
        z = z1;

        i++;

    } while (true);

    cout << "\nSolution:\n";
    cout << "x = " << x1 << "\n";
    cout << "y = " << y1 << "\n";
    cout << "z = " << z1 << "\n";

    return 0;
}
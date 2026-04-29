#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of variables: ";
    cin >> n;

    float a[n][n+1]; // augmented matrix

    cout << "Enter coefficients of augmented matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // Forward Elimination
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            float ratio = a[j][i] / a[i][i];
            for(int k = 0; k <= n; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    // Back Substitution
    float x[n];

    for(int i = n-1; i >= 0; i--) {
        x[i] = a[i][n];
        for(int j = i+1; j < n; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    // Output
    cout << "\nSolution:\n";
    for(int i = 0; i < n; i++) {
        cout << "x" << i+1 << " = " << x[i] << endl;
    }

    return 0;
}
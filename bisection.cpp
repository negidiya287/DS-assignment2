# include <iostream>
using namespace std;

// Function to find root using bisection method
double bisection(double a, double b, double epsilon) {
    while ((b - a) >= epsilon) {
        double mid = (a + b) / 2.0;
        
        // Replace with your function f(x)
        if (f(mid) == 0.0)
            return mid;
        
        if (f(a) * f(mid) < 0)
            b = mid;
        else
            a = mid;
    }
    return (a + b) / 2.0;
}

// Example function: replace with your own
double f(double x) {
    return x * x - 4;  // finds root of x^2 - 4
}

int main() {
    double root = bisection(0, 3, 0.0001);
    cout << "Root found: " << root << endl;
    return 0;
}
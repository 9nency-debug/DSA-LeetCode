#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    cout << "Sum: " << a + b << endl;
    cout << "Difference: " << a - b << endl;
    cout << "Product: " << a * b << endl;

    if (b != 0) {
        cout << "Division: " << a / b << endl;
    } else {
        cout << "Division: Undefined (Division by zero)" << endl;
    }

    cout << "Average: " << (a + b) / 2.0 << endl;

    cout << "Absolute Values: " << abs(a) << " " << abs(b) << endl;

    cout << "Minimum: " << min(a, b) << endl;
    cout << "Maximum: " << max(a, b) << endl;

    cout << "Power (a^b): " << pow(a, b) << endl;

    if (a >= 0) cout << "Square Root of a: " << sqrt(a) << endl;
    else cout << "Square Root of a: Invalid for negative numbers\n";

    if (b >= 0) cout << "Square Root of b: " << sqrt(b) << endl;
    else cout << "Square Root of b: Invalid for negative numbers\n";

    cout << "Absolute Difference: " << abs(a - b) << endl;

    if (a * b >= 0)
        cout << "Geometric Mean: " << sqrt(a * b) << endl;
    else
        cout << "Geometric Mean: Undefined for negative product\n";

    cout << "Harmonic Mean: " << (2.0 * a * b) / (a + b) << endl;

    cout << "Median: " << (a + b) / 2.0 << endl;
    cout << "Mean: " << (a + b) / 2.0 << endl;
    cout << "Mode: N/A" << endl;

    cout << "Range: " << abs(a - b) << endl;
    cout << "Variance: N/A" << endl;
    cout << "Standard Deviation: N/A" << endl;

    cout << "Factorial of a: " << (a >= 0 ? tgamma(a + 1) : 0) << endl;
    cout << "Factorial of b: " << (b >= 0 ? tgamma(b + 1) : 0) << endl;

    cout << "GCD: " << std::gcd(a, b) << endl;
    cout << "LCM: " << (a * b) / std::gcd(a, b) << endl;

    if (a > 0) cout << "Logarithm base 10 of a: " << log10(a) << endl;
    else cout << "Logarithm base 10 of a: Undefined for non-positive numbers\n";

    if (b > 0) cout << "Logarithm base 10 of b: " << log10(b) << endl;
    else cout << "Logarithm base 10 of b: Undefined for non-positive numbers\n";

    if (a > 0) cout << "Natural Logarithm of a: " << log(a) << endl;
    else cout << "Natural Logarithm of a: Undefined for non-positive numbers\n";

    if (b > 0) cout << "Natural Logarithm of b: " << log(b) << endl;
    else cout << "Natural Logarithm of b: Undefined for non-positive numbers\n";

    cout << "Exponential of a: " << exp(a) << endl;
    cout << "Exponential of b: " << exp(b) << endl;

    cout << "Sine(a): " << sin(a) << endl;
    cout << "Sine(b): " << sin(b) << endl;

    cout << "Cosine(a): " << cos(a) << endl;
    cout << "Cosine(b): " << cos(b) << endl;

    cout << "Tangent(a): " << tan(a) << endl;
    cout << "Tangent(b): " << tan(b) << endl;

    return 0;
}
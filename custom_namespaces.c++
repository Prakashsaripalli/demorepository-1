#include <iostream>
using namespace std;
// Custom namespace
namespace Math {
    int add(int a, int b) {
        return a + b;
    }
}
namespace Physics {
    double add(double a, double b) {
        return a + b;
    }
}
int main() {
    cout << "Sum using Math namespace: " << Math::add(5, 10) << endl;
    cout << "Sum using Physics namespace: " << Physics::add(12.5, 7.5) << endl;
    return 0;
}

#include <iostream>
using namespace std;
void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside function (after swap): a = " << a << ", b = " << b << endl;
}

int main() {
    int x = 10, y = 20;
    cout << "Before function call: x = " << x << ", y = " << y << endl;
    // Call by reference
    swapNumbers(x, y);
    cout << "After function call: x = " << x << ", y = " << y << endl;
    return 0;
}

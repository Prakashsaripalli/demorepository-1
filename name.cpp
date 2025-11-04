#include <iostream>
using namespace std;
int x = 100;  // Global variable
namespace math{
	int x=10;
}
int main() {
    int x = 50;   // Local variable
    cout << "Local variable x = " << x << endl;
    cout << "Global variable x = " << ::x << endl; // using scope resolution
    cout<<"custom namespace x= "<<math::x<<endl;
    return 0;
}

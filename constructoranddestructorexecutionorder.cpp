#include<iostream>
using namespace std;
class Base{
	public:
		Base()
		{
			cout << "Base class constructor is called" << endl;
		}
		~Base()
		{
			cout << "Base class destructor is called" << endl;
		}
};
class Derive:public Base{
	public:
		Derive()
		{
			cout << "Derived class constructor is called" << endl;
		}
		~Derive()
		{
			cout << "Derived class destructor is called" << endl;
		}
};
int main()
{
	{
		Derive obj;
	}
	return 0;
}

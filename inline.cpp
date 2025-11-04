#include<iostream>
int num=10;
namespace MyMath{
	int num=20;
	
	void display()
	{
		std::cout<<"Inside namespace MyMath,num="<<num<<std::endl;
	}
} 

int main()
{
	int num=30;
	std::cout<<"Local num="<<num<<std::endl;
	std::cout<<"Gobal num="<<::num<<std::endl;
	std::cout<<"Namespace num="<<MyMath::num<<std::endl;
	MyMath::display();
	return 0;
}
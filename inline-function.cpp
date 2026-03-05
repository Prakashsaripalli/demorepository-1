#include<iostream>
#include<cmath>
inline int square(int x)
{
	return x*x;
}
inline int cube(int x)
{
	return x*x*x;
}
inline double po(int x,int n)
{
	
	return pow(x,n);
}

int main()
{
	int n;
	std::cout<<"Enter the Number:";
	std::cin>>n;
	int num;
	std::cout<<"Enter the Number:";
	std::cin>>num;
	std::cout<<"square of "<<num<<" is :"<<square(num)<<std::endl;
	std::cout<<"cube of "<<num<<" is :"<<cube(num)<<std::endl;
	
	std::cout<<"power of "<<num<<" is :"<<po(num,n)<<std::endl;
	return 0;
}

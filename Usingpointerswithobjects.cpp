#include<iostream>
using namespace std;
class Student{
	public:
		int id;
		float marks;
	void display(){
		cout << "ID:" << id <<",Marks:"<<marks<<endl;
	}
};
int main()
{
	Student s1;
	s1.id=101;
	s1.marks=95.5;
	Student* ptr=&s1;
	ptr->id=102;
	ptr->marks=98.5;
	ptr->display();
	return 0;
}

#include<iostream>
using namespace std;
class Student{
	public:
		string name;
		string roll;
		Student()
		{
			name="Unknown";
			roll="24Unknown";
		}
		Student(string n,string r)
		{
			name=n;
			roll=r;
		}
	void display()
	{
		cout<<"Roll No:"<<roll<<",Name:"<<name<<endl;
	}
};
int main()
{
	Student s1;
	s1.display();
	Student s2[3];
	for(int i=0;i<3;i++)
	{
		cout<<"Enter the details of the student: "<<endl;
		cin >> s2[i].name;
		cin >> s2[i].roll;
	}
	for(int i=0;i<3;i++)
	{
		s2[i].display();
	}
}

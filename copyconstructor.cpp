#include<iostream>
using namespace std;
class Student{
	private:
		int rollno;
		
	public:
		Student(int r)
		{
			rollno = r;
		}
		
		Student(const Student &s){
			rollno = s.rollno;
		}
		
		void display()
		{
			cout<<"Roll No:"<<rollno<<endl;
		}
};
int main()
{
	Student s1(121);
	Student s2=s1;
	s1.display();
	s2.display();
}

#include<stdio.h>
struct student{
	char name[100];
	int rollno;
	char gender;
	
}s1,s2;
int main()
{
	struct student s1={"sai",143,'m'},s2;
	s2=s1;
	printf("The student Details are:\n");
	printf("Name:%s\nRollno=%d\nGender=%c",s2.name,s2.rollno,s2.gender);
	return 0;
}
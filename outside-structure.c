#include<stdio.h>
struct student {
	char name[50];
	int roll;
	float marks;
};
int main()
{
	struct student s1;
	
	printf("Enter name of a student :");
	scanf("%s",s1.name);
	printf("Enter the roll number :");
	scanf("%d",&s1.roll);
	printf("Enter marks :");
	scanf("%f",&s1.marks);
	
	printf("\n student Details\n");
	printf("Name of the student :%s\n",s1.name);
	printf("Roll Number :%d\n",s1.roll);
	printf("Marks :%.2f",s1.marks);
	return 0;
}
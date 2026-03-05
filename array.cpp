#include<stdio.h>
int main ()
{
	char size;
	printf("Enter the size : ");
	scanf("%c",&size);
	char arr[size];
	int i;
	for (i=0;i<size;i++)
	{
		scanf("%c",&arr[i]);
	}
	for (i=0;i<size;i++)
	{
		printf("%c",arr[i]);
	}
}

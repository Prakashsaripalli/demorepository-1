#include<stdio.h>
int main()
{
	int n;
	printf("Enter the size of arry: ");
	scanf("%d",&n);
	int arr[n];
	int i=0;
	for (i=0;i<n;i=i+1)
	{
		printf("Enter the %d element:\n",i+1);
		scanf("%d",&arr[i]);
	}
}

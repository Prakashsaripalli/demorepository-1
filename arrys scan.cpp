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
		scanf("%d",&arr[i]);
	}
	for (i=n;i>=0;i=i-1)
	{
		printf("%d",&arr[i]);
	}
	return 0;
}

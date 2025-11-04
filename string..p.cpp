#include<stdio.h>
int fun(int *ptr,int size)
{
	int sum=0,i;
	for(i=0;i<n;i++)
	{
		sum=sum+ *(ptr+i);
	}
	return sum;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("%d",fun(arr[0],i));
	return 0;
}

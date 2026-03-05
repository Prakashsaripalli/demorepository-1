#include<stdio.h>
int main()
{
	int i,n,count=0;
	scanf("%d",&n);
	for (i=1;i<=n;i=i+1)
	{
			if (n%i==0)
		{
			printf("  %d\n",i);
			count=count+1;
		}
	}
	if (count==2)
	{
		printf("it is prime");
	}
	else
	{
		printf("it is not prime");
	}
}

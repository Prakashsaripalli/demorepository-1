#include<stdio.h>
int main()
{
	int n,i=n,c=0,k;
	scanf("%d",&n);
	while (i>=1)
	{
		k=i%10;
		c=c+k;
		n=n/10;
		printf("%d",c);
	}
}

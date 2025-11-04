#include<stdio.h>
int main()
{
	int n=1,b=0,c=1,r;
	scanf("%d",&n);
	while (n>0)
	{
		r=n%2;
		b=b+r*c;
		n=n/2;
		c=c*10;
		
	}
	printf("%d",b);
	
}
	


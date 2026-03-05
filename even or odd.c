/*#include<stdio.h>
int main()
{
	int n,e=0,o=0,c=0;
	scanf("%d",&n);
	int i=n;
	while(i>=1)
	{
		c=c+1;
		int k=i%10;
	
	

		if (k%2==0)
		{
			e=e+1;
		}
		else
		{
			o=o+1;
		}
		i=i/10;
	}
	printf("no of count:%d\n",c);
	printf("no of odd's: %d\n",o);
	printf("no of even's: %d\n",e);
}*/
#include<stdio.h>
int main()
{
	int n,o=0,l=0,c=o;
	printf("enter the digit:");
	scanf("%d",&n);
	int i=n;
	while(i>=1)
	{
		c=c+1;
		int k=i%10;
		printf("%d\n",k);
		if (k%3==0)
		{
		   l=l+1;
		}
		else
		{
			o=o+1;
		}
		i=i/10;
	}

	printf("count the digits:%d\n",c);
	printf("no of digits divisible by 3: %d\n",l);
	printf("no of digits not divisible by 3: %d\n",o);
	
}
	

#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int c=0;
		int i,j;
		for(i=0;i<n/2;i++)
		{
			for(j=n/2;j<n;j++)
			{
				if((i+j-3)%4==0)
				{
					c++;
				}
			}
		}
		if(c%2==0)
		{
			printf("Bob\n");
		}
		else
		{
			printf("Alice\n");
		}
		
	}
}

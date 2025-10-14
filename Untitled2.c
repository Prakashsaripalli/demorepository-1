#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int k;
		scanf("%d",&k);
		int a[n],i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int c=0;
		int j=0;
		while(j<n)
		{
			if((j+1)%k==0)
			{
				if(a[j+1]==0)
				{
					c++;
				}
				j=j+k+1;
			}
			else
			{
				c=0;
				j=j+1;
			}
		}
		printf("%d\n",c);
	}
}

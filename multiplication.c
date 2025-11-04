#include<stdio.h>
int main()
{
	int n,i,s,b;
	scanf("%d%d%d",&n,&b,&s);
	for (i=b;i<=s;i=i+1)
	{
		printf("%dx%d=%d\n",n,i,n*i);
		
	}
}
/*#include<stdio.h>
int main()
{
	int n,i,b,k;
	scanf("%d%d%d",&n,&b,&k);
	i=b;
	while (i<=k)
	{
		printf("%d x %d = %d \n i",n,i,n*i);
		i++;
		
	}
	
}*/


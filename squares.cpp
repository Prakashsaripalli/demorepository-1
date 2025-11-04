#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int n,i,k,p,r;
	int sum=0;
	int sum2=0;
	scanf("%d",&n);
	k=(n*(n+1)*((2*n)+1))/6;
	
	for(i=1;i<=n;i++)
	{
		sum2=sum2+i;
		
	}
	p=pow(sum2,2);
	r=abs(k-p);
	printf("%d\n",k);
	printf("%d\n",p);
	printf("%d",r);
	
}

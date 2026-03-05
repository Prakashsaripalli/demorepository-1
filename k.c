#include<stdio.h>
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	int k=x-y;
	if (x>=y)
	{
		printf("%d",k);
	}
	else
	{
		printf("0");
	}
}

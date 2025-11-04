#include<stdio.h>
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	for(x%y==0;y<=x;y=y+1)
	{
		printf("\n%d",y);
	}
}

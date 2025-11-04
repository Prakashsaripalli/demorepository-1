#include<stdio.h>
	int add(int *a,int *b)
{
	int c=*a + *b;
     return c;
}
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d",add(&x,&y));
}



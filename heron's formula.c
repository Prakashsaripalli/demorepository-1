#include<stdio.h>
#include<math.h>
int main ()
{
	int a,b,c;
	int s;
	scanf("%d%d%d",&a,&b,&c);
	s=(a+b+c)/2.0;
	float result=sqrt(s*(s-a)*(s-b)*(s-c));
	printf ("%d",result);
	return 0;
}

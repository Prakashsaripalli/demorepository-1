#include<stdio.h>
int main()
{
	int a,b,c=0,cnt=0;
	scanf("%d%d",&a,&b);

	if(a > b)
	{
		c=1;
	}
	else
	{
		c=2;
	}
  if(c==1)
  {
  	while(a>0)
  	{
  		cnt++;
  		a/=10;
	  }
  }
  else
  {
  	while(b>0)
  	{
  		cnt++;
  		b/=10;
	  }
  }
  printf("%d",cnt);
  printf("%d",k);
	

	
	
}

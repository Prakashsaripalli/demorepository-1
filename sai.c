#include<stdio.h.>
#include<math.h>
int main()
{
	int x,y;
	printf("x :"),
	scanf("%d",&x);
	printf("y :"),
	scanf("%d",&y);
	double loss_percentage=(doubleS)((x-y)*100)/x;
	printf("loss percentage : %.2f%%\n",loss_percentage);
	return 0;
}

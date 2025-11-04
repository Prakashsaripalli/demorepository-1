#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *arr = (int*)calloc(4,sizeof(int));
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr = (int*)realloc(arr,6*sizeof(int));
	arr[4]=120;
	arr[5]=100;
	int i;
	for(i=0;i<6;i++)
	{
		printf("%d ",arr[i]);
	}
}

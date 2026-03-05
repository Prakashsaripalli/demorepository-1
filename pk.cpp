#include<stdio.h>
int main()
{
 int n,i,x=0;
 printf("enter the arr size : ");
 scanf("%d",&n);
 int arr[n];
 for(i=0;i<n;i++)
 {
 	scanf("%d",&arr[i]);
 }
 for(i=0;i<n;i++)
 {
 	if(x<arr[i])
 	{
 		x=arr[i];
	}
	 
 }
 	printf("%d",x);
}

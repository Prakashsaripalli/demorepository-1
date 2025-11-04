#include<stdio.h>
void merge(int arr[],int low,int mid,int high)
{
	int b[100];
	int i=low,j=mid+1,k=0;
	while(i<=mid && j<=high)
	{
		if (arr[i]<arr[j])	
		{
			b[k++]=arr[i++];
			
		}
		else{
			b[k++]=arr[j++];
		}
		
	}
}
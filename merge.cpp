#include<stdio.h>
void mergesort(int arr[],int low,int high,int mid)
{
	int b[10];
	 int i = low, j = mid + 1, k = 0;
	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
			b[k++]=arr[i++];
			
		}
		else{
			b[k++]=arr[j++];
		}
	}


	while (i <= mid){
	
	b[k++]=arr[i++];
     }
  while (j <= high)
  {
  	b[k++] = arr[j++];
  }
    
for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = b[k];

}

 
 void merge(int arr[],int low, int high)
 {
 	if(low<high){
 		int mid=(low+high)/2;
 		merge(arr,low,mid);
 		merge(arr,mid+1,high);
 		mergesort(arr,low,mid,high);
 		
	 }
 }

int main()
{
	int n,i,a[215];
	printf("enter the number:");
	scanf("%d",&n);
	printf("enter the elements:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	printf("sorted array:");
	for(i=0;i<n;i++)
	scanf("%d\t",&a[i]);
}

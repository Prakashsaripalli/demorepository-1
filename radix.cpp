#include<stdio.h>
#include<math.h>
void Bucket(int arr[],int size,int count){
	int i,j;
	int brr[10][size];
	int div=1;
	while(count>0){
		int crr[10]={0};
		for(i=0;i<size;i++){
			int last=(arr[i]/div)%10;
			brr[last][crr[last]]=arr[i];
			crr[last]++;
		}
		int arr_element=0;
		for(i=0;i<10;i++){
			for(j=0;j<crr[i];j++){
				arr[arr_element]= brr[i][j];
				arr_element++;
			}	
		}
		div*=10;
		count--;
	}
}
int main()
{
	int n;
	printf("Enter the size:");
	scanf("%d",&n);
	int arr[n],i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int max=arr[0];
	//maximum number in an array...
	for(i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	// number of digits in a array
	int count= log10(max)+1;
	//printf("--%d--\n",count);
	printf("Before Sorting\n");
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
	Bucket(arr,n,count);
	printf("After Sorting\n");
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
}
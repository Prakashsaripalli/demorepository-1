#include<stdio.h>
int main()
{
	int n,m,i,j;
	printf("enter value:");
	scanf("%d %d",&n,&m);
	int arr[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
		}
		printf("\n");
    }
    int result=0;
    int odd=0,even=0;
    for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			result=result+arr[i][j];
			printf("%d ",arr[i][j]);
			int k=arr[i][j]%2==0;
			int p=arr[i][j]%2!=0;
			even=even+k;
			odd=odd+p;
		}
		printf("\n");
         
    }
    printf(" result:%d\n",result);
    printf("Even count:%d\n",even);
    printf("odd count:%d\n",odd);
    printf(" total count %d",even+odd);
    return 0;
    
}

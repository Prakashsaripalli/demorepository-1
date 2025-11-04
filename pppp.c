#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n];
    int sum=0,count=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum=sum+arr[i];
    }   
    int k=sum/n;
    printf("avg %d\n",k);
    for(i=0;i<n;i++)
    {
        if (arr[i]>=k)
        {
            count=count+1;
        }
       
    }
     printf("%d\n",count);
    
}

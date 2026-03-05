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
    for(i=0;i<n;i++)
    {
        if (arr[i]>=k)
        {
            count=count+arr[i];
        }
        printf("%d",count);
    }
    
}


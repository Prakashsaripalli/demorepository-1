#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n],sum_even=0,sum_odd=0;
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        
    
     if(arr[i]%2==0)
     {
   	   sum_even =sum_even+arr[i];
     }
       else
     {
   	   sum_odd = sum_odd+arr[i];
     }
   }
   int s= abs(sum_even - sum_odd);
   printf("%d",s);
}


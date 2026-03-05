#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
    {
        int num;
        scanf("%d",&num);
        int j,digits,k,sum=0;
        for(j=num;j>=1;j/=10)
        {
            digits=j%10;
            int factorial=1;
            for(k=1;k<=digits;k++)
            {
                factorial=factorial*k; 
            }
            sum=sum+factorial;
        }
        if(sum==num)
        {
            printf("Strong");
        }
        else
        {
            printf("Not Strong");
        }
    }
}

#include<stdio.h>
int main()
{
    int n,m;
    float k;
    scanf("%d%d",&n,&m);
    k=n*(0.9);
    if(k<m)
    {
        printf("ONLINE\n");
    }
    else if(k>m)
    {
        printf("DINING\n");
    }
    else
    {
        printf("EITHER\n");
    }
}

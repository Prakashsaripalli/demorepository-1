#include<stdio.h>
#include<string.h>
int main()
{
    char string[100000];
    int i,count=0;
    scanf("%[^\n]s",string);
    for(i=0;i<=strlen(string);i++)
    {
        if(string[i]>='0' && string[i]<='9')
        {
            count=count+(int)(string[i]-48);
        }
    }
    printf("%d",count);
    return 0;
}

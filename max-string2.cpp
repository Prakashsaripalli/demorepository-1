#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	char ch='A';
	char str[100000];
    scanf("%[^\n]s",str);
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]>ch)
        {
            ch=str[i];
        }
    }
    printf("%c",ch);
    return 0;
}

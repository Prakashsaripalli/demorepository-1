#include<stdio.h>
int main()
{
	char a[900];
	gets(a);
	int i,count=0,c=0;
	for(i=0;a[i]!='\0';i++){
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
		count++;
		else
		c++;
	}
	printf("Vowels = %d\nconsonants= %d",count,c);
	return(0);
}

#include <stdio.h>

int main()
 {
	int n;
	printf("enter:");
	scanf("%d", &n);
    char str[n];
	scanf(" %[^\n]", str);
	printf("%s\n", str); 
    int l = 0;
    while (str[l] != '\0') {
        l++;  
    }
    printf("The length of the string is : %d\n", l);
    return 0;
}


#include<stdio.h> 
#include<string.h> 
int main()  
{ 
    char str1[100], str2[100]; 
    
    printf("Enter the first string: "); 
    scanf("%s",str1);   
  
    printf("Enter the second string: "); 
    scanf("%s",str2); 
     
    // Find string length 
    printf("Length of the first string: %d\n", strlen(str1)); 
    
    // Concatenate strings 
    strcat(str1, str2); 
    printf("Concatenated string: %s\n",str1); 
   
    // Reverse the second string 
    strrev(str2); 
    printf("Reversed first string: %s\n", str2); 
 
    return 0; 
} 

#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#define MAX 20 
void push(int); 
int pop(); 
int peek(); 
int evaluationofpostfix(char*); 
int stack[MAX], top = -1; 
void push(int n) { 
 top++; 
    stack[top] = n; 
} 
int pop() { 
 int n=stack[top]; 
    top--; 
    return n; 
} 
int peek() { 
    return stack[top]; 
} 
int evaluationofpostfix(char *ex) { 
    int a = 0, c = 0, i; 
    for (i = 0; ex[i] != '\0'; i++) { 
        if (isdigit(ex[i])) 
            a++; 
        else if (ex[i] == '+' || ex[i] == '-' || ex[i] == '*' || ex[i] == '/' || ex[i] == '%' || ex[i] == '^') 
            c++; 
    } 
    if (a <= c) { 
        printf("Invalid Expression\n"); 
        exit(0); 
    } 
    for (i = 0; ex[i] != '\0'; i++) { 
        if (isdigit(ex[i]) || ex[i] == '+' || ex[i] == '-' || ex[i] == '*' || ex[i] == '/' || ex[i] == '%') { 
            if (isdigit(ex[i])) 
                push(ex[i] - '0'); 
            else { 
                int x1, x2; 
                x1 = pop(); 
                x2 = pop(); 
                switch (ex[i]) { 
                    case '+': push(x2 + x1); break; 
                    case '-': push(x2 - x1); break; 
                    case '*': push(x2 * x1); break; 
                    case '/': push(x2 / x1); break; 
                    case '%': push(x2 % x1); break; 
                } 
            } 
        } else { 
            printf("Invalid expression\n"); 
            exit(0); 
        } 
    } 
    if (top != 0) { 
        printf("Invalid expression\n"); 
        exit(0); 
    } else { 
        return stack[top]; 
    } 
} 
int main() { 
    char exp[MAX]; 
    printf("Enter a valid postfix expression: "); 
    gets(exp); 
    printf("Result of postfix evaluation is %d\n", evaluationofpostfix(exp)); 
    return 0; 
} 
#include<stdio.h>
#include<ctype.h>

#define MAX 100
int stack[MAX];
int top=-1;

void push(int val){
	stack[++top]=val;
}

int pop(){
	return stack[top--];
}

int main(){
	char expression[MAX];
	int i,a,b;
	printf("Enter the Expression like 124 132 * 1243 :");
	scanf("%s",expression);
	for(i=0;expression[i]!='\0';i++){
		char ch=expression[i];
		if(isdigit(ch)){
			push(ch -'0');
		}else{
			b=pop();
			a=pop();
			
			switch(ch){
				case '+':push(a+b); break;
				case '-':push(a-b); break;
				case '*':push(a*b); break;
				case '/':push(a/b); break;
			}
		}
	}
	printf("result is %d",pop());
}

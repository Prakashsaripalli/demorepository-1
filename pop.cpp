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
  
  int main()
  {
  	char exp[MAX];
  	int i,a,b;
  	printf("enter the experssion:");
  	scanf("%s",exp);
  	
  	for(i=0;exp[i]!='\0';i++)
  	{
  		char ch=exp[i];
  		
  		if(isdigit(ch))
  		{
  			push(ch -'0');
		  }
		  else{
		  	b=pop();
		  	a=pop();
		  	
		  	switch(ch)
		  	{
		  		case '+':push(a+b); break;
		  		case '-':push(a-b); break;
		  		case '*':push(a*b); break;
		  		case '/':push(a/b); break;
			  }
		  }
		  
	  }
	  printf("result : %d",pop());
  }

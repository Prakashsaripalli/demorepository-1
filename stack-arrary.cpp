#include<stdio.h> 
#include<stdlib.h> 
#define MAX 5 
void pop(); 
void push(); 
void peek(); 
void display(); 
int stack[MAX],top=-1,count=0; 
void push() 
{ 
 if(top==MAX-1) 
 printf("Stack is overflow\n"); 
 else 
 { 
  top++; 
  printf("Enter data to push:"); 
  scanf("%d",&stack[top]); 
  count++; 
 } 
} 
void pop() 
{ 
 if(top==-1) 
 printf("stack is underflow\n"); 
 else 
 { 
  printf("%d is poped from stack\n",stack[top]); 
  top--; 
  count--; 
 } 
} 
void peek() 
{ 
 if(top==-1) 
 printf("stack is empty\n"); 
 else 
 printf("Top element is %d\n",stack[top]); 
} 
void display() 
{ 

 if(top==-1) 
 printf("Stack is empty\n"); 
 else 
 { 
  int i; 
  for(i=top;i>=0;i--) 
  printf("\t%d\n",stack[i]); 
 } 
} 
int main() 
{ 
 int ch; 
while(1)
 { 
  printf("1.Push\n2.Pop\n3.Peek\n4.Count\n5.display\n"); 
  printf("Enter your choice:"); 
  scanf("%d",&ch); 
  switch(ch) 
  { 
   case 1:push(); break; 
   case 2:pop(); break; 
   case 3:peek(); break; 
   case 4:printf("Number of elements in stack are %d\n",count); break; 
   case 5:display(); break; 
   default:exit(0); 
  } 
 }
}
#include<stdio.h> 
#include<stdlib.h> 
struct stack 
{ 
 int data; 
 struct stack *next; 
}; 
typedef struct stack STACK; 
STACK *top=NULL; 
int count=0; 
void push(); 
void pop(); 
void peek(); 
void display(); 
void push() 
{ 
 STACK *New=(STACK*)malloc(sizeof(STACK)); 
 printf("Enter data to push:"); 
 scanf("%d",&New->data); 
 New->next=NULL; 
 count++; 
 if(top==NULL) 
 top=New; 
 else 
 { 
  New->next=top; 
  top=New; 
 } 
} 
void pop() 
{ 
 if(top==NULL) 
 printf("Stack is underflow\n"); 
 else 
 { 
  STACK *temp=top; 
  top=top->next; 
  printf("%d is poped from the memory\n",temp->data); 
  count--; 
  free(temp); 
 } 
} 

void peek() 
{ 
 if(top==NULL) 
 printf("Stack is emepty\n"); 
 else 
 printf("Top element is %d\n",top->data); 
} 
void display() 
{ 
 if(top==NULL) 
 printf("Stack is empty\n"); 
 else 
 { 
  STACK *t=top; 
  while(t!=NULL) 
  { 
   printf("\t%d\n",t->data); 
   t=t->next; 
  } 
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
   case 3:peek();break; 
   case 4:printf("Number of elements in stack are %d\n",count); break; 
   case 5:display(); break; 
   default:exit(0); 
  } 
 }
} 
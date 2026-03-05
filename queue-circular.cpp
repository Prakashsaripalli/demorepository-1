#include<stdio.h> 
#include<stdlib.h> 
#define MAX 5 
int Q[MAX],front=-1,rear=-1; 
void enque(); 
void deque(); 
void display(); 
void enque() 
{ 
 if(front==(rear+1)%MAX) 
 printf("Circular Queue is overflow.\n"); 
 else 
 { 
  if(front==-1) 
  front=rear=0; 
  else 
  rear=(rear+1)%MAX; 
  printf("Enter data to insert:"); 
  scanf("%d",&Q[rear]); 
 } 
} 
void deque() 
{ 
 if(front==-1) 
 printf("Circular Queue is underflow.\n"); 
 else { 
  printf("%d is removed.\n",Q[front]); 
  if(front==rear) 
  front=rear=-1; 
  else 
  front=(front+1)%MAX; 
 } 
} 
void display(){ 
 if(front==-1) 
 printf("Circular Queue is empty.\n"); 
 else { 
  int i=front; 
  while(i!=rear) 
  { 
   printf("%d\t",Q[i]); 
   i=(i+1)%MAX; 

  } 
  printf("%d\n",Q[i]); 
 } 
} 
int main(){ 
 int ch; 
while(1){ 
  printf("1.ENQUE\n2.DEQUE\n3.Display\nEnter your choice:"); 
  scanf("%d",&ch); 
  switch(ch){ 
   case 1:enque();  break; 
   case 2:deque();  break; 
   case 3:display();break; 
   default:exit(0); 
  } 
 }
} 
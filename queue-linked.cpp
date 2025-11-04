#include<stdio.h> 
#include<stdlib.h> 
struct queue 
{ 
 int data; 
 struct queue *next; 
}; 
typedef struct queue QUEUE; 
QUEUE *create(); 
void enque(); 
void deque(); 
void peep(); 
QUEUE *front=NULL,*rear=NULL; 
QUEUE *create() 
{ 
 QUEUE *New=(QUEUE*)malloc(sizeof(QUEUE)); 
 printf("Enter data to insert:"); 
 scanf("%d",&New->data); 
 New->next=NULL; 
 return New; 
} 
void enque() 
{ 
 QUEUE *New=create(); 
 if(front==NULL) 
 front=rear=New; 
 else 
 { 
  rear->next=New; 
  rear=New; 
 } 
} 
void deque() 
{ 
 if(front==NULL) 
 printf("Queue is underflow.\n"); 
 else 
 { 
  QUEUE *temp=front; 
  if(front==rear) 
  front=rear=NULL; 
  else {
  front=front->next; 
  printf("%d is removed from queue\n",temp->data); 
  free(temp); 
 } 
} 


void display() 
{ 
 if(front==NULL) 
 printf("Queue is empty.\n"); 
 else 
 { 
  QUEUE *temp=front; 
  while(temp!=rear) 
  { 
   printf("%d\t",temp->data); 
   temp=temp->next; 
  } 
  printf("%d\n",temp->data); 
 } 
} 
}
int main() 
{ 
 int ch; 
while(1)
 { 
  printf("1.ENQUE\n2.DEQUE\n3.Peep\n4.Display\n"); 
  printf("Enter your choice:"); 
  scanf("%d",&ch); 
  switch(ch) 
  { 
   case 1:enque(); break; 
   case 2:deque(); break; 
   case 3:peep();   break; 
   case 4:display(); break; 
   default:exit(0); 
  } 

 }
}
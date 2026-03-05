#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void enQueue (int);
void deQueue ();
void display ();

int queue[SIZE],front=-1,rear=-1;
int main()
{
	int value , choice;
	while(1){
	printf("\n\n*****MENU*****\n");
	printf("1.Insertion\n 2.Deletion\n 3.Display\n 4.Exit");
	printf("\n Enter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("Enter the value to be inserted:");
			scanf("%d",&value);
			enQueue(value);
			break;
			case 2:
				deQueue();
				break;
				case 3:
					display();
					break;
					case 4:
						exit(0);
						default:
							printf("\n wrong selection ! try again.");
							
	}
	}
	return 0;
}
void enQueue (int value ) {
	if (rear==SIZE-1){
		printf("\n Queue is full");
	}
	else{
		if (front==-1)
		front=0;
		rear++;
		queue[rear]=value;
		printf("\n Insertion successful !");
	}
}
void deQueue(){
	if (front==-1||front>rear){
		printf("\n Queue is empty");
	}else{
		printf("\n Deleted : %d",queue[front]);
		front++;
		if(front>rear)
		front=rear=-1;
	}
}
void display(){
	if(front==-1||front>rear){
		printf("\n Queue is empty !");
	} else{
		int i;
		printf("\n Queue elements are:\n");
		for(i=front;i<=rear;i++)
			printf("%d\t",queue[i]);
		
	}
}

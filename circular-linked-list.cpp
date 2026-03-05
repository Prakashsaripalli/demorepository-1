#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next ;
}N;
N *head = NULL;
N *create();
void insertAtBegin();
void insertAtEnd();
void insertAnywhere();
void deleteAtBegin();
void deleteAtEnd();
void deleteAnywhere();
void traverse();
void reverse(N*);
int size =0;
N *create(){
	N new_node =(N)malloc(sizeof(N));
	printf("Enter Data:\n");
	scanf("%d",&new_node->data);
	size++;
	return new_node;
}
void traverse()
{
	if(head==NULL) printf("LIST Empty\n");
	else{
		N *temp = head;
		do{
			printf("-->%d",temp->data);
			temp = temp->next;
		}
		while(temp!=head);
			printf("-->%d",temp->data);
			printf("\n");
	}
}
void insertAtBegin(){
	N* new_node = create(),*t;
	if(head == NULL){
		head=new_node;
		head->next=head;
	}
	else{
		t=head;
		while(t->next!=head){
			t=t->next;
		}
		new_node->next=head;
		t->next=new_node;
		head=new_node;
	}
}
void insertAtEnd(){
	N *new_node=create(),*t;
	if(head==NULL){
		head=new_node;
		head->next=head;
	}
	else{
		new_node->next=head;
		t=head;
		while(t->next!=head){
			t=t->next;
			t->next=new_node;
		}
	}
}
void insertAnywhere(){
	int p,loc=0;
	printf("Enter position to insert:\n");
	scanf("%d",&p);
	if(head==NULL) printf("NO such position\n");
	else if(p==1){
		insertAtBegin();
	}
	else if(p== size+1) insertAtEnd();
	else if(p>size) printf("NO such position\n");
	else {
		N *new_node=create(),*t,*pr;
		t=pr=head;
		while(t->next!=head){
			loc++;
			if(loc==p) break;
			pr=t;
			t=t->next;
		}
		new_node->next=t;
		pr->next=new_node;
	}
}
void deleteAtBegin(){
	if(head==NULL) printf("List is Empty!!!\n");
	else if(size==1){
		N *temp =head;
		printf("%d is removed\n",temp->data);
		size--;
		head=NULL;
		free(temp);
	}
	else{
		N *t,*temp;
		t=temp=head;
		while(t->next!=head)
		t=t->next;
		t->next=head->next;
		head=head->next;
		printf("%d is removed\n",temp->data);
		size--;
		free(temp);
	}
}
void deleteAtEnd(){
	N *temp,*t;
	temp=t=head;
	if(head==NULL) printf("List is empty!!!\n");
	else if(size==1){
		printf("%d is removed\n",temp->data);
		size--;
		head=NULL;
		free(temp);
	}
	else{
		while(temp->next!=head){
			t=temp;
			temp=temp->next;
		}
		t->next=head;
		printf("%d is removed\n",temp->data);
		size--;
		free(temp);
	}
}
void deleteAnywhere(){
	N *temp,*t;
	temp=t=head;
	if(head==NULL) printf("List is Empty!!!\n");
	else{
		int p,loc=0;
		printf("Enter position to delete:\n");
		scanf("%d",&p);
		if(p==1) deleteAtBegin();
		else if(p==size) deleteAtEnd();
		else if(p>size) printf("NO such position\n");
		else{
			while(temp->next!=head){
				loc++;
				if(loc==p) break;
				t=temp;
				temp=temp->next;
			}
			t->next=temp->next;
			printf("%d is removed\n",temp->data);
			size--;
			free(temp);
		}
	}
}
int main(){
	int ch;
	do{
		printf("1.Insert at beginning.\n");
		printf("2.Insert at ending\n");
		printf("3.Insert at anywhere\n");
		printf("4.Delete at beginning\n");
		printf("5.Delete at ending\n");
		printf("6.Delete at anywhere\n");
		printf("7.Traverse\n");		
		printf("8.count\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:insertAtBegin();
			break;
			case 2:insertAtEnd();
			break;
			case 3:insertAnywhere();
			break;
			case 4:deleteAtBegin();
			break;
			case 5:deleteAtEnd();
			break;
			case 6:deleteAnywhere();
			break;
			case 7:traverse();
			break;
			case 8:printf("Number of elements are %d\n",size);
			break;
			default:exit(0);
		}
	}
		while(1);
		return 0;
}

/*//Implementation of stacks using Arrays
#include<stdio.h>
int stack[10000],size,top=-1;
void push(int val)
{
	//Overflown condition --> If the stack is already full
	if(top==size-1)
	{
		printf("Stack is overflown. No more insertions possible\n");
		return;
	}
	else
	{
		top++;
		stack[top]=val;//Or you can use stack[++top]=val (first increment and then the val is placed)	
	}
}
void display()
{
	if(top==-1)
	{
		printf("Stack is Underflow / Empty\n");
		return;
	}
	int i;
	for(i=top;i>=0;i--) printf("%d ",stack[i]);
	printf("\n");
}
void pop()
{
	if(top==-1)
	{
		printf("Stack is Underflown / Empty\n");
	}
	else
	{
		printf("Deleting: %d\n",stack[top]);
		top--;
	}
}
void peek()
{
	if(top==-1)
	{
		printf("Stack is Underflown / Empty\n");
		return;
	}
	else
	{
		printf("The element which is at the top of the stack : %d",stack[top]);
	}
	printf("\n");
}
int main()
{
	printf("Enter the max numbers of elements stack can hold: ");
	scanf("%d",&size);
	int ch;
	while(1)
	{
		printf("Enter\n1. Push\n2. Pop\n3. Display\n4. Peek\nAny other to exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			//Implement Push() ---> Adding a new element to the stack
			int e;
			printf("Enter an element to push into the stack: ");
			scanf("%d",&e);
			push(e);	//Function Call
		}
		else if(ch==2)
		{
			pop();
		}
		else if(ch==3)
		{
			display();
		}
		else if(ch==4)
		{
			peek();	
		}
		else
		{
			printf("Thank you!\n");
			break;
		}
	}
}*/
//coversion of postflix (reverse polish notation)
// For DFT Tree Traversals
// Code to construct a tree manually
/*#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node treenode;

treenode *createNewNode(int val) {
	// Create a new node
	treenode *new_node = (treenode *)malloc(sizeof(treenode));
	// put value in data part
	// set right and left to NULL
	new_node->data = val;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void preOrder(treenode *root) {
	if (root != NULL)
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void inOrder(treenode *root) {
	if (root != NULL)
	{
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}
void postOrder(treenode *root) {
	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}
int main() {
	// Create 7 nodes
	treenode *n1 = createNewNode(10);
	treenode *n2 = createNewNode(20);
	treenode *n3 = createNewNode(30);
	treenode *n4 = createNewNode(40);
	treenode *n5 = createNewNode(50);
	treenode *n6 = createNewNode(60);
	treenode *n7 = createNewNode(70);
	// Connecting the nodes
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	treenode *root = n1;
//	printf("%d ", root->left->left->data);
	printf("Pre-Order Traversal: ");
	preOrder(root);
	printf("\n");
	printf("In-Order Traversal: ");
	inOrder(root);
	printf("\n");
	printf("Post-Order Traversal: ");
	postOrder(root);
	printf("\n");
	return 0;
}*/
//BST Implementation
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node TreeNode;
TreeNode *createnode(int val)
{
	TreeNode *newnode=(TreeNode *)malloc(sizeof(TreeNode));
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
TreeNode *insertanewnode(TreeNode *root,int val)
{
	TreeNode *newnode=createnode(val);
	if(root==NULL)
	{
		root =newnode;
		return root;
	}
	TreeNode *temp=root;
	TreeNode *parent=NULL;
	while(temp!=NULL)
	{
		parent=temp;
		if(temp->data<val)
		{
			temp=temp->right;
		}
		else
		{
			temp=temp->left;
		}
	}
	if(val<parent->data)
	{
		parent->left=newnode;
	}
	else
	{
		parent->right=newnode;
	}
	return root;
}
void InOrder(TreeNode *root)
{
	if(root)
	{
		InOrder(root->left);
		printf("%d ",root->data);
		InOrder(root->right);
	}
}
int main()
{
	int ch;
	TreeNode *root= NULL;
	while(1)
	{
		printf("1. Construct BST\n2. Traversal\n3. Search\nAny other to exit");
		scanf("%d",&ch);
		if(ch==1)
		{
			int a[]={40,32,68,36,54,79,16,52,29,146,7};
			int n=sizeof(a)/sizeof(int);
			int i;
			for(i=0;i<n;i++)
			{
				root=insertanewnode(root,a[i]);
			}
			
			//Construct a BST
		}
		else if(ch==2)
		{
			InOrder(root);
			printf("\n");
			//Run a loop onj constructed BST
			//In-Order Traversalih
		}
	}
}

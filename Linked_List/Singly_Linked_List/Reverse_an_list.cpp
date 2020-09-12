#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void reverse(struct node *head_r)
{
	struct node *prev,*curr,*next;
	prev=NULL;
	curr=head_r;
	while(curr!=NULL)
	{							
		next=curr->next;		//assigning the value of next as next of the current node
		curr->next=prev;		
		prev=curr;				//placing the prev to the curr place
		curr=next;				//placing the curr to the next place 
	}
	head_r=prev;
	struct node *trav=(struct node *)malloc(sizeof(struct node));
	trav=head_r;
	while(trav!=NULL)
	{
		cout<<trav->data<<" ";
		trav=trav->next;
	}
	cout<<endl;	
}
void push(struct node **head_p,int d)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=(*head_p);
	(*head_p)=newnode;
}
int main()
{
	struct node *head=NULL;
	push(&head,5);			//inserting the values in the begining 
	push(&head,4);			
	push(&head,3);
	push(&head,2);
	push(&head,1);
	reverse(head);
}

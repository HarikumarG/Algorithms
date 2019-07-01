#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void push(struct node **head,int d)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=(*head);
	(*head)=newnode;
}
void print(struct node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}
struct node* reverse(struct node *head,int k)
{
	struct node *curr=head;
	struct node *prev=NULL;
	struct node *next=NULL;
	int count=0;
	/*reverse first k nodes of the linked list */
	while(curr !=NULL && count<k)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;
	}
	/* Next is now a pointer to (k+1)th node 
       Recursively call for the list starting from current.
       And make rest of the list as next of first node */
	if(next !=NULL)
	{
		head->next= reverse(next,k);
	}

    /* prev is new head of the input list */
	
    return prev;
}
int main()
{
	struct node *head=NULL;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	head=reverse(head,3);
	print(head);
}

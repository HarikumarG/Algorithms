#include<iostream>
#include<stdlib.h>
using namespace std;
struct node 
{
	int data;
	struct node *next;
	struct node *prev;
};
void delete_node(struct node **head,int d)
{
	struct node *del;
	del=(*head);
	if((*head)==NULL)
	{
		return;
	}
	while(del->data != d)
	{
		del=del->next;
	}
	if(del->prev == NULL)
	{
		(*head)=del->next;
	}
	if(del->prev != NULL)
	{
		del->prev->next=del->next;
	}
	if(del->next != NULL)
	{
		del->next->prev=del->prev;
	}
	free(del);
}
void push(struct node **head,int d)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->prev=NULL;
	newnode->next=(*head);
	if((*head)!=NULL)
	{
		(*head)->prev=newnode;
	}
	(*head)=newnode;
}
void print(struct node *head)
{
	struct node *trav;
	trav=head;
	while(trav!=NULL)
	{
		cout<<trav->data<<" ";
		trav=trav->next;
	}
}
int main()
{
	struct node *head=NULL;
	push(&head,2);
	push(&head,4);
	push(&head,8);
	push(&head,10);
	push(&head,12);
	push(&head,14);
	delete_node(&head,14);
	delete_node(&head,8);
	delete_node(&head,2);
	print(head);
}
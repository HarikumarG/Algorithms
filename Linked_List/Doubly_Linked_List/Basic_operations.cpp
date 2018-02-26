#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
void insert_at_begining(struct node **head_b,int d)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->prev=NULL;
	newnode->next=(*head_b);
	if((*head_b!=NULL))
	{
		(*head_b)->prev=newnode;
	}
	(*head_b)=newnode;
}
void insert_at_end(struct node **head_e,int d)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	struct node *last;
	last=(*head_e);
	newnode->data=d;
	newnode->next=NULL;
	if((*head_e==NULL))
	{
		newnode->prev=NULL;
		(*head_e)=newnode;	
	}
	else
	{
		while(last->next!=NULL)
		{
			last=last->next;
		}
		last->next=newnode;
		newnode->prev=last;
	}
}
void insert_after(struct node **head_a,int d)
{
	int af=7;
	struct node *after;
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=d;
	if((*head_a) !=NULL)
	{
		after=(*head_a);
		while(after->data !=af)
		{
			after=after->next;
		}
		newnode->next=after->next;
		after->next->prev=newnode;
		after->next=newnode;
		newnode->prev=after;
	}
	else
	{
		newnode->prev=NULL;
		(*head_a)=newnode;	
	}
}
void print(struct node *head)
{
	struct node *trav;
	struct node *last;
	trav=head;
	cout<<"Forward direction\n";
	while(trav!=NULL)
	{
		cout<<" "<<trav->data;
		last=trav;
		trav=trav->next;
	}
	cout<<"\nReverse direction\n";
	while(last!=NULL)
	{
		cout<<" "<<last->data;
		last=last->prev;
	}
}
int main()
{
	struct node *head=NULL;
	insert_at_begining(&head,6);
	insert_at_begining(&head,7);
	insert_at_end(&head,8);
	insert_at_end(&head,9);
	insert_after(&head,2);
	print(head);
}
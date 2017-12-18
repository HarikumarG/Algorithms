#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void insert_at_begining(struct node *head_f)
{
	int element =8;
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=element;
	newnode->next=NULL;
	if(head_f==NULL)
	{
		head_f=newnode;
	}
	else
	{
		newnode->next=head_f;
		head_f=newnode;
	}
	struct node *trav=(struct node *)malloc(sizeof(struct node));
	trav=head_f;
	while(trav!=NULL)
	{
		cout<<trav->data<<"->";
		trav=trav->next;
	}
}
void insert_at_middle(struct node *head_m)
{
	int element=8,before=3;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=element;
	newnode->next=NULL;
	struct node *p=head_m;
	struct node *temp;
	if(head_m==NULL)
	{
		head_m=newnode;
	}
	else
	{
		while(p->data!=before)
		{
			temp=p;
			p=p->next;
		}
		temp->next=newnode;
		newnode->next=p;
	}
	struct node *trav=(struct node *)malloc(sizeof(struct node));
	trav=head_m;
	while(trav!=NULL)
	{
		cout<<trav->data<<"->";
		trav=trav->next;
	}
}
void insert_at_end(struct node *head_e)
{
	int element=8;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=element;
	newnode->next=NULL;
	struct node *p=head_e;
	if(head_e==NULL)
	{
		head_e=newnode;
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=newnode;
		newnode->next=NULL;
	}
	struct node *trav=(struct node *)malloc(sizeof(struct node));
	trav=head_e;
	while(trav!=NULL)
	{
		cout<<trav->data<<"->";
		trav=trav->next;
	}
}
void push(struct node **head_r,int d)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=(*head_r);
	(*head_r)=newnode;
}
int main()
{
	struct node *head=NULL;
	//address is passed since that we are not returing the head so its by call by reference
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	insert_at_begining(head);
	insert_at_end(head);
	insert_at_middle(head);
}
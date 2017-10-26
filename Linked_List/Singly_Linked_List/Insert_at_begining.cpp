#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void insert(struct node *head_f)
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
	/*push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);*/
	insert(head);
}
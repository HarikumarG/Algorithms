#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void swap(struct node **head,int k)
{
	int n=1;
	struct node *count;
	count=(*head);
	while(count->next != NULL)
	{
		n++;
		count=count->next;
	}
	if(n<k)
	{
		return;
	}
	if(2*k-1==n)
	{
		return;
	}
	struct node *x_prev;
	struct node *x=(*head);
	struct node *y_prev;
	struct node *y=(*head);
	for(int i=1;i<n-k+1;i++)
	{
		if(i<k)
		{
			x_prev=x;
			x=x->next;
		}
		y_prev=y;
		y=y->next;
	}
	if(x_prev)
	{
		x_prev->next=y;
	}
	if(y_prev)
	{
		y_prev->next=x;
	}
	struct node *temp;
	temp=x->next;
	x->next=y->next;
	y->next=temp;
	if(k==1)
	{
		(*head)=y;
	}
	if(k==n)
	{
		(*head)=x;
	}
}
void push(struct node **head,int d)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=(*head);
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
	push(&head,12);
	push(&head,10);
	push(&head,8);
	push(&head,6);
	push(&head,4);
	push(&head,2);
	swap(&head,2);
	print(head);
}
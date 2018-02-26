#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void swap(struct node *a,struct node *b)
{
	int temp= a->data;
	a->data=b->data;
	b->data=temp;
}
void print(struct node *head_p)
{
	struct node *trav_p;
	trav_p=head_p;
	while(trav_p!=NULL)
	{
		cout<<trav_p->data<<" ";
		trav_p=trav_p->next;
	}
}
int bubble(struct node *head_s)
{
	int swapped;
	struct node *lptr=NULL;
	struct node *trav;
	trav=head_s;
	if(trav==NULL)
	{
		return 0;
	}
	do
	{
		trav=head_s;
		swapped=0;
		while(trav->next!=lptr)
		{
			if(trav->data > trav->next->data)
			{
				swap(trav,trav->next);
				swapped=1;
			}
			trav=trav->next;
		}
		lptr=trav;

	}while(swapped);
	print(head_s);
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
	push(&head,1);
	push(&head,4);
	push(&head,3);
	push(&head,5);
	push(&head,2);
	bubble(head);
}
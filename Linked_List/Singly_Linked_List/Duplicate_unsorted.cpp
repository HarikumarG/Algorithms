#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void print(struct node *head_o)
{
	struct node *trav;
	trav=head_o;
	while(trav!=NULL)
	{
		cout<<trav->data<<" ";
		trav=trav->next;
	}
}
void push(struct node **head_p,int d)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=(*head_p);
	(*head_p)=newnode;
}
void duplicate(struct node *head_d)
{
	struct node *ptr1,*ptr2,*dup;
	ptr1=head_d;
	while(ptr1 !=NULL && ptr1->next != NULL)
	{
		ptr2=ptr1;
		while(ptr2->next!=NULL)
		{
			if(ptr1->data == ptr2->next->data)
			{
				dup=ptr2->next;
				ptr2->next=ptr2->next->next;
				delete(dup);
			}
			else
			{
				ptr2=ptr2->next;
			}
		}
		ptr1=ptr1->next;
		
	}
}
int main()
{
	struct node *head=NULL;
	push(&head,7);
	push(&head,7);
	push(&head,8);
	push(&head,8);
	push(&head,9);
	push(&head,10);
	push(&head,10);
	duplicate(head);
	return 0;
}
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node 
{
	int data;
	struct node *next;
};
void middle(struct node *head)
{
	struct node *slow=head;
	struct node *fast=head;
	if(head!=NULL)
	{
		while(fast!=NULL && fast->next!=NULL)
		{
			fast=fast->next->next;
			slow=slow->next;
		}
		cout<<"The middle element is "<<slow->data;
	}
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
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	middle(head);
}


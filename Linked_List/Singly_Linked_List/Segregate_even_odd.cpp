#include<iostream>
#include<stdlib.h>
using namespace std;
struct node 
{
	int data;
	struct node* next;
};
void segregate(struct node *head)
{
	struct node *even_start=NULL;
	struct node *even_end=NULL;
	struct node *odd_start=NULL;
	struct node *odd_end=NULL;
	struct node *curr=head;
	while(curr!=NULL)
	{
		int element=curr->data;
		if(element %2 ==0)
		{
			if(even_start==NULL)
			{
				even_start=curr;
				even_end=curr;
			}
			else
			{
				even_end->next=curr;
				even_end=even_end->next;
			}
		}
		else
		{
			if(odd_start==NULL)
			{
				odd_start=curr;
				odd_end=curr;
			}
			else
			{
				odd_end->next=curr;
				odd_end=odd_end->next;
			}
		}
		curr=curr->next;
	}
	if(odd_start==NULL || even_start==NULL )
	{
		return;
	}
	even_end->next=odd_start;
	odd_end->next=NULL;
	head=even_start;
	struct node *trav=head;
	while(trav!=NULL)
	{
		cout<<trav->data;
		cout<<" ";
		trav=trav->next;
	}
}
void push(struct node **head,int d)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=(*head);
	(*head)=newnode;
}
int main()
{
	struct node* head=NULL;
	push(&head,10);
	push(&head,8);
	push(&head,7);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	segregate(head);

}
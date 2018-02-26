#include<iostream>
#include<stdlib.h>
using namespace std;
struct node 
{
	int data;
	struct node *next;
};
void remove(struct node *loop_node,struct node *head)
{
	struct node *ptr1;
	struct node *ptr2;
	ptr1=head;
	while(1)
	{
		ptr2=loop_node;
		while(ptr2->next != loop_node && ptr2->next != ptr1)
		{
			ptr2=ptr2->next;
		}
		if(ptr2->next==ptr1)
			break;
		ptr1=ptr1->next;
	}
	ptr2->next=NULL;

	struct node *trav=head;
	while(trav!=NULL)
	{
		cout<<trav->data<<" ";
		trav=trav->next;
	}
}
void detect(struct node *head)
{
	int flag=0;
	struct node *slow=head;
	struct node *fast=head;
	while(slow && fast && fast->next)   //Floyd’s Cycle detection algorithm 
	{									//	terminates when fast and slow pointers meet  
		slow=slow->next;				// fast pointers
		fast=fast->next->next;
		if(slow==fast)
		{
			flag=1;
			remove(slow,head);
		}
	}
	if(flag==0)
		cout<<"There is no loop";
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
	push(&head,2);
	push(&head,5);
	push(&head,7);
	push(&head,9);
	push(&head,11);
	 /* Create a loop for testing */
	head->next->next->next->next->next=head->next->next;
	detect(head);
}
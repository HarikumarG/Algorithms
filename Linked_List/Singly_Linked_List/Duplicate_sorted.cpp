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
	struct node *nex;
	struct node *curr=head_d;
	if(curr == NULL)
	{
		return;
	}
	else
	{
		while(curr->next!=NULL)
		{
			if(curr->data==curr->next->data)
			{
				nex=curr->next->next;			
				free(curr->next);//delete the duplicate by connecting left of duplicate to 
				curr->next=nex;  //right of duplicate
			}
			else
			{
				curr=curr->next;
			}
		}
		print(head_d);
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
#include<iostream>
#include<stdlib.h>
using namespace std;
//Declaring the structure
struct node
{
	int data;
	struct node *next;
};
//inserting the data to the head
//double pointer is used since implementing the call by reference method ..Any change made that reflects back in the actual parametes
void push(struct node **head_r,int d)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=(*head_r);
	(*head_r)=newnode; 
}
//displaying the list
void display(struct node *head_d)
{
	struct node *trav=head_d;
	while(trav!=NULL)
	{
		cout<<trav->data;
		cout<<" ";
		trav=trav->next;
	}

}
int main()
{
	struct node *head=NULL;
	// passing the address since call by reference method ...
	push(&head,1); 
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
	display(head);
	return 0;	
}
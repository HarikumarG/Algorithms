#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
Node *reverse(Node *head)
{
	Node *prev=NULL;
	Node *current=head;
	Node *next;
	while(current !=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	return prev;
}
int count(Node *head)
{
	int c=0;
	Node *trav=head;
	while(trav!=NULL)
	{
		c++;
		trav=trav->next;
	}
	return c;
}
Node *addsum(Node *head,Node *head1)
{
	Node *res=head;
	Node *temp;
	int carry=0,sum;
	while(head!=NULL)
	{
		sum=carry+head->data+head1->data;
		carry=(sum>=10)?1:0;
		sum=sum%10;
		head->data=sum;
		temp=head;
		head=head->next;
		head1=head1->next;
	}
	 if (carry > 0)
	 {
        temp->next = newNode(carry);
     }
	return res; 
}
Node *add(Node *head,Node *head1)
{
	Node *result=NULL;
	head=reverse(head);
	head1=reverse(head1);
	result=addsum(head,head1);
	return reverse(result);
}
void printList(Node *node)
{
    while (node != NULL)
    {
       cout<<node->data;
        node = node->next;
    }
    cout<<"\n";
}
void push(Node **head_r,int d)
{
	Node *newnode=newNode(d);
	newnode->next=(*head_r);
	(*head_r)=newnode;
}
int main()
{
    Node *head = newNode(1);
    head->next = newNode(9);
    head->next->next = newNode(9);
    head->next->next->next = newNode(9);
    head->next->next->next->next= newNode(9);
 
    cout<<"First List is ";
    printList(head);
 	
 	Node *head1 = newNode(2);
    head1->next = newNode(3);
    head1->next->next = newNode(5);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next= newNode(9);
    head1->next->next->next->next->next= newNode(6);
    head1->next->next->next->next->next->next= newNode(2);
    cout<<"Second List is ";
    printList(head1);

    Node *result=NULL;

    int headcount=count(head);
    int head1count=count(head1);
    if(headcount>=head1count)
    {
    	int dif=headcount-head1count;
    	while(dif!=0)
    	{	
    		push(&head1,0);
    		dif--;
    	}
    }
 	else
 	{
 		int dif=head1count-headcount;
 		while(dif!=0)
    	{	
    		push(&head,0);
    		dif--;
    	}
 	}
 	result = add(head,head1);
    cout<<"\nResultant list is ";
    printList(result);
 
    return 0;
}

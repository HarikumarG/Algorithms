#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>storeset;
struct Node
{
	int data;
	Node *next;
};
void push(Node **head,int d)
{
	Node *newnode=new Node;
	newnode->data=d;
	newnode->next=(*head);
	(*head)=newnode;
}
void printlist(Node *head)
{
	Node *trav=NULL;
	trav=head;
	while(trav!=NULL)
	{
		cout<<trav->data<<" ";
		trav=trav->next;
	}
}
void duplicate(Node *head)
{
	Node *curr=head;
	Node *prev=NULL;
	storeset seen;
	while(curr!=NULL)
	{
		if(seen.find(curr->data)!=seen.end())
		{
			prev->next=curr->next;
			delete(curr);
		}
		else
		{
			seen.insert(curr->data);
			prev=curr;
		}
		curr=prev->next;
	}
	printlist(head);
}
int main()
{
	Node *head=NULL;
	push(&head,10);
	push(&head,8);
	push(&head,2);
	push(&head,10);
	push(&head,6);
	push(&head,10);
	push(&head,2);
	push(&head,2);
	push(&head,3);
	push(&head,1);
	duplicate(head);
	return 0;
}
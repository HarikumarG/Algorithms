#include<bits/stdc++.h>
using namespace std;
struct Tnode
{
	int data;
	Tnode *left,*right;
};
void preorder(Tnode *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
Tnode *newNode(int d)
{
	Tnode *temp=(Tnode *)malloc(sizeof(Tnode));
	temp->data=d;
	temp->left=temp->right=NULL;
	return temp;
}
Tnode *arrayToBst(int arr[],int start,int end)
{
	if(start > end)
		return NULL;
	int mid=(start+end)/2;
	Tnode *root=newNode(arr[mid]);
	root->left=arrayToBst(arr,start,mid-1);
	root->right=arrayToBst(arr,mid+1,end);
	return root;
}
struct Lnode
{
	int data;
	Lnode *next;
};
void push(Lnode **head,int d)
{
	Lnode *newnode=(Lnode *)malloc(sizeof(Lnode));
	newnode->data=d;
	newnode->next=(*head);
	(*head)=newnode;
}
int count(Lnode *head)
{
	Lnode *trav=head;
	int no=0;
	while(trav!=NULL)
	{
		no++;
		trav=trav->next;
	}
	return no;
}
Tnode *listToBst(Lnode **head,int n)
{
	
}
int main()
{
	int arr[]={1,2,3,4,5,6,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	Tnode *root=arrayToBst(arr,0,n-1);
	preorder(root);
	Lnode *head=NULL;
	push(&head, 7); 
    push(&head, 6); 
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1); 
    int no=count(head);
    Tnode *root1=listToBst(&head,no);
    preorder(root1);
	return 0;
}
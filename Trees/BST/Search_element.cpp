#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *left,*right;
};
struct node *search(struct node *head,int find)
{
	if(head==NULL)
	{
		cout<<"\nElement not found";
		return head;
	}
	if(head->data==find)
	{
		cout<<"\nElement found "<<head->data;
		return head;
	}
	if(find<head->data)
	{
		 search(head->left,find);
	}
	else
	{
		 search(head->right,find);
	}
}
struct node *newnode(int k)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=k;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
struct node *insert(struct node *head_i,int key)
{
	if(head_i==NULL)
	{
		return newnode(key);
	}
	if(key<head_i->data)
	{
		head_i->left=insert(head_i->left,key);
	}
	else if(key>head_i->data)
	{
		head_i->right=insert(head_i->right,key);
	}
	return head_i;
}
int main()
{
	struct node *root=NULL;
	root=insert(root,50);
	insert(root, 40);
    insert(root, 30);
    insert(root, 20);
    insert(root, 45);
    insert(root, 25);
    insert(root, 35);
    insert(root, 32);
    insert(root, 60);
    insert(root, 70);
    insert(root, 65);
    insert(root, 90);
    insert(root, 80);
    search(root,190);
    return 0;
}
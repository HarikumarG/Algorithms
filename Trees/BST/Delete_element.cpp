#include<bits/stdc++.h>
using namespace std;
struct node
{
	int key;
	struct node *left,*right;
};
node *newnode(int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->left=temp->right=NULL;
	temp->key=data;
	return temp;
}
node *insert(node *root,int data)
{
	if(root == NULL)
	{
		root=newnode(data);
	}
	else if(root->key<data)
	{
		root->right=insert(root->right,data);
	}
	else
	{
		root->left=insert(root->left,data);
	}
	return root;
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}
node *minval(node *root)
{
	struct node *curr=root;
	while(curr->left != NULL)
	{
		curr=curr->left;
	}
	return curr;
}
node *deletenode(node *root,int data)
{
	if(root == NULL)
	{
		return root;
	}
	else if(root->key<data)
	{
		root->right=deletenode(root->right,data);
	}
	else if(root->key>data)
	{
		root->left=deletenode(root->left,data);
	}
	else
	{
		if(root->left == NULL)
		{
			node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			node *temp=root->left;
			free(root);
			return temp;
		}
		else
		{
			node *mintemp=minval(root->right);
			root->key = mintemp->key;
			root->right =deletenode(root->right,mintemp->key);
		}
	}
	return root;
}
int main()
{
	struct node *root = (struct node *)malloc(sizeof(struct node));
	root=NULL;
	root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
    inorder(root);
    cout<<"\nDelete node 20\n";
    root=deletenode(root,20);
    root=deletenode(root,30);
    root=deletenode(root,50);
    inorder(root);
    return 0;
}
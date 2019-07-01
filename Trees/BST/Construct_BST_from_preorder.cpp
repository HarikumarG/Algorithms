#include<bits/stdc++.h>
using namespace std;
struct node
{
	int key;
	struct node *left ,*right;
};
node *newnode(int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->left=temp->right=NULL;
	temp->key=data;
	return temp;
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
node *constructTreeUtil(int pre[],int *preind,int data,int min,int max,int size)
{
	if(*preind >=size)
	{
		return NULL;
	}
	node *root=NULL;
	if(data>min && data<max)
	{
		root=newnode(data);
		*preind=*preind+1;
		if(*preind<size)
		{
			root->left=constructTreeUtil(pre,preind,pre[*preind],min,data,size);
			root->right=constructTreeUtil(pre,preind,pre[*preind],data,max,size);
		}
	}
	return root;
}
node *constructTree(int pre[],int size)
{
	int preind=0;
	return constructTreeUtil(pre,&preind,pre[0],INT_MIN,INT_MAX,size);
}
int main()
{
	int pre[]={10, 5, 1, 7, 40, 50};
	int size=sizeof(pre)/sizeof(pre[0]);
	node *root=constructTree(pre,size);
	inorder(root);
	return 0;
}
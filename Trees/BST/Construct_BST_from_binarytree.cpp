#include<bits/stdc++.h>
using namespace std;
struct node
{
	int key;
	struct node *left,*right;
};
void Inorder(node *root)
{
	if(root != NULL)
	{
		Inorder(root->left);
		cout<<root->key<<" ";
		Inorder(root->right);
	}
}
int countnodes(node *root)
{
	if(root == NULL)
		return 0;
	return countnodes(root->left)+countnodes(root->right)+1;
}
node  *storeinarray(int arr[],int *i,node *root)
{
	if(root == NULL)
		return NULL;
	storeinarray(arr,i,root->left);
	arr[*i]=root->key;
	*i=*i+1;
	storeinarray(arr,i,root->right);
}
node *arraytoBST(int arr[],int *i,node *root)
{
	if(root == NULL)
		return NULL;
	arraytoBST(arr,i,root->left);
	root->key=arr[*i];
	(*i)++;
	arraytoBST(arr,i,root->right);
}
void binarytoBST(node *root)
{
	int n=countnodes(root);
	int arr[n];
	int i=0;
	storeinarray(arr,&i,root);
	sort(arr,arr+n);
	i=0;
	arraytoBST(arr,&i,root);
}
node* newNode (int data) 
{ 
    struct node *temp = new struct node; 
    temp->key = data; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
}
int main()
{
	struct node *root = NULL; 
  
    /* Constructing tree given in the above figure 
          10 
         /  \ 
        30   15 
       /      \ 
      20       5   */
    root = newNode(10); 
    root->left = newNode(30); 
    root->right = newNode(15); 
    root->left->left = newNode(20); 
    root->right->right = newNode(5); 
    binarytoBST(root);
    cout<<"The Inorder of BST is \n";
    Inorder(root);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	int lcount;
	node *left;
	node *right;
};
node *insert(node *root,node *node)
{
	struct node *ptraverse=root;
	struct node *currentparent=root;
	while(ptraverse)
	{
		currentparent=ptraverse;
		if(node->data < ptraverse->data)
		{
			ptraverse->lcount++;
			ptraverse=ptraverse->left;
		}
		else
		{
			ptraverse=ptraverse->right;
		}
	}
	if(!root)
	{
		root=node;
	}
	else if(node->data < currentparent->data)
	{
		currentparent->left=node;
	}
	else
	{
		currentparent->right=node;
	}
	return root;
}
node *binary_search_tree(node *root,int keys[],int size)
{
	int it;
	for(it=0;it<size;it++)
	{
		node *newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=keys[it];
		newnode->lcount=0;
		newnode->left=NULL;
		newnode->right=NULL;
		root=insert(root,newnode);
	}
	return root;
}
int k_smallest_element(node *root,int k)
{
	int ret =-1;
	if(root)
	{
		node *ptraverse=root;
		while(ptraverse)
		{
			if((ptraverse->lcount+1)==k)
			{
				ret=ptraverse->data;
				break;
			}
			else if(k > ptraverse->lcount)
			{
				k=k-(ptraverse->lcount+1);
				ptraverse=ptraverse->right;
			}
			else
			{
				ptraverse=ptraverse->left;
			}
		}
	}
	return ret;
}
int main(void) 
{ 
    /* just add elements to test */
    /* NOTE: A sorted array results in skewed tree */
    int ele[] = { 20, 8, 22, 4, 12, 10, 14 }; 
    int i; 
    node *root = NULL; 
  
    /* Creating the tree given in the above diagram */
    root = binary_search_tree(root, ele, 7); 
  
    /*  It should print the sorted array */
    for(i = 1; i <=7; i++) 
    { 
        cout<<k_smallest_element(root, i)<<" "; 
    } 
    return 0; 
}
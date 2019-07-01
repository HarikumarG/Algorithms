#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
  TreeNode *left;
  TreeNode *right;
  int data;
};
void printlevelorder(TreeNode *root)
{
	if(root == NULL)
		return ;
	queue<TreeNode *>q;
	q.push(root);
	while(q.empty()==false)
	{
		TreeNode *node=q.front();
		cout<<node->data<<" ";
		q.pop();
		if(node->left)
			q.push(node->left);
		if(node->right)
			q.push(node->right);
	}
}
struct TreeNode* newNode(int data) 
{ 
  struct TreeNode* node = (struct TreeNode*) 
  malloc(sizeof(struct TreeNode)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return(node); 
} 
int main() 
{ 
  struct TreeNode *root = newNode(1); 
  root->left        = newNode(2); 
  /*root->right       = newNode(20); 
  root->right->left=newNode(15);  
  root->right->right=newNode(7);  
  */
  printlevelorder(root);
  return 0; 
}   
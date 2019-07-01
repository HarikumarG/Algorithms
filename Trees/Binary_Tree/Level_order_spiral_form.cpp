#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
	TreeNode *left;
	TreeNode *right;
	int data;
};
void printspiralorder(TreeNode *root)
{
	if(root==NULL)
		return ;
	stack<TreeNode *>s1;
	stack<TreeNode *>s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			TreeNode *temp=s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			if(temp->right)
				s2.push(temp->right);
			if(temp->left)
				s2.push(temp->left);
		}
		while(!s2.empty())
		{
			TreeNode *tem=s2.top();
			s2.pop();
			cout<<tem->data<<" ";
			if(tem->left)
				s1.push(tem->left);
			if(tem->right)
				s1.push(tem->right);
		}
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
  root->left = newNode(2); 
  root->right = newNode(3); 
  root->left->left = newNode(7); 
  root->left->right = newNode(6); 
  root->right->left = newNode(5); 
  root->right->right = newNode(4); 
  printspiralorder(root);
  return 0; 
}   
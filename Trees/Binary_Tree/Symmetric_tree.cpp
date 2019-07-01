#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
	TreeNode *left;
	TreeNode *right;
	int val;
};
struct TreeNode* newNode(int data) 
{ 
	struct TreeNode* node = (struct TreeNode*) 
	malloc(sizeof(struct TreeNode)); 
	node->val = data; 
	node->left = NULL; 
	node->right = NULL; 

	return(node); 
} 
bool isMirror(TreeNode *root1,TreeNode *root2)
{
	if(!root1 && !root2)
		return true;
	if(!root1 || !root2)
		return false;
	return (root1->val == root2->val) && isMirror(root1->right,root2->left) &&                      isMirror(root1->left,root2->right);
}
bool symmetric(TreeNode* root) {
	return isMirror(root,root);
}
int main() 
{ 
	struct TreeNode *root = newNode(1); 
	root->left        = newNode(2); 
	root->right       = newNode(2); 
	root->left->left=newNode(3);  
	root->left->right=newNode(4);  
	root->right->left=newNode(4);
	root->right->right=newNode(3);
	cout<<symmetric(root);
	return 0; 
}   
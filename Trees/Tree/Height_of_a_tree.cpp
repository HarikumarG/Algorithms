#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
  TreeNode *left;
  TreeNode *right;
  int data;
};

int maxDepth(TreeNode* root)    
{

  int lh=0;
  int rh=0;

  queue<TreeNode *>q;

  if(root == NULL)
    return 0;
  else
  {
    while(root)
    {
      if(root->left)
      {
        q.push(root->left);
        lh++;
      }
      if(root->right)
      {
        q.push(root->right);
        rh++;
      }
      root=q.front();
      q.pop();
    }
    if(lh >= rh)
      return lh;
    else
      return rh;
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
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5);
  root->left->right->right=newNode(6);  
  
  cout<<maxDepth(root);
  return 0; 
}   
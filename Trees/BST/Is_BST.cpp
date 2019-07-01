#include <bits/stdc++.h> 
using namespace std;

struct node 
{ 
  int data; 
  struct node* left; 
  struct node* right; 
}; 

int isBSTUtil(struct node* node); 

int isBST(struct node* node)  
{  
  return(isBSTUtil(node));  
}  

/* Returns true if the given tree is a BST and its  
   values are >= min and <= max. */ 
int isBSTUtil(struct node* root)  
{  
  stack<node *> s;
  int inorder=INT_MIN;
  while(!s.empty() || root != NULL)
  {
    while(root!=NULL)
    {
      s.push(root);
      root=root->left;
    }
    root =  s.top();
    s.pop();
    if(root->data <= inorder)
      return false;
    inorder=root->data;
    root=root->right;
  }
  return true;
}  

struct node* newNode(int data) 
{ 
  struct node* node = (struct node*) 
  malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return(node); 
} 

int main() 
{ 
  struct node *root = newNode(4); 
  root->left        = newNode(2); 
  root->right       = newNode(5); 
  root->left->left  = newNode(1); 
  root->left->right = newNode(6);  
  
  if(isBST(root)) 
    printf("Is BST"); 
  else
    printf("Not a BST"); 

  getchar(); 
  return 0; 
}   
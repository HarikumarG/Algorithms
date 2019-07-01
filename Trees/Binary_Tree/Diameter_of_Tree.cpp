#include<bits/stdc++.h>
using namespace std;
struct Node 
{
	int data;
	Node *left;
	Node *right;
};
Node *newNode(int d)
{
	Node *temp = new Node;
	temp->data = d;
	temp->left = temp->right = NULL;
	return temp;
}
int height(Node* root, int& ans) 
{ 
    if (root == NULL) 
        return 0; 
  
    int left_height = height(root->left, ans); 
  
    int right_height = height(root->right, ans); 
  
    // update the answer, because diameter of a 
    // tree is nothing but maximum value of 
    // (left_height + right_height + 1) for each node 
    ans = max(ans, 1 + left_height + right_height); 
  
    return 1 + max(left_height, right_height); 
} 
  
/* Computes the diameter of binary tree with given root. */
int diameter(Node* root) 
{ 
    if (root == NULL) 
        return 0; 
    int ans = INT_MIN; // This will store the final answer 
    int height_of_tree = height(root, ans); 
    return ans; 
} 
int main()
{
	struct Node *root = newNode(1); 
  	root->left        = newNode(2); 
  	root->right       = newNode(3); 
  	root->left->left  = newNode(4); 
  	root->left->right = newNode(5); 
  	cout<<"Diameter of the given binary tree is "<<diameter(root); 
  	return 0; 
}

#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};
TreeNode *findLCAUtil(TreeNode *root,TreeNode *p,TreeNode *q,bool &v1,bool &v2)
{
	if(root ==  NULL)
		return NULL;
	if(root->val == p->val)
	{
		v1=true;
		return root;
	}
	if(root->val == q->val)
	{
		v2=true;
		return root;
	}
	TreeNode *leftlca = findLCAUtil(root->left,p,q,v1,v2);
	TreeNode *rightlca = findLCAUtil(root->right,p,q,v1,v2);
	
	if(leftlca && rightlca)
		return root;
	return (leftlca != NULL)?leftlca : rightlca;
}
bool find(TreeNode *root,TreeNode *k)
{
	if(root == NULL)
		return false;
	if(root->val == k->val || find(root->left,k) || find(root->right,k))
		return true;
	return false;
}
TreeNode *findLCA(TreeNode *root,TreeNode *p,TreeNode *q)
{
	if(p == NULL || q == NULL)
		return NULL;
	bool v1=false,v2=false;
	TreeNode *lca = findLCAUtil(root,p,q,v1,v2);
	
	if(v1 && v2 || v1 && find(lca,q) || v2 && find(lca,p))
		return lca;
	return NULL;
}
TreeNode *newNode(int data)
{
	TreeNode* temp=new TreeNode;
	temp->val = data;
	temp->left = temp->right = NULL;
	return temp;
}
int main()
{
	TreeNode* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    TreeNode *lca =  findLCA(root,root->left->left,root->left->right); 
    if (lca != NULL) 
       cout << "LCA(4, 5) = " << lca->val; 
    else
       cout << "Keys are not present "; 
  
    lca =  findLCA(root,root->left->left,NULL); 
    if (lca != NULL) 
       cout << "\nLCA(4, 10) = " << lca->val; 
    else
       cout << "\nKeys are not present "; 
  
    return 0; 
}

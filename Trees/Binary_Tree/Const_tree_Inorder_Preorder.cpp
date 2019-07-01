#include<bits/stdc++.h>
using namespace std;
struct Node
{
	char data;
	Node *left;
	Node *right;
};
Node *newnode(char curr)
{
	Node *temp = new Node;
	temp->data = curr;
	temp->left = temp->right = NULL;
	return temp;
}
Node *buildTree(char pre[],int instrt,int inend,map<char,int>&mp)
{
	static int preind=0;
	if(instrt > inend)
		return NULL;
	char curr = pre[preind++];
	Node *tnode = newnode(curr);
	if(instrt == inend)
		return tnode;
	
	int inIndex = mp[curr];
	
	tnode->left = buildTree(pre,instrt,inIndex-1,mp);
	tnode->right =buildTree(pre,inIndex+1,inend,mp);
	
	return tnode;
	
}
Node *buildTreeWrap(char in[],char pre[],int len)
{
	map<char ,int >mp;
	for(int i=0;i<len;i++)
	{
		mp[in[i]]=i;
	}	
	return buildTree(pre,0,len-1,mp);
}
void printInorder(Node *root)
{
	if(root != NULL)
	{
		printInorder(root->left);
		cout<<root->data<<" ";
		printInorder(root->right);
	}
}
int main()
{
	char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 
    int len = sizeof(in) / sizeof(in[0]); 
  
    struct Node* root = buildTreeWrap(in, pre, len); 
  
    /* Let us test the built tree by printing  
      Insorder traversal */
    printf("Inorder traversal of the constructed tree is \n"); 
    printInorder(root); 
    return 0;
}

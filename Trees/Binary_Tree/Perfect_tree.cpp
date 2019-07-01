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
	temp->left=temp->right=NULL;
	return temp;
}
bool isPerfect(Node *root)
{
	if(root == NULL)
		return true;
	queue<Node*>q;
	q.push(root);
	int size;
	while(!q.empty())
	{
		size = q.size();
		while(size > 0)
		{
			Node *temp = q.front();
			q.pop();
			if(temp->left && !temp->right || temp->right && !temp->left)
			{
				return false;
			}
			if(temp->left && temp->right)	
			{
				q.push(temp->left);
				q.push(temp->right);
			}	
			size--;
		}
	}
	return true;
}
int main()
{
	struct Node* root = NULL; 
    root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
  
    root->left->left = newNode(40); 
    root->left->right = newNode(50); 
    root->right->left = newNode(60); 
    root->right->right = newNode(70); 
  
    if (isPerfect(root)) 
        cout<<"Yes\n";
    else
        cout<<"No\n";
  
    return 0; 
}

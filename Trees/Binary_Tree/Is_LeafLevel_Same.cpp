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
int checkLevelLeafNode(Node *root,int level,int *result)
{
	if(root == NULL)	
		return 1;
	
	if(root->left == NULL && root->right == NULL)
	{
		if(*result == 0)
		{
			*result = level;
			return 1;
		}
		if(*result == level)
			return 1;
	}
	return checkLevelLeafNode(root->left,level+1,result) && checkLevelLeafNode(root->right,level+1,result);
}
int checkLevelLeafNodeIterative(Node *root)
{
    if (!root) 
        return 1; 
        
	queue<Node*>q;
	int size;
	int result = INT_MAX,level=0;
	q.push(root);
	while(!q.empty())
	{
		size = q.size();
		level = level+1;
		while(size > 0)
		{
			Node *temp = q.front();
			q.pop();
			if(temp->left)
			{
				q.push(temp->left);
				if(!temp->left->right && !temp->left->left)
				{
					if(result == INT_MAX)
						result = level;
					else if(level !=result)
						return 0;
				}
			}
			if(temp->right)
			{
				q.push(temp->right);
				if(!temp->right->right && !temp->right->left)
				{
					if(result == INT_MAX)
						result = level;
					else if(level != result)
						return 0;
				}
			}
			size--;
		}
	}
	return 1;
}
int main()
{
	Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left = newNode(5); 
    root->right->right = newNode(6); 
   
    int result = checkLevelLeafNodeIterative(root); 
    if (result) 
        cout << "All leaf nodes are at same level\n"; 
    else
        cout << "Leaf nodes not at same level\n"; 
    
    //recursive
    int res = 0;
	int result1 = checkLevelLeafNode(root,0,&res); 
    if (result1) 
        cout << "All leaf nodes are at same level\n"; 
    else
        cout << "Leaf nodes not at same level\n"; 
    
    return 0; 
}

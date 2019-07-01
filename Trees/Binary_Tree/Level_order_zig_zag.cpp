#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
	TreeNode *left;
	TreeNode *right;
	int val;
};
TreeNode* newNode(int data)
{
	TreeNode* temp = new TreeNode;
	temp->val=data;
	temp->right = temp->left = NULL;
	return temp;
}
vector<vector<int> > ZigZagLevelOrder(TreeNode *root)
{
	vector<std::vector<int> > res;
	if(root == NULL)
		return res;
	vector<int> temp;
	if(root->left == NULL && root->right == NULL)
	{
		temp.push_back(root->val);
		res.push_back(temp);
		return res;
	}
	stack<TreeNode *> s;
	queue<TreeNode *> q;
	TreeNode* node=NULL;
	bool righttoleft=false;
	q.push(root);
	while(!q.empty())
	{
		int sz=q.size();
		for(int i=0;i<sz;i++)
		{
			node = q.front();
			q.pop();
			if(righttoleft == false)
			{
				temp.push_back(node->val);		
			}
			else
			{	
				s.push(node);
			}
			if(node->left)
				q.push(node->left);
			if(node->right)
				q.push(node->right);
		}	
		if(righttoleft ==  true)
		{
			while(!s.empty())
			{
				node = s.top();
				s.pop();
				temp.push_back(node->val);
			}
		}
		righttoleft = !righttoleft;
		res.push_back(temp);
		temp.clear();
	}
	return res;
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
    root->left->left->left = newNode(8); 
    root->left->left->right = newNode(9); 
    root->left->right->left = newNode(3); 
    root->left->right->right = newNode(1); 
    root->right->left->left = newNode(4); 
    root->right->left->right = newNode(2); 
    root->right->right->left = newNode(7); 
    root->right->right->right = newNode(2); 
    root->left->right->left->left = newNode(16); 
    root->left->right->left->right = newNode(17); 
    root->right->left->right->left = newNode(18); 
    root->right->right->left->right = newNode(19); 
  	
  	vector<std::vector<int> > res;
    res = ZigZagLevelOrder(root); 
    for(int i=0;i<res.size();i++)
    {
    	for(int j=0;j<res[i].size();j++)
    	{
    		cout<<res[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

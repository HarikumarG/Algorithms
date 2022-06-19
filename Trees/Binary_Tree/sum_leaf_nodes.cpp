#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
	int val;
	struct Node* left;
	struct Node* right;
};

Node* insert(int key) {
	struct Node* newNode = new Node();
	newNode->val = key;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void sumNodes(Node* root, int &sum) {
	if(!root)
		return;
	if(!root->left && !root->right)
		sum += root->val;
	sumNodes(root->left, sum);
	sumNodes(root->right, sum);
}

int main() {
	struct Node* root = NULL;
	root = insert(1);
	root->left = insert(2);
	root->right = insert(3);
	root->left->left = insert(4);
	root->left->right = insert(5);
	root->right->left = insert(6);
	root->right->right = insert(7);
	root->right->left->right = insert(8);
	int sum = 0;
	sumNodes(root, sum);
	cout<<sum<<endl;
	return 0;
}
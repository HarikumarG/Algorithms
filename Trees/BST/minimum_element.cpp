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

void inorder(Node* root) {
	if(!root)
		return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

int minElement(Node* root) {
	if(!root)
		return -1;
	if(!root->left)
		return root->val;
	return minElement(root->left);
}

int main() {
	struct Node* root = NULL;
	root = insert(5);
	root->left = insert(4);
	root->right = insert(6);
	root->left->left = insert(3);
	root->right->right = insert(7);
	root->left->left->left = insert(1);
	
	cout<<minElement(root);
	cout<<endl;	
	root = NULL;

	root = insert(9);
	root->right = insert(10);
	root->right->right = insert(11);

	cout<<minElement(root);
	cout<<endl;
	return 0;
}
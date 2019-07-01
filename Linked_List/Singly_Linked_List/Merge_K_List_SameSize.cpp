#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
void printList(Node *head)
{
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
}
Node *SortedMergeList(Node *a,Node *b)
{
	Node *result = NULL;
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	if(a->data <= b->data)
	{
		result = a;
		result->next = SortedMergeList(a->next , b);
	}
	else
	{
		result = b;
		result->next = SortedMergeList(a , b->next);
	}
	return result;
}
Node *mergeKLists(Node *a[],int last)
{
	 // repeat until only one list is left 
	while(last != 0)
	{
		int i=0,j=last;
		while(i < j)
		{
			// merge List i with List j and store 
            // merged list in List i 
			a[i] = SortedMergeList(a[i],a[j]);
			i++;
			j--;
			 // If all pairs are merged, update last 
			if(i >= j)
				last = j;
		}
	}
	return a[0];
}
Node *newNode(int d)
{
	Node *temp = new Node;
	temp->data = d;
	temp->next = NULL;
	return temp;
}
int main()
{
	int k = 3; // Number of linked lists 
    int n = 4; // Number of elements in each list 
  
    // an array of pointers storing the head nodes 
    // of the linked lists 
    Node* arr[k]; 
  
    arr[0] = newNode(1); 
    arr[0]->next = newNode(3); 
    arr[0]->next->next = newNode(5); 
    arr[0]->next->next->next = newNode(7); 
  
    arr[1] = newNode(2); 
    arr[1]->next = newNode(4); 
    arr[1]->next->next = newNode(6); 
    arr[1]->next->next->next = newNode(8); 
  
    arr[2] = newNode(0); 
    arr[2]->next = newNode(9); 
    arr[2]->next->next = newNode(10); 
    arr[2]->next->next->next = newNode(11); 
  
    // Merge all lists 
    Node* head = mergeKLists(arr, k - 1); 
  
    printList(head); 
}

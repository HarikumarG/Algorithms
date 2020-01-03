#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;	
};
void PrintList(ListNode *head)
{
	ListNode *trav = head;
	while(trav != NULL)
	{
		cout<<trav->val<<" ";
		trav = trav->next;
	}
	cout<<endl;
}
int count(ListNode *head)
{
	ListNode *trav = head;
	int c = 0;
	while(trav != NULL)
	{
		c++;
		trav = trav->next;
	}
	return c;
}
ListNode *newNode(int data)
{
	ListNode *node = new ListNode;
	node->next = NULL;
	node->val = data;
	return node;
}
ListNode *reverse(ListNode *head,int h)
{
	ListNode *trav = head;
	ListNode *p;
	while(h--)
	{
		trav = trav->next;
	}
	ListNode *curr = trav;
	ListNode *prev = NULL;
	ListNode *next = NULL;
	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}
int main()
{
	ListNode *head = new ListNode;
	head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(6);
	ListNode *h = head;
	int c = count(head);
	int half = c/2;
	ListNode *rev = reverse(head,half);
	PrintList(rev);
	PrintList(h);
//	ListNode *n = NULL;
//	ListNode *r = NULL;
//	while(h != NULL && rev != NULL)
//	{
//		n = h->next;
//		r = rev->next;
//		h->next = rev;
//		rev->next = n;
//		h = n;
//		rev = r;
//	}
//	PrintList(h);
	return 0;
}

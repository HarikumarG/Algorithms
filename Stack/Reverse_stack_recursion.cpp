#include<bits/stdc++.h>
using namespace std;
struct sNode
{
	int data;
	sNode *next;
};
void push(sNode **topnode,int item)
{
	sNode *newnode = new sNode;
	if(newnode == NULL)
	{
		cout<<"\nStack overflow";
		exit(0);
	}
	newnode->data = item;
	newnode->next = (*topnode);
	(*topnode) = newnode;
}
int pop(sNode **topnode)
{
	sNode *top;
	int d;
	if((*topnode) == NULL)
	{
		cout<<"\nStack overflow";
		exit(0);
	}
	top = (*topnode);
	d = top->data;
	(*topnode) = top->next;
	free(top);
	return d;
}
bool isEmpty(sNode *topnode)
{
	return (topnode == NULL)? 1:0;
}
void print(sNode *trav)
{
	cout<<"\n";
	while(trav != NULL)
	{
		cout<<trav->data<<" ";
		trav = trav->next;
	}
}
void insertAtBottom(sNode **topnode,int item)
{
	if(isEmpty(*topnode))
	{
		push(topnode,item);
	}
	else
	{
		 // Hold all items in Function Call
        // Stack until we reach end of the
        // stack. When the stack becomes
        // empty, the isEmpty(*top_ref)becomes
        // true, the above if part is executed
        // and the item is inserted at the bottom 
		int temp = pop(topnode);
		insertAtBottom(topnode,item);
		 // Once the item is inserted 
        // at the bottom, push all
        // the items held in Function 
        // Call Stack 
		push(topnode,temp);
	}
}
void reverse(sNode **topnode)
{
	if(!isEmpty(*topnode))
	{
		 // Hold all items in Function 
        // Call Stack until we
        // reach end of the stack 
		int temp = pop(topnode);
		reverse(topnode);
		// Insert all the items (held in 
        // Function Call Stack)
        // one by one from the bottom 
        // to top. Every item is
        // inserted at the bottom 
		insertAtBottom(topnode,temp);
	}
}
int main()
{
	sNode *s = NULL;
	push(&s, 4);
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);
 	cout<<"\n Original Stack ";
    print(s);
    reverse(&s);
    cout<<"\n Reversed Stack ";
    print(s);
    return 0;
}
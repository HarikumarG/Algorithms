#include<bits/stdc++.h>
using namespace std;
struct DLLnode
{
	int data;
	DLLnode *prev;
	DLLnode *next;
};
struct mystack
{
	int count;
	DLLnode *mid;
	DLLnode *head;
};
mystack *createstack()
{
	mystack *ms = new mystack;
	ms->count = 0;
	return ms;
}
void push(mystack *ms,int d)
{
	DLLnode *newnode= new DLLnode;
	newnode->data=d;
	newnode->prev = NULL;
	newnode->next= ms->head;
	ms->count += 1;
	if(ms->count == 1)
	{
		ms->mid = newnode;
	}
	else
	{
		ms->head->prev = newnode;
		if( ms->count & 1)		// Update mid if ms->count is odd
		{
			ms->mid = ms->mid->prev;
		}
	}
	ms->head= newnode;
}
int pop(mystack *ms)
{
	if(ms->count == 0)
	{
		cout<<"The stack is empty";
		return -1;
	}
	DLLnode *head1 = ms->head;
	int d= head1->data;
	ms->head = head1->next;
	if(ms->head != NULL)
	{
		ms->head->prev = NULL;
	}
	ms->count -= 1;
	if(!(ms->count & 1))  // update the mid pointer when we have even number of elements in the stack, 
	{						//i,e move down the mid pointer.				
		ms->mid = ms->mid->next;
	}
	free(head1);
	return d;
}
int middle(mystack *ms)
{
	if(ms->count == 0)
	{
		cout<<"\nThe stack is empty";
		return -1;
	}
	return ms->mid->data;
}
int main()
{
	mystack *ms= createstack();
	push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);
    cout<<"\nThe popped element is "<<pop(ms);
    cout<<"\nThe popped element is "<<pop(ms);
    cout<<"\nThe middle element is "<<middle(ms);
    return 0;
}
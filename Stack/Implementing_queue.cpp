#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct sNode
{
	int data;
	 sNode *next;
};
struct Queue
{
	sNode *stack1;
    sNode *stack2;
};
void push(sNode **top_node,int d)
{
	sNode *newnode=new sNode;
	if(newnode==NULL)
	{
		cout<<"Stack overflow";
	}
	newnode->data=d;
	newnode->next=(*top_node);
	(*top_node)=newnode;
}
int pop(sNode **top_node)
{
	int d;
    sNode *top=NULL;
	if((*top_node)==NULL)
	{
		cout<<"Stack underflow";
	}
	else
	{
		top=*top_node;
		d=top->data;
		*top_node=top->next;
		free(top);
		return d;
	}
}
void enqueue(Queue *q,int d)
{
	push(&q->stack1,d);
}
int dequeue(Queue *q)
{
	int d;
	if(q->stack1 ==NULL && q->stack2 == NULL)
	{
		cout<<"Q is empty";
	}
	if(q->stack2 == NULL)
	{
		while(q->stack1 !=NULL)
		{
			d=pop(&q->stack1);
			push(&q->stack2,d);
		}
	}
	d=pop(&q->stack2);
	return d;
}
int main()
{
    Queue *q=new Queue;
	q->stack1=NULL;
	q->stack2=NULL;
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
	cout<<dequeue(q);
	cout<<dequeue(q);
	cout<<dequeue(q);
	return 0;
}

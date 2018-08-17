#include<bits/stdc++.h>
using namespace std;
struct Stacks
{
	unsigned capacity;
	int top;
	int *array;
};
Stacks *createstack(unsigned Capacity)
{
	struct Stacks *stack = (struct Stacks*)malloc(sizeof(struct Stacks));
	stack->capacity = Capacity;
	stack->top = -1;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));
	return stack;
}
int isfull(Stacks *stack)
{
	return (stack->top == stack->capacity-1);
}
int isempty(Stacks *stack)
{
	return (stack->top == -1);
}
void push(Stacks *stack,int item)
{
	if(isfull(stack))
		return;
	stack->array[++stack->top] = item;
}
int pop(Stacks *stack)
{
	int Int_min = -999;
	if(isempty(stack))
	{
		return Int_min;
	}
	else
		return stack->array[stack->top--];
}
void movedisks(char from , char to,int disk)
{
	cout<<"\nMove disk "<<disk<<" from "<<from<<" to "<<to;
}
void movediskbetweenpoles(Stacks *src,Stacks *des,char s,char d)
{
	int Int_min = -999;
	int pole1top=pop(src);
	int pole2top=pop(des);
	if(pole1top == Int_min)	// When pole 1 is empty
	{
		push(src,pole2top);
		movedisks(d,s,pole2top);
	}
	else if(pole2top == Int_min) // When pole 2 is empty
	{
		push(des,pole1top);
		movedisks(s,d,pole1top);
	}
	else if(pole1top > pole2top) // When top disk of pole1 > top disk of pole2
	{
		push(src,pole1top);
		push(src,pole2top);
		movedisks(d,s,pole2top);
	}
	else						// When top disk of pole1 < top disk of pole2
	{
		push(des,pole2top);
		push(des,pole1top);
		movedisks(s,d,pole1top);
	}
}
void toiterate(int noofdisks,Stacks *src,Stacks *aux,Stacks *des)
{	
	int i,moves;
	char s ='S',a = 'A',d = 'D';
	//If number of disks is even, then interchange
    //destination pole and auxiliary pole
	if(noofdisks%2 == 0)
	{
		char temp=d;
		d=a;
		a=temp;
	}
	moves = pow(2,noofdisks)-1;
	for(i=noofdisks;i>=1;i--)  //Larger disks will be pushed first
	{
		push(src,i);
	}
	for(i=1;i<=moves;i++)
	{
		if(i%3 == 1)
		{
			movediskbetweenpoles(src,des,s,d);
		}
		else if(i%3 == 2)
		{
			movediskbetweenpoles(src,aux,s,a);
		}
		else if(i%3 == 0)
		{
			movediskbetweenpoles(aux,des,a,d);
		}
	}
}
int main()
{
	unsigned noofdisks=3;
	Stacks *src,*des,*aux;
	src = createstack(noofdisks);
	des = createstack(noofdisks);
	aux = createstack(noofdisks);
	toiterate(noofdisks,src,aux,des);
	return 0;
}
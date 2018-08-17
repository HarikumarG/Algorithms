#include<bits/stdc++.h>
using namespace std;
struct Stack
{
	int top;
	unsigned capacity;
	int *array;
};
Stack *createstack(unsigned cap)
{
	Stack *st = new Stack;
	st->top=-1;
	st->capacity=cap;
	st->array=(int*)malloc(st->capacity * sizeof(int));
	return st;
}
int isEmpty(Stack *st)
{
	return st->top==-1;
}
char peek(Stack *st)
{
	return st->array[st->top];
}
char pop(Stack *st)
{
	if(!isEmpty(st))
	{
		return st->array[st->top--];
	}
}
void push(Stack *st,char op)
{
	st->array[++st->top] = op;
}
int operand(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int prec(char ch)
{
	switch(ch)
	{
		case '+' :
		case '-' :
			return 1;
		case '*' :
		case '/' :
			return 2;
		case '^' :
			return 3;
		default : return -1;
	}
}
int infixToPostfix(char *exp)
{
	int i,k;
	Stack *stacks = createstack(strlen(exp));
	for(i=0,k=-1;exp[i];i++)
	{
		if(operand(exp[i]))
		{
			exp[++k]=exp[i];
		}
		else if(exp[i] == '(')
		{
			push(stacks,exp[i]);
		}
		else if(exp[i] == ')')
		{
			while(!isEmpty(stacks) && peek(stacks) != '(')
				exp[++k] = pop(stacks);
			if(!isEmpty(stacks) && peek(stacks)!='(')
				return -1;
			else
				pop(stacks);
		}
		else
		{
			while(!isEmpty(stacks) && prec(exp[i]) <= prec(peek(stacks)))
			{
				exp[++k] = pop(stacks);
			}
			push(stacks,exp[i]);
		}
	}
	while(!isEmpty(stacks))
		exp[++k] = pop(stacks);
	exp[++k] = '\0';
	cout<<"\n"<<exp;
}
int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}


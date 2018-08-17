#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class twostacks
{
	int *arr;
	int size;
	int top1,top2;
public:
	twostacks(int n)
	{
		size=n;
		arr = new int[n];
		top1=-1;
		top2=size;
	}

	void push1(int n)
	{
		if(top1<top2-1)  // There is at least one empty space for new element
		{
			top1++;
			arr[top1]=n;
		}
		else
		{
			cout<<"Stack overflow";
			exit(1);
		}
	}
	void push2(int n)
	{
		if(top1<top2-1) // There is at least one empty space for new element
		{
			top2--;
			arr[top2]=n;
		}
		else
		{
			cout<<"Stack overflow";
			exit(1);	
		}
	}
	int pop1()
	{
		int d;
		if(top1>=0)
		{
			d=arr[top1];
			top1--;
			return d;
		}
		else
		{
			cout<<"Stack underflow";
			exit(1);
		}
	}
	int pop2()
	{
		int d;
		if(top2<size)
		{
			d=arr[top2];
			top2++;
			return d;
		}
		else
		{
			cout<<"Stack underflow";
			exit(1);
		}
	}
};
int main()
{
	twostacks ts(5);
	ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(12);
    ts.push2(7);
    cout << "Popped element from stack1 is " << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is " << ts.pop2();
    return 0;
}
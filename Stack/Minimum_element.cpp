#include<bits/stdc++.h>
using namespace std;
struct MyStack
{
	stack<int> s;
	int min;
	void push(int x)
	{
		if(s.empty())
		{
			min=x;
			s.push(x);
			cout<<"\nThe number inserted is "<<x;
		}
		else
		{
			if(x<min)
			{
				s.push(2*x - min);
				min=x;
			}
			else
			{
				s.push(x);
			}
			cout<<"\nThe number inserted is "<<x;
		}
	}
	void peek()
	{
		if(s.empty())
		{
			cout<<"\nThe stack is empty";
		}
		else
		{
			int t=s.top();
			if(t<min)
			{
				cout<<"\nThe top element is "<<min;
			}
			else
			{
				cout<<"\nThe top element is "<<t;
			}
		}
	}
	void pop()
	{
		if(s.empty())
		{
			cout<<"\nThe stack is empty";
		}
		else
		{
			int t=s.top();
			s.pop();
			if(t<min)
			{
				cout<<"\nThe popped element is "<<min;
				min=2*min - t;
			}
			else
			{
				cout<<"\nThe popped element is "<<t;
			}
		}
	}
	void getMin()
	{
		if(s.empty())
		{
			cout<<"\nThe Stack is empty";
		}
		else
		{
			cout<<"\nThe Minimum element is "<<min;
		}
	}
};
int main()
{
	 MyStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();
 	return 0;
}
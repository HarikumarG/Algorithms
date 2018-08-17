#include<bits/stdc++.h>
using namespace std;
stack<int> sortstack(stack<int> input)
{
	stack<int> tempstack;
	while(!input.empty())
	{
		 // pop out the first element
		int temp=input.top();
		input.pop();
		// while temporary stack is not empty and top
        // of stack is greater than temp
		while(!tempstack.empty() && temp<tempstack.top())
		{
			// pop from temporary stack and push
            // it to the input stack
			input.push(tempstack.top());
			tempstack.pop();
		}
		tempstack.push(temp);	// push temp in tempory of stack
	}
	return tempstack;
}
int main()
{
	stack<int> input;
	input.push(34);
    input.push(3);
    input.push(31);
    input.push(98);
    input.push(92);
    input.push(23);
    stack<int> tempstack= sortstack(input);
    while(!tempstack.empty())
    {
    	cout<<tempstack.top()<<" ";
    	tempstack.pop();
    }
    return 0;
}
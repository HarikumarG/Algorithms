#include <iostream>
#include <stack>
using namespace	std;

void reverseStack(stack<int> st) {
	if(st.empty())
		return;

	int val = st.top();
	st.pop();
	reverseStack(st);
	cout<<val<<" ";
}

int main() {
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	reverseStack(st);
	return 0;
}
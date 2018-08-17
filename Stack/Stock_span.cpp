#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
}
void calculateSpan(int price[], int n, int S[])
{
	stack<int> st;
	st.push(0);
	S[0]=1;		// Span value of first element is always 1
	for(int i=1;i<n;i++)
	{
		  // Pop elements from stack while stack is not empty and top of
    	  // stack is smaller than price[i]
    	while(!st.empty() && price[st.top()] <= price[i])
		{
			st.pop();
		}
		// If stack becomes empty, then price[i] is greater than all elements
      // on left of it, i.e., price[0], price[1],..price[i-1].  Else price[i]
      // is greater than elements after top of stack
		S[i] = (st.empty()) ? (i+1) : (i-st.top());
		st.push(i);
	}
}
int main()
{
	int price[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(price)/sizeof(price[0]);
    int S[n];
 
    // Fill the span values in array S[]
    calculateSpan(price, n, S);
 
    // print the calculated span values
    printArray(S, n);
 
    return 0;
}
 
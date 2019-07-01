#include<bits/stdc++.h>
using namespace std;
int findMaxLen(string str)
{
	int n = str.length();
	if(n == 0)
		return 0;
	stack<int>s;
	s.push(-1);
	int result = 0;
	for(int i=0;i<n;i++)
	{
		// If opening bracket, push index of it 
		if(str[i] == '(')
			s.push(i);
		else // If closing bracket, i.e.,str[i] = ')'
		{
			s.pop();
			// Check if this length formed with base of 
            // current valid substring is more than max  
            // so far 
			if(!s.empty())
				result = max(result,i-s.top());
			else
				s.push(i);
			
		}
	}
	return result;
}
int main()
{
	string str = "((()()"; 
    cout << findMaxLen(str) << endl; 
  
    str = "()(()))))"; 
    cout << findMaxLen(str) << endl ; 
  
    return 0; 
}

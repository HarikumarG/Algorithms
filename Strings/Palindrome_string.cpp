#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s1[10];
	int j=0,flag=1;
	cout<<"Enter a string\n";
	cin>>s1;
	int i=strlen(s1)-1;
	while(i>j)
	{
		if(s1[j++] != s1[i--])
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		cout<<"Palindrome";
	}
	else
	{
		cout<<"Not Palindrome";
	}
	return 0;
}
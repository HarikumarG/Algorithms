#include<bits/stdc++.h>
using namespace std;
int subs(char s1, string s2) 
{ 
	
		return -1; 
} 
	int main()
	{
/*	vector<int>my;
	my.push_back(1);
	my.push_back(2);
	vector<int>::iterator it;
	it=0;
	my.erase(it);*/

		string s="abcabc";
		string s2;
		int len=0;
		for(int i=0;i<s.length();i++)
		{
			s2=s[i];
			for(int j=i+1;j<s.length();j++)
			{
				if(subs(s[j],s2)!=-1)
				{
					s2=s2+s[j];
					if(len < s2.length())
						len=s2.length();
				}
				else
					break;
			}
			s2="\0";
		}
		cout<<len;
		return 0;
	}

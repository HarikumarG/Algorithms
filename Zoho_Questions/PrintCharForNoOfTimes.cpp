//Eg 1: Input: a1b10
//       Output: abbbbbbbbbb
//Eg: 2: Input: b3c6d15
//          Output: bbbccccccddddddddddddddd
//The number varies from 1 to 99.
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s="b3c6d15a1";
	int i=0;
	char c;
	while(i < s.length())
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			c = s[i];	
		}
		else
		{
			int v=s[i] - '0';
			if(s[i+1] != '\0')
			{
				if(s[i+1] >= 'a' && s[i+1] <= 'z')
				{
					while(v!=0)
					{
						cout<<c;
						v--;
					}	
				}
				else
				{	
					int u = s[i+1] - '0';
					v = v*10 + u;
					while(v!=0)
					{
						cout<<c;
						v--;
					}	
					i++;
				}
			}
			else
			{
				while(v!=0)
				{
					cout<<c;
					v--;
				}	
			}
		}
		i++;
	}
	
	return 0;
}

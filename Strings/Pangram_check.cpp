#include<bits/stdc++.h>
using namespace std;
bool checkpangram(char str[])
{
	vector<bool> mark(26,false);
	int index,flag=1;
	for(int i=0;i<strlen(str);i++)
	{
		if('A' <= str[i] && str[i] <= 'Z')
		{
			index=str[i]-'A';
		}
		else if('a' <= str[i] && str[i] <= 'z')
		{
			index=str[i]-'a';
		}
		mark[index]=true;
	}
	for(int j=0;j<=25;j++)
	{
		if(mark[j]==false)
		{
			flag=0;
			cout<<(char)(j+'a');
		}
	}
	if(flag)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	char str[100]="The quick brown fox jumps over the dog";
	if(checkpangram(str)==true)
	{
		cout<<"\nIt is a pangram";
	}
	else
	{
		cout<<"\nIt is not a pangram";
	}
	return 0;
}
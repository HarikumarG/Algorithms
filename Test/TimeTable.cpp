#include<bits/stdc++.h>
using namespace std;
struct table
{
	vector<vector<string> >data{ {"0","0","0","0","0"},{"0","0","0","0","0"},{"0","0","0","0","0"},{"0","0","0","0","0"},{"0","0","0","0","0"}};
	vector<string> sub = {"m1","m2","m3","m4","s1","s2","s3"};
	vector<string> t = {"tm1","tm2","tm3","tm4","ts1","ts2","ts3"};
}s;
void print()
{
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cout<<s.data[i][j]<<" ";
		}
		cout<<endl;
	}
}
void generate()
{
	int k = 0;
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			s.data[i][j] = s.sub[k]+"-"+s.t[k];
			k++;
			if(k == 7)
				k = 0;
		}
	}
	print();
}
bool find(string c)
{
	for(int i = 0; i < s.t.size(); i++)
	{
		if(c == s.t[i])
		{
			s.t[i] = "sm4";
			return true;	
		}
	}
	return false;
}
void absent()
{
	string c;
	cout<<"\nEnter the teacher id\n";
	cin>>c;
	if(find(c))
	{
		generate();
	}
	else
	{
		cout<<"The teacher id is not available\n";
	}
}
int main()
{
	while(1)
	{
		int ch;
		bool flag = false;
		cout<<"1 - Generate time table\n";
		cout<<"2 - Absent\n";
		cout<<"3 - Exit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1: generate();break;
			case 2: absent();break;
			case 3: flag = true;break;
			default: cout<<"Enter a right choice";break;
		}
		if(flag)
			break;
	}
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 5,v1=-1;
	int a[] = {1,4,2,3,7};
	vector<int>v;
	vector<int>::iterator it;
	priority_queue<int>bag;
	for(int i=0;i<n;i++)
	{
		if(bag.empty())
		{
			cout<<"-1 -1\n";		
			bag.push(a[i]);
		}
		else
		{
			while(!bag.empty())
			{
				int b = bag.top();
				if(a[i] > b)
				{
					cout<<b<<" "<<v1<<"\n";
					v1=-1;
					break;
				}
				else
				{
					bag.pop();
					v.push_back(b);
				}
				if(a[i] < b)
				{
					v1 = b;
				}
			}
			if(bag.empty())
				cout<<"-1 "<<v1<<"\n";
			if(!v.empty())
				for(it = v.begin();it!=v.end();it++)
					bag.push(*it);
			v.clear();
			bag.push(a[i]);
		}
	}
	return 0;
}

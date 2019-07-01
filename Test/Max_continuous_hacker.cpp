#include<bits/stdc++.h>
using namespace std;
int main()
{
	multimap<int, int> maps;
	maps.insert(pair<int,int>(1,0));
	maps.insert(pair<int,int>(2,1));
	maps.insert(pair<int,int>(3,1));
	maps.insert(pair<int,int>(4,1));
	maps.insert(pair<int,int>(5,1));
	maps.insert(pair<int,int>(6,0));
	map<int, int>:: iterator itr;
	int count=0;
	int max=0;
	vector<int> v;
	for(itr=maps.begin();itr != maps.end();itr++)
	{
		if(itr->second ==0)
		{
			count=0;
		}
		else
		{
			if(find(v.begin(),v.end(),itr->first) != v.end())
			{
				count--;
			}
			else
			{
				v.push_back(itr->first);
			}
			count++;
			max=count;
		}
	}
	cout<<max;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<int> merge(vector<vector<int> >arr)
{
	priority_queue <int> q;
	vector<int>out;
	for(int i=0;i<arr.size();i++)
	{
		for(int j=0;j<arr[i].size();j++)
		{
			q.push(arr[i][j]);
		}
	}
	while(!q.empty())
	{
		out.push_back(q.top());
		q.pop();
	}
	return out;
}
int main()
{
	vector<vector<int > >arr;
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	arr.push_back(v);
	v.clear();
	v.push_back(4);
	v.push_back(5);
	arr.push_back(v);
	v.clear();
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	arr.push_back(v);
	v.clear();
    vector<int>output = merge(arr);
    for(int i = 0;i<output.size();i++)
    {
    	cout<<output[i]<<" ";
	}
	return 0;
}

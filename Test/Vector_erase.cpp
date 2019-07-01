#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int>i;
	i.push_back(1);
	i.push_back(2);
	i.push_back(3);
	i.erase(i.begin()+i.size()-1);
	for(int j=0;j<i.size();j++)
		cout<<i[j]<<" ";
	return 0;
}
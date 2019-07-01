//if two freq are same then sort by increasing order
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	while(t--)
	{
		int n=37;
	    int a[]={1, 3, 7, 7, 7, 3, 2 ,2, 2, 7, 3, 1, 7, 1, 6,3, 5, 5, 4, 5, 6, 2, 1, 2, 4, 7, 3, 1, 3, 5 ,4, 1, 7, 2, 6 ,1 ,2};
	    map<int,int>freq;
	    for(int i=0;i<n;i++)
	    {
	        freq[a[i]]++;
	    }
	    map<int, int>:: iterator itr,itr1;
	    while(!freq.empty())
	    {
	    	int max=0;
	    	for(itr=freq.begin();itr!=freq.end();itr++)
	    	{
	    		if(itr->second > max)
	    		{
	    			max=itr->second;
	    			itr1=itr;
	    		}
	    	}
	    	int k=itr1->second;
	    	while(k--)
	    	{
	    		cout<<itr1->first<<" ";
	    	}
	    	freq.erase(itr1);
	    }
	}
	return 0;
}
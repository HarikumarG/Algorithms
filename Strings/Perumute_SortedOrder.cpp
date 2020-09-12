#include<bits/stdc++.h>
using namespace std;
int findceil(string str,char first,int l,int h)
{
	int ceilIndex = l;
	for(int i = l+1; i <= h; i++)
	{
		if(str[i] > first && str[i] < str[ceilIndex])
			ceilIndex = i;
	}
	return ceilIndex;
}
void reverse(string &a,int i,int j)
{
	while(i < j)
	{
		swap(a[i],a[j]);
		i++;
		j--;
	}
}
void sortedpermute(string str)
{
	int size = str.length();
	bool isFinished = false;
	while( !isFinished )
	{
		cout<<str<<endl;
		int i;
		for(i = size - 2; i >= 0; i--)
		{
			if(str[i] < str[i+1])
				break;
		}
		if(i == -1)
			isFinished = true;
		else
		{
			int ceilIndex = findceil(str,str[i],i+1,size-1);
			swap(str[i],str[ceilIndex]);
			reverse(str,i+1,size-1);
		}
	}

}
int main()
{
	//string should be sorted if not then sort the string
	string str = "123";
	sortedpermute(str);
	return 0;
}

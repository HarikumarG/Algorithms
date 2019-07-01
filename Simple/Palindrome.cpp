#include<bits/stdc++.h>
using namespace std;
int palindrome(int n,int rev)
{
	if(n==0)
		return rev;
	rev=rev*10;
	rev=rev+n%10;
	palindrome(n/10,rev);
}
int main()
{
	int n=12322;
	int m,r=0;
	m=palindrome(n,r);
	if(m==n)
	{
		cout<<"Palindrome";
	}
	else
	{
		cout<<"Not Palindrome";
	}
}
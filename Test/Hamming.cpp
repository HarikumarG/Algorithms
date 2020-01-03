#include<bits/stdc++.h>
using namespace std;
string bin(int n)
{
    string s;
    while(n >= 1)
    {
        int v = n % 2;
        ostringstream str1;
        str1 << v;
        string c = str1.str();
        s.insert(0,c);
        n = n/2;
    }
    return s;
}
int cald(int x,int y)
{
    string s1 = bin(x);
    string s2 = bin(y);
    int v = s1.length()-s2.length();
    if(v != 0)
    {
        if(v < 0)
        {
            v = abs(v);
            while(v != 0)
            {
                s1.insert(0,"0");
                v--;
            }
        }
        else
        {
            while(v != 0)
            {
                s2.insert(0,"0");
                v--;
            }
        }
    }
    int i=0,res=0;
    while(s1[i] != '\0')
    {
        if(s1[i] != s2[i])
            res++;
        i++;
    }
    return res;
}
int hammingDistance(vector<int> A) {
    
    int sum = 0;
    int n = A.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        	int val = cald(A[i],A[j]);
            sum = sum + val;
        }
    }
    return sum;
}
int main()
{
	vector<int>a;
	a.push_back(2);
	a.push_back(4);
	a.push_back(6);
	cout<<hammingDistance(a);
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define mod 1000003; // to return the ans in mod for string length if more

int fact(int n)
{
        if(n==0) return 1 ; else return (n*fact(n-1)) %mod;
}

int findRank(string A) {
    string s=A ;
    int ans =0;
    int n=s.length();
    for(int i=0;i<n-1;i++)
    {
        int c=0;
        for(int j=i+1;j<n;j++)
        {
            if(s[j]<s[i])
                c++;
        }   
        ans+=( (c*fact(n-i-1)) )%mod;
    }
    return (ans+1 )%mod;
}
int main()
{
    string a="cab";
    findRank(a);
    return 0;
}
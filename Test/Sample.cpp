#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void bin(ll n,string &res)
{
    if(n > 1)
        bin(n>>1,res);
    res += to_string(n & 1);
}
int countfreq(string &pat,string &txt)
{
    int M = pat.length(); 
	int N = txt.length(); 
	int res = 0; 
	
	for (int i = 0; i <= N - M; i++) 
	{ 
		int j; 
		for (j = 0; j < M; j++) 
			if (txt[i+j] != pat[j]) 
				break; 

		if (j == M) 
		{ 
    		res++; 
		} 
	} 
	return res; 
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int c = 0;
        ll r,k;
        cin>>r;
        cin>>k;
        for(ll i = 1; i <= r; i++)
        {
            string res;
            bin(i,res);
            string pat = "101";
            int val = countfreq(pat,res);
            if(val >= k)
                c++;
        }
        cout<<c<<"\n";
    }
    return 0;
}

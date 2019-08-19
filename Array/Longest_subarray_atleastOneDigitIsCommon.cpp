#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void count1(ll count[],ll e)
{
    bool hash[10];
    memset(hash,false,sizeof(hash));
    while(e > 0)
    {
        if(hash[e % 10] == false)
            count[e % 10]++;
        hash[e % 10] = true;
        e = e/10;
    }
}
ll solve (vector<ll> arr,ll n) {
   ll count[10];
   memset(count , 0 ,sizeof(count));
   for(ll i=0;i<n;i++)
   {
       count1(count,arr[i]);
   }
   ll longest=0,sl,j;
   for(ll i=0;i<10;i++)
   {
        if(count[i] > longest)
        {
            sl = longest;
            longest = count[i];
            j = i;
        }
        else if(count[i] > sl && count[i] != longest)
            sl = count[i];
   }
    if(j == 0)
        cout<<sl;
    else
        cout<<longest;
   
}

int main() {

    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i_arr=0; i_arr<n; i_arr++)
    {
    	cin >> arr[i_arr];
    }
    solve(arr,n);
}

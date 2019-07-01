#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n=4,x=1,cost=0,i,y,z;
    vector<unsigned long long>a;
    int a1[]={2,5,1,4};
    for(i=0;i<n;i++)
    {
        a.push_back(a1[i]);
    }
    while(!a.empty())
    {
    y = distance(a.begin(),max_element(a.begin(),a.end()));
    y = (a.size()-1) - y;
    if(x < y)
    {
        cost = cost + x;
        z = distance(a.begin(),min_element(a.begin(),a.end()));
        vector<unsigned long long>::iterator it=a.begin(); 
        a.erase(it+z);
    }
    else
    {
        cost = cost+y;
        z = distance(a.begin(),max_element(a.begin(),a.end()));
        vector<unsigned long long>::iterator it1=a.begin(); 
        a.erase(it1+z);
    }
    }
    cout<<cost;
    return 0;
}

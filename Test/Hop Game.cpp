//This is The Coding Area
#include<bits/stdc++.h>
using namespace std;
bool checkdouble(int a[],int i,int n)
{
  if(i+3 <= n && a[i] <= a[i+1] && a[i+1] <= a[i+2])
  {
    	return true;
  }
  else if(i+3 <= n && a[i] <= a[i+2])
  {
  	return true;
	}
  return false;
}
bool checksingle(int a[],int i,int n)
{
  	if(i+1 <= n && a[i] <= a[i+1])
    {
      return true;
    }
  	return false;
}
int main()
{
  int n = 6;
  cin>>n;
  int a[n];
  for(int j=0;j<n;j++)
  {
  	scanf("%d,",&a[j]);
  }
  int i=0;
  int d = 1;
  int res = 0;
  while(i<n)
  {
    if(d == 1 && a[i] == a[i+1] && a[i+1] == a[i+2] && a[i] == a[i+2])
    {
      res = res + a[i]*3;
      i=i+3;
      d = 0;
    }
    else
    {
      if(d == 1 && checkdouble(a,i,n))
       {
         res = res + a[i+2] * 3;
         i = i+3;
       }
        else if(checksingle(a,i,n))
        {
          res = res + a[i+1] *2;
          i = i+2;
        }
      else
      {
        res = res + a[i];
        i = i+1;
      }
    }
  }
  cout<<res;
  return 0;
}

#include<iostream>
using namespace std;
int fun1(int n)
{
  if(n == 1)
     return 0;
  else
     return 1 + fun1(n/2);
} 
void fun2(int n)
{
  if(n == 0)
    return;
 
  fun2(n/2);
  cout<<n%2;
}  
int main()
{
	int val=fun1(9);
	cout<<val<<"\n";
	fun2(21);
}
#include<iostream>
using namespace std;
void fun1(int n)
{
   int i = 0;  
   if (n > 1)
     fun1(n-1);
   for (i = 0; i < n; i++)
     cout<<" * ";
}
//Total numbers of stars printed is equal to 1 + 2 + …. (n-2) + (n-1) + n, which is n(n+1)/2.

#define LIMIT 1000
void fun2(int n)
{
  if (n <= 0)
     return;
  if (n > LIMIT)
    return;
  cout<<n<<"\t";
  fun2(2*n);
  cout<<n<<"\t";
}   

int main()
{
	fun1(2);
	cout<<"\n";
	fun2(100);

}
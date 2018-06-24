#include<iostream>
using namespace std;
void fun(int x)
{
  if(x > 0)
  {
     fun(--x);
     cout<<x<<"\t";
     fun(--x);
  }
}
int fun1(int a[],int n)
{
  int x;
  if(n == 1)
    return a[0];
  else
    x = fun1(a, n-1);
  if(x > a[n-1])
    return x;
  else
    return a[n-1];
}
int fun2(int i)
{
  if ( i%2 ) return (i++);
  else return fun2(fun2( i - 1 ));
}
int main()
{
  int a = 4;
  fun(a);
  int arr[] = {12, 10, 30, 50, 100};
  cout<<"\n"<<fun1(arr,5);
  cout<<"\n"<<fun2(200);
  return 0;
}

    /*               fun(4);              
                    /
                fun(3), print(3), fun(2)->fun(1),prints(1) ->fun(0) does nothing
               /                           |______ fun(0) prints(0)
           fun(2), print(2), fun(1)->fun(0),(prints 0)
           /
       fun(1), print(1), fun(0)(does nothing)
       /
    fun(0), print(0), fun(-1) (does nothing)*/

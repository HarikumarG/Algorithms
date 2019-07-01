#include<bits/stdc++.h>
using namespace std;
int NextPrime(int a)
{
    int i, j, count, num;
    for (i = a + 1; 1; i++)
    {   
        count = 0;  
        for (j = 2;j < i; j++)
        {
            if (i%j == 0) // found a devisor
            {
                count++; 
                break;  // break for (j = 2,j < i; j++) loop 
                        // this will speed up a bit
            }
        }
        if (count == 0)
        {
            return i; 
            //break; // break for (i = a + 1; 1; i++) loop
                     // break is not needed because return will stop execution of this function
        }
    }
}
int main()
{
    cout<<NextPrime(5);
    return 0;
}
/* Extended version of power function 
that can work for float x and negative y*/
#include <bits/stdc++.h> 
using namespace std; 

float power(float x, int y) 
{ 
	float temp; 
	if(y == 0) 
		return 1; 
	temp = power(x, y / 2); 
	if (y % 2 == 0) 
		return temp * temp; 
	else
	{ 
		if(y > 0) 
			return x * temp * temp; 
		else
			return (temp * temp) / x; 
	} 
} 
/*interview bit solution for power function
if(x == 0)
        return 0;
    if(n == 0)
        return 1;
    long long int base = x,ans = 1;
    while(n > 0)
    {
        if(n % 2 == 1)
        {
            ans = (ans * base) % d;
            n--;
        }
        else
        {
            base = (base * base) % d;
            n /= 2;
        }
    }
    if(ans < 0)
        ans = (ans + d) % d;
    return ans;*/

// Driver Code 
int main() 
{ 
	float x = 2; 
	int y = -3; 
	cout << power(x, y); 
	return 0; 
} 

// This is code is contributed 
// by rathbhupendra 

//Number of ways for partitioning n elements 
/*Let the set be {1, 2, 3}
             { {1}, {2}, {3} }
             { {1}, {2, 3} }
             { {2}, {1, 3} }
             { {3}, {1, 2} }
             { {1, 2, 3} }. 
			 number of ways  = 5*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 3;
	int bell[n+1][n+1];
	bell[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		bell[i][0] = bell[i-1][i-1];
		for(int j = 1; j <= i; j++)
		{
			bell[i][j] = bell[i-1][j-1] + bell[i][j-1];
		}
	}
	for(int i = 0;i <=n;i++)
 	{
   		for(int j = 0;j<=n;j++)
   		{
     		cout<<bell[i][j]<<" ";
   		}
   		cout<<"\n";
 	}
 	cout<<bell[n][0];
	return 0;
}

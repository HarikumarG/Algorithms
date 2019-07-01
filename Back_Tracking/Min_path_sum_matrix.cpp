#include<bits/stdc++.h>
using namespace std;
#define n 3
#define m 3
vector<int>fin;
void printsol(vector<int>sol)
{
		for(int j=0;j<sol.size();j++)
		{
			cout<<sol[j]<<" ";
		}
		cout<<"\n";
}
bool issafe(int x,int y)
{
	if(x>=0 && x<m && y>=0 && y<n)
		return true;
	return false;
}
int solve(int mat[n][n],int x,int y,int sum,vector<int>sol,int &min)
{
	if(x==m-1 && y==n-1)
	{
		sum=sum+mat[x][y];
		sol.push_back(mat[x][y]);
		if(sum < min)
		{
			min=sum;
			fin.clear();
			for(int i=0;i<sol.size();i++)
				fin.push_back(sol[i]);
		}
		return 1;
	}
	if(issafe(x,y)==true)
	{
		sum=sum+mat[x][y];
		sol.push_back(mat[x][y]);
		solve(mat,x,y+1,sum,sol,min);
		solve(mat,x+1,y,sum,sol,min);
		sum=0;
		sol.clear();
		return 1;
	}
	return 0;
}
int main()
{
	int mat[n][n] =  
	{ 	{1, 3, 1}, 
        {1, 5, 1}, 
        {4, 2, 1}, 
    }; 
    vector<int>sol;
    int val=999;
    solve(mat,0,0,0,sol,val);
    printsol(fin);
    return 0;
}
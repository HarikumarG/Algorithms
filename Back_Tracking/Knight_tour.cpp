#include<bits/stdc++.h>
using namespace std;
#define n 8
void printsol(int sol[n][n])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<sol[i][j]<<" ";
		}
		cout<<"\n";
	}
}
bool issafe(int x,int y,int sol[n][n])
{
	if(x>=0 && x<n && y>=0 && y<n && sol[x][y]==-1)
		return true;
	else
		return false;
}
bool solvektutil(int x,int y,int movei,int xmove[n],int ymove[n],int sol[n][n])
{
	int k,next_x,next_y;
	if(movei==n*n)
		return true;
	for(k=0;k<n;k++)
	{
		next_x=x+xmove[k];
		next_y=y+ymove[k];
		if(issafe(next_x,next_y,sol)==true)
		{
			sol[next_x][next_y]=movei;
			if(solvektutil(next_x,next_y,movei+1,xmove,ymove,sol)==true)
				return true;
			else
				sol[next_x][next_y]=-1;
		}
	}
	return false;
}
void solvekt()
{
	int sol[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			sol[i][j]=-1;
		}
	}
	sol[0][0]=0;
	int xmove[8]={2, 1, -1, -2, -2, -1,  1,  2};
	int ymove[8]={1, 2,  2,  1, -1, -2, -2, -1};
	if(solvektutil(0,0,1,xmove,ymove,sol)==true)
		printsol(sol);
	else
		cout<<"It doesnt have any solution";
}
int main()
{
	solvekt();
	return 0;
}
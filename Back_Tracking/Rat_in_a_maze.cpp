#include<bits/stdc++.h>
using namespace std;
#define n 4
int c = 0;
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
	cout<<"\n";
}
bool issafe(int maze[n][n],int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<n && maze[x][y]==1)
		return true;
	return false;
}
bool solvemazeutil(int maze[n][n],int x,int y,int sol[n][n])
{
	if(x==n-1 && y==n-1)
	{
		sol[x][y]=1;
		return true;
	}
	if(issafe(maze,x,y)==true)
	{
		sol[x][y]=1;
		if(solvemazeutil(maze,x,y+1,sol)==true)
			return true;
		if(solvemazeutil(maze,x+1,y,sol)==true)
			return true;
		sol[x][y]=0;
		return false;
	}
	return false;
}
int solvemazeutilcount(int maze[n][n],int x,int y,int sol[n][n])
{
	if(x==n-1 && y==n-1)
	{
		sol[x][y]=1;
		c++;
		//printsol(sol);
		return 1;
	}
	if(issafe(maze,x,y)==true)
	{
		sol[x][y]=1;
		solvemazeutilcount(maze,x,y+1,sol);
		solvemazeutilcount(maze,x+1,y,sol);
		sol[x][y]=0;
		return 1;
	}
	return 0;
}
void solvemaze(int maze[n][n])
{
	int sol[n][n]=
	{
		{0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0} 
	};
	/*if(solvemazeutil(maze,0,0,sol)==true)
	{
		cout<<"One of the solution is \n";
		printsol(sol);
	}
	else
	{
		cout<<"The solution doesn't exist\n";
	}*/
	if(solvemazeutilcount(maze,0,0,sol)==0)
	{
		cout<<"The solution doesn't exist\n";
	}
	cout<<"The Number of possible ways "<<c;
}
int main()
{
	int maze[n][n] =  
	{ 	{1, 1, 1, 1}, 
        {1, 1, 1, 1}, 
        {1, 1, 1, 1}, 
        {1, 1, 1, 1} 
    }; 
    solvemaze(maze);
    return 0;
}

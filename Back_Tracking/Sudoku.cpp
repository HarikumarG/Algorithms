#include<bits/stdc++.h>
using namespace std;
#define N 9
void printGrid(int grid[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<grid[i][j]<<" ";
		}
		cout<<"\n";
	}
}
bool FindUnassignedlocation(int grid[N][N],int &row,int &col)
{
	for(row=0;row<N;row++)
	{
		for(col=0;col<N;col++)
		{
			if(grid[row][col]==0)
				return true;
		}
	}
	return false;
}
bool usedinrow(int grid[N][N],int row,int num)
{
	for(int i=0;i<N;i++)
	{
		if(grid[row][i]==num)
			return true;
	}
	return false;
}
bool usedincol(int grid[N][N],int col,int num)
{
	for(int i=0;i<N;i++)
	{
		if(grid[i][col]==num)
			return true;
	}
	return false;
}
bool usedinbox(int grid[N][N],int row,int col,int num) //row and col gives start row and start col
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(grid[i+row][j+col]==num)
				return true;
		}
	}
	return false;
}
bool isSafe(int grid[N][N],int row,int col,int num)
{
	if(!usedinrow(grid,row,num) && !usedincol(grid,col,num) && !usedinbox(grid,row-row%3,col-col%3,num) &&grid[row][col]==0)
		return true;
	return false;	
}
bool SolveSudoku(int grid[N][N])
{
	int row,col;
	if(!FindUnassignedlocation(grid,row,col))
		return true;
	for(int i=1;i<=9;i++)
	{
		if(isSafe(grid,row,col,i)==true)
		{
			grid[row][col]=i;
			if(SolveSudoku(grid)==true)
				return true;
			grid[row][col]=0;
		}
	}
	return false;
}
int main() 
{ 
    // 0 means unassigned cells 
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                      {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                      {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                      {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                      {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                      {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                      {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                      {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}}; 
    if (SolveSudoku(grid) == true) 
          printGrid(grid); 
    else
         printf("No solution exists"); 
  
    return 0; 
} 
#include<bits/stdc++.h>
using namespace std;
#define n 9
bool res=false;
void printsol(int board[n][n])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}
bool issafe(int board[n][n],int row,int col)
{
	int i,j;
	for(i=0;i<col;i++)
	{
		if(board[row][i]==1)
			return false;
	}
	for(i=row,j=col;i>=0 && j>=0;i--,j--)
	{
		if(board[i][j]==1)
			return false;
	}
	for(i=row,j=col;i<n && j>=0;i++,j--)
	{
		if(board[i][j]==1)
			return false;
	}
	return true;
}
bool solvequeenutil(int board[n][n],int col)
{
	if(col>=n)
	{
		return true;
	}
	for(int i=0;i<n;i++)
	{
		if(issafe(board,i,col)==true)
		{
			board[i][col]=1;
			if(solvequeenutil(board,col+1)==true)
				return true;
			board[i][col]=0;
		}
	}
	return false;
}
int solvequeenutilallpossibles(int board[n][n],int col,int &c)
{
	if(col ==n)
	{
		//printsol(board);
		c++;
		//res=true;
		return 1;
	}
	for(int i=0;i<n;i++)
	{
		if(issafe(board,i,col)==1)
		{
			board[i][col]=1;
			solvequeenutilallpossibles(board,col+1,c);
			board[i][col]=0;
		}
	}	
	return c;
}
void solvequeen()
{
	int board[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			board[i][j]=0;
		}
	}
/*    if(solvequeenutil(board,0)==true)
   		printsol(board);
    else
    	cout<<"It doesn't have any solution";
*/
	int val=0;
	int s=solvequeenutilallpossibles(board,0,val);
    if(s==0)
		cout<<"It doesn't have any solution";    	
	else
		cout<<s;

}
int main()
{
	solvequeen();
	return 0;
}
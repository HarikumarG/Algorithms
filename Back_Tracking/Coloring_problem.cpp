#include<bits/stdc++.h>
using namespace std;
#define V 4
void printsolution(int color[V])
{
	for(int i=0;i<V;i++)
		cout<<color[i]<<" ";
}
bool isSafe(bool graph[V][V],int c,int v,int color[V])
{
	for(int i=0;i<V;i++)
	{
		if(graph[v][i]==1 && c==color[i])
			return false;
	}
	return true;
}
bool graphColoringUtil(bool graph[V][V],int m,int color[V],int v)
{
	if(v==V)
		return true;
	for(int c=1;c<=m;c++)
	{
		if(isSafe(graph,c,v,color)==true)
		{
			color[v]=c;
			if(graphColoringUtil(graph,m,color,v+1)==true)
				return true;
			color[v]=0;
		}
	}
	return false;
}
void graphColoring(bool graph[V][V],int m)
{
	int color[V];
	for(int i=0;i<V;i++)
	{
		color[i]=0;
	}
	if(graphColoringUtil(graph,m,color,0)==true)
		printsolution(color);
	else
		cout<<"\nThe solution doesnot exist";
}
int main() 
{ 
    /* Create following graph and test whether it is 3 colorable 
      (3)---(2) 
       |   / | 
       |  /  | 
       | /   | 
      (0)---(1) 
    */
    bool graph[V][V] = {{0, 1, 1, 1}, 
        {1, 0, 1, 0}, 
        {1, 1, 0, 1}, 
        {1, 0, 1, 0}, 
    }; 
    int m = 3; // Number of colors 
    graphColoring (graph, m); 
    return 0; 
} 
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
}
void DFS_util(vector<int>adj[],int s,bool visited[])
{
	visited[s]=true;
	vector<int>::iterator i;
	for(i=adj[s].begin();i!=adj[s].end();i++)
	{
		if(!visited[*i])
			DFS_util(adj,*i,visited);
	}
}
int find_mother(vector<int>adj[],int v)
{
	bool visited[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	int u=0;
	for(int j=0;j<v;j++)
	{
		int flag=1;
		if(!visited[j])
		{
			DFS_util(adj,j,visited);
			u=j;
		}
	}
	for(int m=0;m<v;m++)
	{
		visited[m]=false;
	}
	DFS_util(adj,u,visited);
	for(int k=0;k<v;k++)
	{
		if(visited[k]==false)
			return -1;
	}
	return u;
}
int main()
{
	int v=7;
	vector<int>adj[v];
	addEdge(adj,0, 1); 
    addEdge(adj,0, 2); 
    addEdge(adj,1, 3); 
    addEdge(adj,4, 1); 
    addEdge(adj,6, 4); 
    addEdge(adj,5, 6); 
    addEdge(adj,5, 2); 
    addEdge(adj,6, 0); 
    int j=find_mother(adj,v);
    cout<<j;
	return 0;
}
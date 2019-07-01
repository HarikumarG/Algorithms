#include<bits/stdc++.h>
using namespace std;
void DFS_util(vector<int>adj[],int s,bool visited[])
{
	visited[s]=true;
	cout<<s<<" ";
	vector<int>::iterator i;
	for(i=adj[s].begin();i!=adj[s].end();i++)
	{
		if(!visited[*i])
		{
			DFS_util(adj,*i,visited);
		}
	} 
}
void DFS_connected(vector<int>adj[],int s,int v)
{
	bool visited[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	DFS_util(adj,s,visited);
}
void DFS_unconnected(vector<int>adj[],int v)
{
	bool visited[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	for(int j=0;j<v;j++)
	{
		if(!visited[j])
		{
			DFS_util(adj,j,visited);
		}
	}
}
void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
}
int main()
{
	int v=4;
	vector<int>adj[4];
	addEdge(adj,0, 1); 
    addEdge(adj,0, 2); 
    addEdge(adj,1, 2); 
    addEdge(adj,2, 0); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 3); 
    DFS_connected(adj,2,4);
    cout<<"\n";
    vector<int>adj1[4];
    addEdge(adj1,0, 1); 
    addEdge(adj1,0, 2); 
    addEdge(adj1,1, 2); 
    addEdge(adj1,2, 0); 
    addEdge(adj1,2, 3); 
    addEdge(adj1,3, 3); 
    DFS_unconnected(adj1,4);
    return 0;
}
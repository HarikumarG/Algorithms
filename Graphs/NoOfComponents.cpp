#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void DfsUtil(vector<int>adj[],int v,bool visited[])
{
	visited[v] = true;
	vector<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++)
	{
		if(!visited[*i])
			DfsUtil(adj,*i,visited);
	}
}
int NumberOfComponents(vector<int>adj[],int v)
{
	int count = 0;
	bool visited[v];
	memset(visited,false,sizeof(visited));
	for(int i=0;i<v;i++)
	{
		if(visited[i] == false)
		{
			DfsUtil(adj,i,visited);
			count += 1;
		}	
	}
	return count;
}
int main()
{
	int v = 5;
	vector<int>adj[v];
	addEdge(adj,1, 0); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 4); 
    cout<<NumberOfComponents(adj,v);
    return 0;
}

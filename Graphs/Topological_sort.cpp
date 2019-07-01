#include<bits/stdc++.h>
using namespace std;
#define V 6
void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
}
void topologicalsortUtil(vector<int>adj[],int v,bool visited[],stack<int>&s)
{
	visited[v] = true;
	vector<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++)
	{
		if(!visited[*i])
			topologicalsortUtil(adj,*i,visited,s);
	}
	s.push(v);
}
void topologicalsort(vector<int>adj[])
{
	bool visited[V];
	memset(visited,false,sizeof(visited));
	stack<int>s;
	for(int i=0;i<V;i++)
	{
		if(visited[i] == false)
			topologicalsortUtil(adj,i,visited,s);
	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}
int main()
{
	vector<int>adj[V];
	addEdge(adj,5, 2); 
    addEdge(adj,5, 0); 
    addEdge(adj,4, 0); 
    addEdge(adj,4, 1); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 1); 
  	topologicalsort(adj);
  	return 0;
}

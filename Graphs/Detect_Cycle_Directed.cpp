#include<bits/stdc++.h>
using namespace std;
#define V 4
void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
}
bool isCyclicUtil(vector<int>adj[],int v,bool visited[],bool recstack[])
{
	if(visited[v] == false)
	{
		visited[v] = true;
		recstack[v] = true;
		
		vector<int>::iterator i;
		for(i = adj[v].begin();i != adj[v].end(); i++)
		{
			if(!visited[*i])
			{
				if(isCyclicUtil(adj,*i,visited,recstack))
					return true;
			}
			else if(recstack[*i])
				return true;
		}
	}
	recstack[v] = false;
	return false;
}
bool isCyclic(vector<int>adj[])
{
	bool visited[V];
	bool recstack[V];
	memset(visited,false,sizeof(visited));
	memset(recstack,false,sizeof(recstack));
	for(int i=0;i<V;i++)
	{
		if(isCyclicUtil(adj,i,visited,recstack))
			return true;
	}
	return false;
}
int main()
{
	vector<int>adj[V];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,2,0);
	addEdge(adj,2,3);
	addEdge(adj,3,3);
	if(isCyclic(adj))
		cout<<"The Graph contains a cycle";
	else
		cout<<"The Graph doesn't contains a cycle";
	return 0;
}

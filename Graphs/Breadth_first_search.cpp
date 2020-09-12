#include<bits/stdc++.h>
using namespace std;
void BFS_unconnected_util(int s,vector<int>adj[],bool visited[])
{
	vector<int>queue;
	visited[s]=true;
	queue.push_back(s);
	vector<int>::iterator i;
	while(!queue.empty())
	{
		s=queue.front();
		cout<<s<<" ";
		queue.erase(queue.begin());

		for(i=adj[s].begin();i!=adj[s].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				queue.push_back(*i);
			}
		}	
	}
}
void BFS_unconnected(vector<int>adj[],int v)
{
	bool visited[v];
	for(int i=0;i<5;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			BFS_unconnected_util(i,adj,visited);
		}
	}
}
void BFS_connected(vector<int>adj[],int s,int v)
{
	bool visited[v];
	for(int i=0;i<4;i++)
	{
		visited[i]=false;
	}
	vector<int>queue;
	visited[s]=true;
	queue.push_back(s);
	vector<int>::iterator i;
	while(!queue.empty())
	{
		s=queue.front();
		cout<<s<<" ";
		queue.erase(queue.begin());

		for(i=adj[s].begin();i!=adj[s].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				queue.push_back(*i);
			}
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
    BFS_connected(adj,2,4);
    cout<<"\n";
    int v1=5;
    vector<int>adj1[5];
  	addEdge(adj1, 0, 4); 
    addEdge(adj1, 1, 2); 
    addEdge(adj1, 1, 3); 
    addEdge(adj1, 1, 4); 
    addEdge(adj1, 2, 3); 
    addEdge(adj1, 3, 4); 
    //BFS_unconnected(adj1,4);
	return 0;
}

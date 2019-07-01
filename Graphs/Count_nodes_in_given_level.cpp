//For this problem we have to use BFS since it traverses horizontally
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
}
void BFS(vector<int>adj[],int s,int l,int v)
{
	bool visited[v];
	int level[v];
	for(int k=0;k<v;k++)
	{
		visited[k]=0;
		level[k]=0;
	}
	vector<int>queue;
	level[s]=0;
	visited[s]=true;
	queue.push_back(s);
	vector<int>::iterator i;
	while(!queue.empty())
	{
		s=queue.front();
		queue.erase(queue.begin());
		for(i=adj[s].begin();i!=adj[s].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				queue.push_back(*i);
				level[*i]=level[s]+1;
			}
		}
	}
	int count=0;
	for(int j=0;j<v;j++)
	{
		if(level[j]==l)
			count++;
	}
	cout<<count;
}
int main()
{
	int v=6;
	vector<int> adj[v];
	addEdge(adj,0, 1); 
    addEdge(adj,0, 2); 
    addEdge(adj,1, 3); 
    addEdge(adj,2, 4); 
    addEdge(adj,2, 5); 
    int level=2;
    BFS(adj,0,level,v);
	return 0;
}
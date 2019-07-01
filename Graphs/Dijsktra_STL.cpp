#include<bits/stdc++.h>
using namespace std;
#define V 9
typedef pair<int, int>ipair;
void addEdge(vector<ipair>adj[],int u,int v,int w)
{
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}
void Shortestpath(vector<ipair>adj[])
{
	priority_queue<ipair,vector<ipair>,greater<ipair> >pq;
	int src = 0;
	vector<int>dist(V,INT_MAX);
	pq.push(make_pair(0,src));
	dist[src] = 0;
	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		
		vector<ipair>::iterator i;
		for(i=adj[u].begin();i!=adj[u].end();i++)
		{
			int v = (*i).first;
			int weight = (*i).second;
			if(dist[v] > dist[u] + weight)
			{
				dist[v]=dist[u] + weight;
				pq.push(make_pair(dist[v],v));
			}
		}
	}
	cout<<"Vertex Distance from source\n";
	for(int i=0;i<V;i++)
	{
		cout<<i<<"   -   "<<dist[i]<<"\n";
	}
}
int main()
{
	vector<ipair>adj[V];
	addEdge(adj,0, 1, 4); 
    addEdge(adj,0, 7, 8); 
    addEdge(adj,1, 2, 8); 
    addEdge(adj,1, 7, 11); 
    addEdge(adj,2, 3, 7); 
    addEdge(adj,2, 8, 2); 
    addEdge(adj,2, 5, 4); 
    addEdge(adj,3, 4, 9); 
    addEdge(adj,3, 5, 14); 
    addEdge(adj,4, 5, 10); 
    addEdge(adj,5, 6, 2); 
    addEdge(adj,6, 7, 1); 
    addEdge(adj,6, 8, 6); 
    addEdge(adj,7, 8, 7); 
    Shortestpath(adj);
  	return 0;
}

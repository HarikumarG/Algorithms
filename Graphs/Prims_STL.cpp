#include<bits/stdc++.h>
using namespace std;
#define V 9
typedef pair<int, int>ipair;
void addEdge(vector<ipair>adj[],int u,int v,int w)
{
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}
void primMst(vector<ipair>adj[])
{
	priority_queue<ipair,vector<ipair>,greater<ipair> >pq;
	int src = 0;
	vector<int>key(V,INT_MAX);
	vector<int>parent(V,-1);
	vector<bool>inMst(V,false);
	pq.push(make_pair(0,src));
	key[src] = 0;
	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		inMst[u] = true;
		
		vector<ipair>::iterator i;
		for(i=adj[u].begin();i!=adj[u].end();i++)
		{
			int v = (*i).first;
			int weight = (*i).second;
			if(inMst[v] == false && key[v] > weight)
			{
				key[v] = weight;
				pq.push(make_pair(key[v],v));
				parent[v] = u;
			}
		}
	}
	for(int i=1;i<V;i++)
	{
		cout<<parent[i]<<"-"<<i<<"\n";
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
    primMst(adj);
  	return 0;
}

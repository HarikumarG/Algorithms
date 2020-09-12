#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}
void DFSUtil(int u, vector<int> adj[],
					vector<bool> &visited)
{
	visited[u] = true;
	vector<int>::iterator i;
	for (i=adj[u].begin(); i != adj[u].end(); i++)
		if (visited[*i] == false)
			DFSUtil(*i, adj, visited);
}
int countTrees(vector<int>adj[],int v)
{
    vector<bool>visited(v,false);
    int res = 0;
    for(int i = 0; i < v; i++)
    {
        if(visited[i] == false)
        {
            DFSUtil(i,adj,visited);
            res++;
        }
    }
    return res;
}
int main()
{
    int v = 5;
    vector<int>adj[v];
    addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 3, 4);
	cout << countTrees(adj, v);
	return 0;
}

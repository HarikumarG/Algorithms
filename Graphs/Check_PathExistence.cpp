#include<bits/stdc++.h>
using namespace std;
#define V 4
void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
}
bool isReachable(vector<int>adj[],int src,int dest)
{
	if(src == dest)
		return true;
	bool visited[V];
	memset(visited,false,sizeof(visited));
	visited[src] = true;
	vector<int>queue;
	queue.push_back(src);
	vector<int>::iterator i;
	while(!queue.empty())
	{
		src = queue.front();
		queue.pop_back();
		for(i = adj[src].begin();i != adj[src].end();i++)
		{
			if(*i == dest)
				return true;
			if(!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	return false;
}
int main()
{
	vector<int>adj[V];
    addEdge(adj,0, 1); 
    addEdge(adj,0, 2); 
    addEdge(adj,1, 2); 
    addEdge(adj,2, 0); 
    addEdge(adj,2, 3); 
	addEdge(adj,3, 3); 
  
    int u = 1, v = 3; 
    if(isReachable(adj,u, v)) 
        cout<< "\n There is a path from " << u << " to " << v; 
    else
        cout<< "\n There is no path from " << u << " to " << v; 
  
    u = 3, v = 1; 
    if(isReachable(adj,u, v)) 
        cout<< "\n There is a path from " << u << " to " << v; 
    else
        cout<< "\n There is no path from " << u << " to " << v; 
  
    return 0; 
}

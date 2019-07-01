#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void printGraph(vector<int>adj[],int v)
{
	for(int i=0;i<v;i++)
	{
		cout<<"Adjacency list of vertex "<<i <<"\nhead";
		vector<int>::iterator x=adj[i].begin();
		while( x !=adj[i].end())
		{
			cout<<"->"<<*x;
			*x++;
		}
		cout<<"\n";
	}
}
int main()
{
	int v=5;
	vector<int>adj[v];
	addEdge(adj,0, 1);
    addEdge(adj,1, 2);  
    addEdge(adj,0, 3); 
    addEdge(adj,2, 4); 
    addEdge(adj,1, 4); 
    addEdge(adj,1, 3); 
    printGraph(adj, v); 
    return 0;
}
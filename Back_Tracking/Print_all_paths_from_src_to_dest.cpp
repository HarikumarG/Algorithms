#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
}
void possiblepathutil(vector<int>adj[],int u,int dest,bool visited[],int path[],int pathind)
{
	visited[u]=true;
	path[pathind]=u;
	pathind++;
	if (u==dest)
	{
		for(int i=0;i<pathind;i++)
		{
			cout<<path[i]<<" ";
		}
		cout<<"\n";
	}
	else
	{
		vector<int>::iterator i;
		for(i=adj[u].begin();i!=adj[u].end();i++)
		{
			if(!visited[*i])
				possiblepathutil(adj,*i,dest,visited,path,pathind);
		}
	}
	visited[u]=false;
	pathind--;
}
void possiblepath(vector<int>adj[],int src,int dest,int v)
{
	bool visited[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	int ind=0;
	int path[v];
	possiblepathutil(adj,src,dest,visited,path,ind);
}
int main()
{
	int v=5;
	vector<int>adj[v];
   	addEdge(adj,0, 1);
    addEdge(adj,0, 3);  
    addEdge(adj,1, 2); 
    addEdge(adj,2, 4); 
    addEdge(adj,1, 4); 
    addEdge(adj,1, 3); 
    int src=0,dest=3;
    possiblepath(adj,src,dest,v);
    return 0;
}
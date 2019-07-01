#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int> >adj[],int u,int v,int w)
{
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}
bool findpath(vector<pair<int,int> >adj[],int src,int k,bool path[])
{
	if(k<=0)
		return true;
	vector<pair<int,int> >::iterator i;
	for(i=adj[src].begin();i!=adj[src].end();i++)
	{
		int v=i->first;
		int w=i->second;

		if(path[v] == true)
			continue;
		if(w>=k)
			return true;

		path[v]=true;

		if(findpath(adj,v,k-w,path))
			return true;

		path[v]=false;
	}
	return false;
}
int main()
{
	int v=9;
	vector<pair<int,int> >adj[v];
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
    int k=62;
    bool path[v];
    for(int i=0;i<v;i++)
    	path[i]=false;
    int src=0;
    path[src]=1;
    if(findpath(adj,src,k,path))
    	cout<<"true";
    else
    	cout<<"false";
  	return 0;
}
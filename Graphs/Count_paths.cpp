#include<bits/stdc++.h>
using namespace std;
#define V 4
void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
}
void PrintPath(vector<int>path)
{
	for(int i=0;i<path.size();i++)
		cout<<path[i]<<" ";
	cout<<"\n";
}
void CountpathsUtil(vector<int>adj[],int u,int d,bool visited[],int &pathcount,vector<int>&path)
{
	visited[u] = true;
	path.push_back(u);
	if(u == d)
	{
		pathcount++;
		PrintPath(path);
	}
	else
	{
		vector<int>::iterator i;
		for(i = adj[u].begin();i!=adj[u].end();i++)
		{
			if(!visited[*i])
			{
				CountpathsUtil(adj,*i,d,visited,pathcount,path);	
			}	
		}	
	}
	visited[u] = false;
	path.pop_back();
}
int Countpaths(vector<int>adj[],int s,int d)
{
	bool visited[V];
	memset(visited,false,sizeof(visited));
	int pathcount = 0;
	vector<int>path;
	CountpathsUtil(adj,s,d,visited,pathcount,path);
	return pathcount;
}
int main()
{
	vector<int>adj[V];
	addEdge(adj,0, 1); 
    addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,2, 0); 
    addEdge(adj,2, 1); 
    addEdge(adj,1, 3); 
    int s = 2,d = 3;
    cout<<"All the paths are\n";
    cout<<"NO.of.paths "<<Countpaths(adj,s,d);
    return 0;
}

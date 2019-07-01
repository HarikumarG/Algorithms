#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
}
void DFS_Iterative(vector<int>adj[],int s,int v)
{
	bool visited[v];
	for(int i=0;i<4;i++)
	{
		visited[i]=false;
	}
	stack<int> stack;
	visited[s]=true;
	stack.push(s);
	vector<int>::iterator i;
	while(!stack.empty())
	{
		s=stack.top();
		cout<<s<<" ";
		stack.pop();

		for(i=adj[s].begin();i!=adj[s].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				stack.push(*i);
			}
		}	
	}
}
int main()
{
	int v=5;
	vector<int>adj[v];
	addEdge(adj,1, 0); 
    addEdge(adj,0, 2); 
    addEdge(adj,2, 1); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 4);  
    DFS_Iterative(adj,0,4);
    return 0;
}
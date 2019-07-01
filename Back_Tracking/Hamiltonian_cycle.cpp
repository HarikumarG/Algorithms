#include<bits/stdc++.h>
using namespace std;
#define v 5
void printsol(int path[v])
{
	for(int i=0;i<v;i++)
		cout<<path[i]<<" ";
	cout<<path[0];
}
bool isSafe(bool graph[v][v],int path[v],int i,int pos)
{
	if(graph[path[pos-1]][i]==0)
		return false;
	for(int j=0;j<pos;j++)
	{
		if(path[j]==i)
			return false;
	}
	return true;
}
bool isSafelist(vector<int>graph2[v],int path[v],int i,int pos)
{
	int flag=0;
	int node=path[pos-1];
	vector<int>::iterator k;
	for(k=graph2[node].begin();k!=graph2[node].end();k++)
	{
		if(*k==i)
		{
			flag=1;
			break;
		}
	}
	int flag1=0;
	if(flag==1)
	{
		 flag1=1;
		for(int j=0;j<pos;j++)
		{
			if(path[j]==i)
				flag=0;
		}
	}
	if(flag==1 && flag1==1)
		return true;
	else
		return false;
}
bool hamCycleUtil(bool graph[v][v],int path[v],int pos)
{
	if(pos==v)
	{
		if(graph[ path[pos-1] ][ path[0] ]==1)
			return true;
		return false;
	}
	for(int i=1;i<v;i++)
	{
		if(isSafe(graph,path,i,pos)==true)
		{
			path[pos]=i;
			if(hamCycleUtil(graph,path,pos+1))
				return true;
			path[pos]=-1;
		}
	}
	return false;
}
bool hamCycleUtillist(vector<int>graph2[v],int path[v],int pos)
{
	if(pos==v)
	{
		int node=path[pos-1];
		vector<int>::iterator k;
		for(k=graph2[node].begin();k!=graph2[node].end();k++)
		{
			if(*k == 0)
				return true;
		}
		return false;
	}
	for(int i=1;i<v;i++)
	{
		if(isSafelist(graph2,path,i,pos)==true)
		{
			path[pos]=i;
			if(hamCycleUtillist(graph2,path,pos+1))
				return true;
			path[pos]=-1;
		}
	}
	return false;
}
void hamCycle(bool graph[v][v])
{
	int path[v];
	for(int i=0;i<v;i++)
		path[i]=-1;
	path[0]=0;
	if(hamCycleUtil(graph,path,1)==false)
		cout<<"\nHamiltonian cycle does not exist\n";
	else
		printsol(path);
}
void hamCyclelist(vector<int>graph2[v])
{
	int path[v];
	for(int i=0;i<v;i++)
		path[i]=-1;
	path[0]=0;
	if(hamCycleUtillist(graph2,path,1)==false)
		cout<<"Hamiltonian cycle does not exist";
	else
		printsol(path);	
}
void addEdge(vector<int>graph2[v],int u,int v1)
{
	graph2[u].push_back(v1);
	graph2[v1].push_back(u);
}
int main() 
{ 
   /* Let us create the following graph 
      (0)--(1)--(2) 
       |   / \   | 
       |  /   \  | 
       | /     \ | 
      (3)-------(4)    */
   bool graph1[v][v] = {{0, 1, 0, 1, 0}, 
                      {1, 0, 1, 1, 1}, 
                      {0, 1, 0, 0, 1}, 
                      {1, 1, 0, 0, 1}, 
                      {0, 1, 1, 1, 0}, 
                     }; 
    hamCycle(graph1); 
   /* Let us create the following graph 
      (0)--(1)--(2) 
       |   / \   | 
       |  /   \  | 
       | /     \ | 
      (3)       (4)    */
    cout<<"\n";
    vector<int>graph2[v];
    addEdge(graph2,0,1);
    addEdge(graph2,0,3);
    addEdge(graph2,1,2);
    addEdge(graph2,1,4);
    addEdge(graph2,1,3);
    addEdge(graph2,2,4);
    addEdge(graph2,3,4);
    hamCyclelist(graph2); 
    return 0; 
}
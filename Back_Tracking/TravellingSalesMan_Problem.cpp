#include<bits/stdc++.h>
using namespace std;
#define V 4
void tsp(int graph[][V],int currpos,bool v[],int cost,int &ans,int count)
{
	// If last node is reached and it has a link 
    // to the starting node i.e the source then 
    // keep the minimum value out of the total cost 
    // of traversal and "ans" 
    // Finally return to check for more possible values 
	if(count == V && graph[currpos][0])
	{
		ans = min(ans,cost+graph[currpos][0]);
	}
	// BACKTRACKING STEP 
    // Loop to traverse the adjacency list 
    // of currPos node and increasing the count 
    // by 1 and cost by graph[currPos][i] value 
	for(int i=0;i<V;i++)
	{
		if(!v[i] && graph[currpos][i])
		{
			v[i] = true;
			tsp(graph,i,v,cost+graph[currpos][i],ans,count+1);
			v[i] = false;
		}
	}
}
int main()
{
	int graph[][V] = { 
        { 0, 10, 15, 20 }, 
        { 10, 0, 35, 25 }, 
        { 15, 35, 0, 30 }, 
        { 20, 25, 30, 0 } 
    }; 
    
    int ans = INT_MAX;
    bool visited[V];
    memset(visited,false,sizeof(visited));
    visited[0] = true;
    tsp(graph,0,visited,0,ans,1);
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define V 9
// A utility function to find the vertex with  
// minimum key value, from the set of vertices  
// not yet included in MST
int minKey(int key[],bool mstSet[])
{
	int min = INT_MAX,min_ind;
	for(int v=0;v<V;v++)
	{
		if(mstSet[v] == false && key[v] < min)
			min = key[v],min_ind = v;
	}
	return min_ind;
}
int Shortestpath(int key[])
{
	for(int j=0;j<V;j++)
		cout<<j<<" "<<key[j]<<"\n";
}
void Dijsktra(int graph[][V])
{
	int key[V]; // Key values used to pick minimum weight edge in cut 
	bool mstSet[V]; // To represent set of vertices not yet included in MST
	for(int i=0;i<V;i++)
	{
		key[i] = INT_MAX,mstSet[i] = false;
	}
	key[0] = 0;
	for(int count = 0;count < V-1;count++)
	{
		// Pick the minimum key vertex from the  
        // set of vertices not yet included in MST 
		int u = minKey(key,mstSet);
		mstSet[u] = true;
		// Update key value and parent index of  
        // the adjacent vertices of the picked vertex.  
        // Consider only those vertices which are not  
        // yet included in MST 
		for(int v=0;v<V;v++)
		{
			// graph[u][v] is non zero only for adjacent vertices of m 
        	// mstSet[v] is false for vertices not yet included in MST 
        	// Update the key only if graph[u][v] is smaller than key[v] 
			if(graph[u][v] && mstSet[v] == false && key[u]+graph[u][v] < key[v])
			{
				key[v] = key[u] + graph[u][v];
			}
		}
	}
	Shortestpath(key);
}
int main()
{
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 
   
        Dijsktra(graph);
        return 0;
}

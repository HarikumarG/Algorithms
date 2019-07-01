#include<bits/stdc++.h>
using namespace std;
#define V 5
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
int printMST(int parent[],int graph[][V])
{
	for(int i=1;i<V;i++)
	{
		cout<<parent[i]<<"-"<<i<<" "<<graph[i][parent[i]]<<"\n";
	}
}
void primMST(int graph[][V])
{
	int parent[V]; // Array to store constructed MST 
	int key[V]; // Key values used to pick minimum weight edge in cut 
	bool mstSet[V]; // To represent set of vertices not yet included in MST
	for(int i=0;i<V;i++)
	{
		key[i] = INT_MAX,mstSet[i] = false;
	}
	key[0] = 0;
	parent[0] = -1;
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
			if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
		}
	}
	printMST(parent,graph);
}
int main()
{
	int graph[V][V] = {{0, 2, 0, 6, 0}, 
                    {2, 0, 3, 8, 5}, 
                    {0, 3, 0, 0, 7}, 
                    {6, 8, 0, 0, 9}, 
                    {0, 5, 7, 9, 0}}; 
        primMST(graph);
        return 0;
}

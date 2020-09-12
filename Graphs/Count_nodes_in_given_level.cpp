#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
}
int BFS(vector<int>adj[],int v,int l)
{
    queue<int>q;
    bool visited[v];
    int level[v];
    vector<int>::iterator i;
    int c = 0;
    memset(visited,false,sizeof(visited));
    memset(level,0,sizeof(level));
    q.push(0);
    visited[0] = true;
    level[0] = 0;
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        for(i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                q.push(*i);
                level[*i] = level[s] + 1;
            }
        }
    }
    for(int i = 0; i < v; i++)
    {
        if(level[i] == l)
            c++;
    }
    return c;
}
int DFS(vector<int>adj[],int v,int l)
{
    stack<int>q;
    bool visited[v];
    int level[v];
    vector<int>::iterator i;
    int c = 0;
    memset(visited,false,sizeof(visited));
    memset(level,0,sizeof(level));
    q.push(0);
    visited[0] = true;
    level[0] = 0;
    while(!q.empty())
    {
        int s = q.top();
        q.pop();
        if (!visited[s])
        {
            visited[s] = true;
        }
        for(i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if(!visited[*i])
            {
                q.push(*i);
                level[*i] = level[s] + 1;
            }
        }
    }
    for(int i = 0; i < v; i++)
    {
        if(level[i] == l)
            c++;
    }
    return c;

}
int main()
{
    int v = 6;
    vector<int>adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,2,4);
    addEdge(adj,2,5);
    int level = 2;
    int c = BFS(adj,v,level);
    cout<<"BFS -> "<<c;
    cout<<endl;
    int d = DFS(adj,v,level);
    cout<<"DFS -> "<<d;
    return 0;
}

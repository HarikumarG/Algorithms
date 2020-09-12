#include<bits/stdc++.h>
using namespace std;
struct cell
{
    int x;
    int y;
    int dis;
};
bool isInside(int x,int y,int n)
{
    if(x >= 1 && x <= n && y >= 1 && y <= n)
        return true;
    return false;
}
int minSteps(int knight[],int target[],int n)
{
    queue<cell>q;
    int x,y;
    bool visit[n+1][n+1];
    cell t;
    int dx[] = {-2, -1, 1, 2, 1, -2, -1, 2};
    int dy[] = {-1, -2, 2, 1, -2, 1, 2, -1};
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            visit[i][j] = false;
    q.push({knight[0],knight[1],0});
    visit[knight[0]][knight[1]] = true;

    while(!q.empty())
    {
        t = q.front();
        q.pop();

        if(t.x == target[0] && t.y == target[1])
            return t.dis;
        for(int i = 0; i < 8; i++)
        {
            x = t.x + dx[i];
            y = t.y + dy[i];

            if(isInside(x,y,n) && !visit[x][y])
            {
                visit[x][y] = true;
                q.push({x,y,t.dis+1});
            }
        }
    }

}
int main()
{
    int n = 6;
    int knight[] = {4,5};
    int target[] = {1,1};
    cout<<minSteps(knight,target,n);
    return 0;
}


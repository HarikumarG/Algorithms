#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
void BFS(int a,int b,int target)
{
    map<pii,int>m;
    bool isSolvable = false;
    vector<pii>path;
    queue<pii>q;
    q.push({0,0});

    while(!q.empty())
    {
        pii u = q.front();
        q.pop();
        if(m[{u.first,u.second}] == 1)
            continue;
        if((u.first > a || u.second > b || u.first < 0 || u.second < 0))
            continue;
        path.push_back({u.first,u.second});
        m[{u.first,u.second}] = 1;
        if(u.first == target || u.second == target)
        {
            isSolvable = true;
            if(u.first == target)
            {
                if(u.second != 0)
                    path.push_back({u.first,0});
            }
            else
            {
                if(u.first != 0)
                    path.push_back({0,u.second});
            }
            int sz = path.size();
            for(int i = 0; i < sz; i++)
            {
                cout<<"("<<path[i].first<<", "<<path[i].second<<")\n";
            }
            break;
        }
        q.push({ u.first, b });
		q.push({ a, u.second });

		//transfer jug 1 -> jug 2
		int d = b - u.second;
		if(u.first >= d)
		{
            int c = u.first - d;
            q.push({c,b});
		}
        else
        {
            int c = u.first + u.second;
            q.push({0,c});
        }

        //transfer jug 2 -> jug 1
        d = a - u.first;
        if(u.second >= d)
        {
            int c = u.second - d;
            q.push({a,c});
        }
        else if(u.second < d)
        {
            int c = u.first + u.second;
            q.push({c,0});
        }

		q.push({ a, 0 });
		q.push({ 0, b });

    }
    if (!isSolvable)
		cout << "No solution";
}
int main()
{
    int Jug1 = 4, Jug2 = 3, target = 1;
	cout << "Path from initial state "
			"to solution state :\n";
	BFS(Jug1, Jug2, target);
	return 0;
}

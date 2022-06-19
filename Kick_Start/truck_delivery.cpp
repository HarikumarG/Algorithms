/*
1
7 5
2 1 2 4
2 3 7 8
3 4 6 2
5 3 9 9
2 6 1 5
7 1 5 7
5 10
5 8
4 1
6 1
7 6
*/

#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int to, load, toll;
  Edge(int t, int l, int tol) {
    to = t;
    load = l;
    toll = tol;
  }
};

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a , a);
}

void addEdge(vector<Edge*> adj[], int f, int to, int l, int tol) {
  adj[f].push_back(new Edge(to, l, tol));
  adj[to].push_back(new Edge(f, l, tol));
}

bool solveUtil(vector<Edge*>adj[], int u, int weight, bool visited[], vector<int>& tolls) {

  visited[u] = true;
  if(u == 1) {
    return true;
  }
  else {
    vector<Edge*>::iterator i;
    for(i = adj[u].begin(); i != adj[u].end(); i++) {
      if(!visited[(*i)->to]) {
        if((*i)->load <= weight) {
          tolls.push_back((*i)->toll);
        }
        if(solveUtil(adj, (*i)->to, weight, visited, tolls)) {
          return true;
        }
        if((*i)->load <= weight) {
          tolls.pop_back();
        }
      }
    }
  }
  visited[u] = false;
  return false;
}

int solve(vector<Edge*> adj[], int start, int weight, int n) {
  int result = 0;
  bool visited[n+1];
  for(int i = 0; i < n+1; i++) {
    visited[i] = false;
  }
  vector<int> tolls;
  // cout<<"St"<<endl;
  // for(int i = 1; i <= n; i++) {
  //   cout<<i<<":";
  //   vector<Edge*>::iterator it;
  //   for(it = adj[i].begin(); it != adj[i].end(); it++) {
  //     cout<<" "<<(*it)->to<<" "<<(*it)->load<<" "<<(*it)->toll<<", ";
  //   }
  //   cout<<endl;
  // }
  // cout<<"end"<<endl;
  solveUtil(adj, start, weight, visited, tolls);
  int tollSize = tolls.size();
  if(tollSize > 0) {
    result = tolls[0];
    for(int i = 1; i < tollSize; i++) {
      result = gcd(tolls[i], result);
      if(result == 1) {
        break;
      }
    }
  }
  // cout<<endl<<"tolls";
  // for(auto i : tolls) {
  //   cout<<i<<" ";
  // }
  // cout<<endl;
  return result;
}

int main() {
  int t;
  cin >> t;
  for(int t1 = 1; t1 <= t; t1++) {
    int n, q, f, to, l, tol, start, weight;
    cin>> n;
    cin>> q;

    vector<Edge*> adj[n+1];
    for(int i = 1; i <= n-1; i++) {
      cin >> f;
      cin >> to;
      cin >> l;
      cin >> tol;
      addEdge(adj, f, to, l, tol);
    }

    vector<int> result;
    for(int i = 1; i <= q; i++) {
      cin >> start;
      cin >> weight;
      result.push_back(solve(adj, start, weight, n));
    }

    cout<<"Case #"<<t1<<":";
    for(auto r : result) {
      cout<<" "<<r;
    }
    cout<<endl;
  }
  return 0;
}

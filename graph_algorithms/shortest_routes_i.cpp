#include<bits/stdc++.h>
using namespace std;
 
/* Shorthands */
#define elif                  else if
#define Fi                    first
#define Se                    second
#define pb                    push_back
#define nl                    '\n'

/* Constants */
#define IINF                  INT_MAX
#define LLINF                 1e18
 
/*  */
#define roof(x, y)            (((x)+(y)-1)/(y))
#define sz(x)                 (int)((x).size())
#define all(x)                (x).begin(), (x).end()
#define rall(x)               (x).rbegin(), (x).rend()
#define gcd(a, b)             __gcd(a, b)
#define lcm(a, b)             ((a/gcd(a, b))*b)
 
/* */
#define RET(x)                { cout<<(x)<<endl; return; }
#define DBG(x)                { cout<<"? "<<#x<<" : "<<x<<endl; }
 
/* Aliases */
using lli   = long long int;
using PII   = pair<int, int>;
using PLL   = pair<lli, lli>;
using VI    = vector<int>;
using VLL   = vector<lli>;


/* Solve Here */
void solve(int tc) {
  int n, m;
  cin>>n>>m;

  vector<vector<PII>> adj(n+1);
  for(int i=0; i<m; i++) {
    int x, y, c;
    cin>>x>>y>>c;

    adj[x].pb({y, c});
  }

  VLL dist(n+1, LLINF);

  // Dijkstra
  priority_queue<PLL, vector<PLL>, greater<PLL>> q;
  dist[1]=0;
  q.push({0, 1});

  while(!q.empty()) {
    auto [cur_dist, cur]=q.top();
    q.pop();

    if(dist[cur]!=cur_dist)
      continue; // Already better opt found

    for(auto [next, wght]:adj[cur]) {
      if(dist[next]>dist[cur]+wght) {
        dist[next]=dist[cur]+wght;
        q.push({dist[next], next});
      }
    }
  }

  for(int i=1; i<=n; i++)
    cout<<dist[i]<<" ";
  cout<<nl;
}
 
 
/* Main */
int main() {
  int t = 1;
  //cin>>t;
 
  for(int i=1; i<=t; i++)
    solve(i);
 
  return 0;
}

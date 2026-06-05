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


void bfs(int src, vector<VI>& adj, VI& vis, int& farthest, int& dist) {
  vis[src]=1;

  queue<PII> q;
  q.push({src, 0});
  vis[src]=1;

  while(!q.empty()) {
    int cur=q.front().Fi;
    int curdist=q.front().Se;
    q.pop();

    if(curdist>=dist) {
      farthest=cur;
      dist=curdist;
    }

    for(auto it:adj[cur]) {
      if(vis[it])
        continue;

      vis[it]=1;
      q.push({it, curdist+1});
    }
  }
}


/* Solve Here */
void solve(int tc) {
  int n;
  cin>>n;

  vector<VI> adj(n+1);
  for(int i=1; i<n; i++) {
    int x, y;
    cin>>x>>y;
    adj[x].pb(y);
    adj[y].pb(x);
  }

  int farthest, dist=0;
  VI vis(n+1);
  bfs(1, adj, vis, farthest, dist);

  vis=VI(n+1);

  int farthest2, dist2=0;
  bfs(farthest, adj, vis, farthest2, dist2);

  cout<<dist2<<nl;
}
 
 
/* Main */
int main() {
  int t = 1;
  //cin>>t;
 
  for(int i=1; i<=t; i++)
    solve(i);
 
  return 0;
}

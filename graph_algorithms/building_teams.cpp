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


void dfs(int src, vector<VI>& adj, VI& mark, bool& pos) {
  queue<int> q;
  q.push(src);
  mark[src]=1;

  while(!q.empty()) {
    int cur=q.front();
    q.pop();

    for(auto it:adj[cur]) {
      if(mark[it]==mark[cur]) {
        pos=0;
        return;
      }

      if(mark[it])
        continue;

      mark[it]=(mark[cur]==1)? 2 : 1;
      q.push(it);
    }
  }
}


/* Solve Here */
void solve(int tc) {
  int n, m;
  cin>>n>>m;

  vector<VI> adj(n+1);
  for(int i=0; i<m; i++) {
    int x, y;
    cin>>x>>y;
    adj[x].pb(y);
    adj[y].pb(x);
  }

  VI mark(n+1);
  bool pos=1;
  for(int i=1; i<=n; i++) {
    if(mark[i])
      continue;

    dfs(i, adj, mark, pos);
  }

  if(!pos)
    RET("IMPOSSIBLE");

  for(int i=1; i<=n; i++)
    cout<<mark[i]<<" ";
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
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


int count(int src, vector<VI>& adj, VI& cnt) {
  if(cnt[src]!=-1)
    return cnt[src];

  int tot=1;
  for(auto it:adj[src])
    tot+=count(it, adj, cnt);

  cnt[src]=tot;
  return cnt[src];
}

 
/* Solve Here */
void solve(int tc) {
  int n;
  cin>>n;

  vector<VI> adj(n+1);
  for(int i=2; i<=n; i++) {
    int x;
    cin>>x;
    adj[x].pb(i);
  }

  VI cnt(n+1, -1);
  count(1, adj, cnt);

  for(int i=1; i<=n; i++)
    cout<<cnt[i]-1<<" ";
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

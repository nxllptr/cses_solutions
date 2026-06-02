#include<bits/stdc++.h>
using namespace std;
 
/* Shorthands */
#define elif                  else if
#define Fi                    first
#define Se                    second
#define pb                    push_back
#define nl                    '\n'
 
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


void visit(int i, int j, vector<string>& v, vector<VI>& vis, int n, int m) {
  if(i<0 or i>=n or j<0 or j>=m)
    return;

  if(v[i][j]=='#' or vis[i][j])
    return;


  vis[i][j]=1;
  visit(i-1, j, v, vis, n, m);
  visit(i+1, j, v, vis, n, m);
  visit(i, j-1, v, vis, n, m);
  visit(i, j+1, v, vis, n, m);
}

 
/* Solve Here */
void solve(int tc) {
  int n, m;
  cin>>n>>m;

  vector<string> v(n);
  for(auto &it:v)
    cin>>it;

  int cnt=0;
  vector<VI> vis(n, vector<int>(m, 0));
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(vis[i][j] or v[i][j]=='#')
        continue;

      cnt++;
      visit(i, j, v, vis, n, m);
    }
  }

  RET(cnt);
}
 
 
/* Main */
int main() {
  int t = 1;
  //cin>>t;
 
  for(int i=1; i<=t; i++)
    solve(i);
 
  return 0;
}
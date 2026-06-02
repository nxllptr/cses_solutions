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
 
 
/* Solve Here */
void solve(int tc) {
  int n, x;
  cin>>n>>x;
 
  VI v(n);
  map<int, VI> idx;     // Using unordered_map gives TLE for some reason idk
 
  for(int i=0; i<n; i++) {
    cin>>v[i];
    idx[v[i]].pb(i);
  }
 
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      int req=x-v[i]-v[j];
 
      if(idx.count(req)) {
        for(auto k:idx[req])
          if(k!=i and k!=j) {
            cout<<i+1<<" "<<j+1<<" "<<k+1<<nl;
            return;
          }
      }
    }
  }
 
  RET("IMPOSSIBLE");
}
 
 
/* Main */
int main() {
  int t = 1;
  //cin>>t;
 
  for(int i=1; i<=t; i++)
    solve(i);
 
  return 0;
}

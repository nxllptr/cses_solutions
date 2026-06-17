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
#define VOUT(x)               { for(auto it:x) { cout<<it<<" "; }; cout<<nl; }
#define DBG(x)                { cout<<"? "<<#x<<" : "<<x<<endl; }
 
/* Aliases */
using lli   = long long int;
using PII   = pair<int, int>;
using PLL   = pair<lli, lli>;
using VI    = vector<int>;
using VLL   = vector<lli>;


/* Constants */
const int IINF  = 2e9;
const lli LLINF = 2e18;
const lli MOD   = 1e9+7;


/* Solve Here */
void solve(int tc) {
  int n;
  cin>>n;
  VI v(n);
  for(auto &it:v)
    cin>>it;

  map<int, int> prev_occ;
  int start_idx=0;
  int res=0;

  for(int i=0; i<n; i++) {
    if(!prev_occ.count(v[i])) {
      prev_occ[v[i]]=i;
      continue;
    }

    if(prev_occ[v[i]]<start_idx)
      prev_occ[v[i]]=i;
    else {
      res=max(res, i-start_idx);
      start_idx=prev_occ[v[i]]+1;
      prev_occ[v[i]]=i;
    }
  }
  res=max(res, n-start_idx);

  cout<<res<<nl;
}
   
   
/* Main */
int main() {
  int t = 1;
  // cin>>t;
   
  for(int i=1; i<=t; i++)
    solve(i);
   
  return 0;
}

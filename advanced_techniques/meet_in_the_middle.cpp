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


void check(VI& v, VLL& tot) {
  int n=sz(v);

  for(int i=0; i<(1ll<<n); i++) {
    lli cur=0;
    for(int j=0; j<n; j++)
      if(i&(1ll<<j))
        cur+=v[j];
    
    tot.pb(cur);
  }
}


/* Solve Here */
void solve(int tc) {
  int n, x;
  cin>>n>>x;

  int n1=n/2, n2=n-n1;
  VI v1(n1), v2(n2);
  for(auto &it:v1)
    cin>>it;
  for(auto &it:v2)
    cin>>it;

  VLL tot1;
  VLL tot2;
  check(v1, tot1);
  check(v2, tot2);

  sort(all(tot2));

  lli res=0;
  for(auto sum1:tot1) {
    lli req=x-sum1;
    auto ub=upper_bound(all(tot2), req);
    auto lb=lower_bound(all(tot2), req);
    res+=(ub-lb);
  }

  cout<<res<<nl;
}
   
   
/* Main */
int main() {
  int t = 1;
  //cin>>t;
   
  for(int i=1; i<=t; i++)
    solve(i);
   
  return 0;
}

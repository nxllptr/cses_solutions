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
  int n;
  cin>>n;

  vector<PII> p(n);
  for(int i=0; i<n; i++)
    cin>>p[i].Fi>>p[i].Se;
  p.pb({p[0].Fi, p[0].Se});
  
  lli res=0;
  for(int i=0; i<n; i++)
    res+=1ll*p[i].Fi*p[i+1].Se;

  for(int i=1; i<=n; i++)
    res-=1ll*p[i-1].Se*p[i].Fi;

  if(res<0)
    res=-res;

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

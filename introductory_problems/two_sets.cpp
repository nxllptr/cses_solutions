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
  int n;
  cin>>n;

  lli tot=1ll*n*(n+1)/2;
  if(tot%2)
    RET("NO");

  VI set(n+1);
  int set1=0;
  lli req=tot/2;
  for(int i=n; i>=1; i--) {
    if(req>=i) {
      set[i]=1;
      set1++;
      req-=i;
    }
  }

  cout<<"YES"<<nl;

  cout<<set1<<nl;
  for(int i=1; i<=n; i++)
    if(set[i])
      cout<<i<<" ";
  cout<<nl;

  cout<<n-set1<<nl;
  for(int i=1; i<=n; i++)
    if(!set[i])
      cout<<i<<" ";
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
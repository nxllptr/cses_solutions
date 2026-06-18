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


bool check(lli mid, lli t, VI& v) {
  lli prod=0;
  for(auto it:v) {
    prod+=(mid/it);

    if(prod>=t)
      return true;
  }

  return false;
}


/* Solve Here */
void solve(int tc) {
  int n, t;
  cin>>n>>t;

  VI v(n);
  for(auto &it:v)
    cin>>it;

  sort(all(v));

  lli lo=0, hi=LLINF;
  while(lo<hi) {
    lli mid=(lo+hi)/2;

    if(check(mid, t, v))
      hi=mid;

    else
      lo=mid+1;
  }

  cout<<lo<<nl;
}
   
   
/* Main */
int main() {
  int t = 1;
  // cin>>t;
   
  for(int i=1; i<=t; i++)
    solve(i);
   
  return 0;
}

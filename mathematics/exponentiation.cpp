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


const lli MOD = 1e9+7;

lli pw(int a, int b) {
  VLL pww(32);
  pww[0]=1;
  pww[1]=a;
  for(int i=2; i<=31; i++)
    pww[i]=(pww[i-1]*pww[i-1])%MOD;

  lli res=1;
  for(int i=31; i>=0; i--)
    if(b&(1<<i)) {
      res*=pww[i+1];
      res%=MOD;
    }

  return res;
}


/* Solve Here */
void solve(int tc) {
  int a, b;
  cin>>a>>b;

  cout<<pw(a, b)<<nl;
}
   
   
/* Main */
int main() {
  int t = 1;
  cin>>t;
   
  for(int i=1; i<=t; i++)
    solve(i);
   
  return 0;
}

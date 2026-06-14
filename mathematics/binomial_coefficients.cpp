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


/* Constants */
const int IINF  = 2e9;
const lli LLINF = 2e18;
const lli MOD   = 1e9+7;


lli binpow(int a, int b) {
  vector<lli> pw(31);
  pw[0]=a;

  for(int i=1; i<=30; i++)
    pw[i]=(pw[i-1]*pw[i-1])%MOD;

  lli res=1;
  for(int i=0; i<=30; i++)
    if(b&(1<<i)) {
      res*=pw[i];
      res%=MOD;
    }

  return res;
}


VLL fact(1e6+1);
void seive() {
  fact[0]=1;

  for(int i=1; i<=1e6; i++)
    fact[i]=(fact[i-1]*i)%MOD;
}


/* Solve Here */
void solve(int tc) {
  int a, b;
  cin>>a>>b;

  lli res=fact[a];
  res=(res*(binpow(fact[b], MOD-2)%MOD))%MOD;
  res=(res*(binpow(fact[a-b], MOD-2)%MOD))%MOD;

  cout<<res<<nl;
}
   
   
/* Main */
int main() {
  seive();

  int t = 1;
  cin>>t;
   
  for(int i=1; i<=t; i++)
    solve(i);
   
  return 0;
}

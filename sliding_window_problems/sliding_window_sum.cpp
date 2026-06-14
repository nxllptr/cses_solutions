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
  int n, k;
  cin>>n>>k;

  int x, a, b, c;
  cin>>x>>a>>b>>c;

  lli res=0;
  lli sum=0;
  VLL v(k);

  v[0]=x;
  sum+=x;
  for(int i=1; i<k; i++) {
    v[i]=(a*v[i-1]+b)%c;
    sum+=v[i];
  }

  res=sum;

  int cur=0;
  for(int i=k; i<n; i++) {
    if(cur==k)
      cur=0;
    
    int prev=(cur==0)? k-1:cur-1;

    sum-=v[cur];
    v[cur]=(a*v[prev]+b)%c;
    sum+=v[cur];

    res^=sum;
    cur++;
  }

  RET(res);
}
   
   
/* Main */
int main() {
  int t = 1;
  // cin>>t;
   
  for(int i=1; i<=t; i++)
    solve(i);
   
  return 0;
}

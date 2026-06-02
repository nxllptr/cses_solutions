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

  VI c(n);
  for(auto &it:c)
    cin>>it;

  VLL dp(x+10, INT_MAX);
  for(auto it:c)
    if(it<=x)
      dp[it]=1;

  for(int i=1; i<=x; i++) {
    for(auto it:c)
      if(i-it>=1)
        dp[i]=min(dp[i], dp[i-it]+1);
  }

  int res=(dp[x]==INT_MAX? -1 : dp[x]);
  RET(res);
}


/* Main */
int main() {
  int t = 1;
  //cin>>t;

  for(int i=1; i<=t; i++)
    solve(i);

  return 0;
}
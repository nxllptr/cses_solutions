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
  lli MOD=1e9+7;

  int n;
  cin>>n;

  vector<string> v(n);
  for(auto &it:v)
    cin>>it;

  lli dp[n][n];
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      dp[i][j]=0;

  if(v[0][0]=='.')
    dp[0][0]=1;

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(v[i][j]=='*')
        continue;

      if(i and v[i-1][j]=='.')
        dp[i][j]+=dp[i-1][j];
      if(j and v[i][j-1]=='.')
        dp[i][j]+=dp[i][j-1];

      dp[i][j]%=MOD;
    }
  }

  RET(dp[n-1][n-1]);
}


/* Main */
int main() {
  int t = 1;
  //cin>>t;

  for(int i=1; i<=t; i++)
    solve(i);

  return 0;
}
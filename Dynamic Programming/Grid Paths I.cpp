/**
 * Problem Name: Grid Paths I
 * Link: https://cses.fi/problemset/task/1638
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int main() {
  int n;
  cin>>n;

  vector<string> v(n);
  for(auto &it:v)
    cin>>it;

  vector<vector<long long int>> dp(n, vector<long long int>(n, 0));

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

  cout<<dp[n-1][n-1]<<endl;

  return 0;
}
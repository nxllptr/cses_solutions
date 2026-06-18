/**
 * Problem Name: Dice Combinations
 * Link: https://cses.fi/problemset/task/1633
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

/* Main */
int main() {
  int n;
  cin>>n;

  vector<long long int> dp(n+10);

  for(int i=1; i<=6; i++)
    dp[i]=1;

  for(int i=1; i<=n; i++) {
    long long int cur=0;
    
    for(int j=1; j<=6; j++)
      if(i-j>=1)
        cur+=dp[i-j];

    dp[i]=(dp[i]+cur)%MOD;
  }

  cout<<dp[n]<<endl;

  return 0;
}
/**
 * Problem Name: Coin Combinations I
 * Link: https://cses.fi/problemset/task/1635
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int main() {
  int n, x;
  cin>>n>>x;

  vector<int> coins(n);
  for(auto &it:coins)
    cin>>it;

  vector<long long int> dp(x+10);

  for(auto it:coins)
    if(it<=x)
      dp[it]=1;

  for(int i=1; i<=x; i++) {
    long long int cur_sum=0;

    for(auto it:coins)
      if(i-it>=1)
        cur_sum+=(dp[i-it]);

    dp[i]=(dp[i]+cur_sum)%MOD;
  }

  cout<<dp[x]<<endl;

  return 0;
}
/**
 * Problem Name: Minimizing Coins
 * Link: https://cses.fi/problemset/task/1634
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin>>n>>x;

  vector<int> coins(n);
  for(int i=0; i<n; i++)
    cin>>coins[i];

  vector<long long int> dp(x+10, INT_MAX);
  for(auto coin:coins)
    if(coin<=x)
      dp[coin]=1;

  for(int i=1; i<=x; i++) {
    for(auto coin:coins)
      if(i-coin>=1)
        dp[i]=min(dp[i], dp[i-coin]+1);
  }

  cout<<(dp[x]==INT_MAX? -1 : dp[x])<<endl;

  return 0;
}
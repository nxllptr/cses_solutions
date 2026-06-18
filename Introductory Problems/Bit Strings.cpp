/**
 * Problem Name: Bit Strings
 * Link: https://cses.fi/problemset/task/1617
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

/* Main */
int main() {
  int n;
  cin>>n;

  int res=1;
  for(int i=1; i<=n; i++)
    res=(res*2)%MOD;
  
  cout<<res<<endl;

  return 0;
}
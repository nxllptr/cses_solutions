/**
 * Problem Name: Range Xor Queries
 * Link: https://cses.fi/problemset/task/1650/
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  cin>>n>>q;

  vector<int> v(n);
  for(int i=0; i<n; i++)
    cin>>v[i];

  // Use prefix array for bits
  vector<vector<int>> pre(n+1, vector<int>(31));
  for(int i=1; i<=n; i++) {
    for(int j=0; j<31; j++) {
      // Toggle bit (1^1=0, 0^1=1)

      if(v[i-1]&(1<<j))
        pre[i][j]=!pre[i-1][j];

      else
        pre[i][j]=pre[i-1][j];
    }
  }

  while(q--) {
    int l, r;
    cin>>l>>r;

    long long int sum=0;
    for(int i=0; i<31; i++) {
      int bit_enabled=pre[r][i]-pre[l-1][i];

      if(bit_enabled)
        sum+=(1<<i);
    }

    cout<<sum<<endl;
  }

  return 0;
}

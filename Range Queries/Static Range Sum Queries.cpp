/**
 * Problem Name: Static Range Sum Queries
 * Link: https://cses.fi/problemset/task/1646
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  cin>>n>>q;

  vector<int> v(n+1);
  vector<int> prefix(n+1);

  for(int i=1; i<=n; i++) {
    cin>>v[i];
    prefix[i]=prefix[i-1]+v[i];
  }

  while(q--) {
    int l, r;
    cin>>l>>r;
    cout<<prefix[r]-prefix[l-1]<<" ";
  }

  cout<<endl;
 
  return 0;
}

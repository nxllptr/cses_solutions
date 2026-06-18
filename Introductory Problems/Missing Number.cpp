/**
 * Problem Name: Missing Number
 * Link: https://cses.fi/problemset/task/1083
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin>>n;

  vector<int> v(n-1);
  long long int sum_cur=0;
  for(int i=0; i<n-1; i++) {
    cin>>v[i];
    sum_cur+=v[i];
  }

  long long int sum_req = 1ll*n*(n+1)/2;

  // current sum + missing number = required sum (sum from 1..n)
  int res=sum_req-sum_cur;

  cout<<res<<endl;

  return 0;
}
/**
 * Problem Name: Two Sets
 * Link: https://cses.fi/problemset/task/1092
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;
 
int main() {
  int n;
  cin>>n;

  // An array can never be divided into two sets of equal sum if its sum is odd
  // i.e. 1+2+...+n must be even

  long long int tot=1ll*n*(n+1)/2;
  if(tot%2) {
    cout<<"NO"<<endl;
    return 0;
  }

  // Logic: Keep taking the biggest integer from 1...n which has not been taken yet

  vector<int> set(n+1); // set[i]==1 means `i` belongs to set 1, otherwise, it belongs to set 2 (set[i]==0)

  long long int req=tot/2;
  for(int i=n; i>=1; i--) {
    if(req>=i) {
      set[i]=1;
      req-=i;
    }
  }

  vector<int> set1, set2;
  for(int i=1; i<=n; i++) {
    if(set[i]==1)
      set1.push_back(i);
    else
      set2.push_back(i);
  }

  cout<<"YES"<<endl;

  cout<<set1.size()<<endl;
  for(auto it:set1)
    cout<<it<<" ";
  cout<<endl;

  cout<<set2.size()<<endl;
  for(auto it:set2)
    cout<<it<<" ";
  cout<<endl;
 
  return 0;
}
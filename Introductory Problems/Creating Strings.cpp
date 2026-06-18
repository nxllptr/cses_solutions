/**
 * Problem Name: Creating Strings
 * Link: https://cses.fi/problemset/task/1622
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;
 
int main() {
  string s;
  cin>>s;

  set<string> perms;

  // Generate all permutations of string s
  sort(s.begin(), s.end());
  do {
    perms.insert(s);
  } while(next_permutation(s.begin(), s.end()));

  cout<<perms.size()<<endl;
  for(auto perm:perms)
    cout<<perm<<endl;
 
  return 0;
}
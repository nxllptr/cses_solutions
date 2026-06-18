/**
 * Problem Name: Repetitions
 * Link: https://cses.fi/problemset/task/1069
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin>>s;

  int res=1;
  int cur=1;
  for(int i=1; i<s.size(); i++) {
    cur=(s[i]==s[i-1])? cur+1 : 1;
    
    res=max(res, cur);
  }

  cout<<res<<endl;

  return 0;
}
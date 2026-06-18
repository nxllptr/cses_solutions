/**
 * Problem Name: Gray Code
 * Link: https://cses.fi/problemset/task/2205
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

// Idea: Gray Code of length (n) can be determined from gray code of length (n-1) in the following way:
// (1) Take all gray codes of length (n-1) and put 0 in front of them
// (2) Take all gray codes of length (n-1) from reverse and put 1 in front of them
// Can be solved using recursion

vector<string> get_graycodes(int n) {
  if(n==1)
    return vector<string>({"0", "1"});

  vector<string> codes=get_graycodes(n-1);
  int len=codes.size();

  for(int i=0; i<len; i++)
    codes[i]="0"+codes[i];

  for(int i=len-1; i>=0; i--) {
    string cur=codes[i];
    cur[0]='1';
    codes.push_back(cur);
  }

  return codes;
}

int main() {
  int n;
  cin>>n;

  vector<string> res = get_graycodes(n);
  for(auto it:res)
    cout<<it<<endl;

  return 0;
}

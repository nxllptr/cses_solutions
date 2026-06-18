/**
 * Problem Name: Palindrome Reorder
 * Link: https://cses.fi/problemset/task/1755
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin>>s;

  map<char, int> cnt;
  for(auto ch:s)
    cnt[ch]++;

  char odd='?';
  bool possible=1;

  // Check how many odd character occurences are there
  for(auto [fi, se]:cnt) {
    if(se%2==0)
      continue;

    if(odd!='?') {
      // There are multiple characters with odd times of occurences
      // So, palindrome is not possible
      possible=0;
      break;
    }

    else
      odd=fi;
  }

  if(!possible) {
    cout<<"NO SOLUTION"<<endl;
    return 0;
  }

  string reordered=s;
  int l=0, r=s.size()-1;

  if(odd!='?') {
    reordered[s.size()/2]=odd;
    cnt[odd]--;
  }

  for(auto [fi, se]:cnt) {
    int cur=se;
    while(cur>0) {
      reordered[l++]=fi;
      reordered[r--]=fi;
      cur-=2;
    }
  }

  cout<<reordered<<endl;
 
  return 0;
}
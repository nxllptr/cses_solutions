/**
 * Problem Name: Trailing Zeros
 * Link: https://cses.fi/problemset/task/1618
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

// Get how many of `x` is inside `n`
int get(int n, int x) {
  int cur=x; // cur = pow(x, something)
  int res=0;

  while(cur<=n) {
    res+=(n/cur);
    cur*=x;
  }

  return res;
}

int main() {
  int n;
  cin>>n;

  int twos=get(n, 2); // how many twos are inside n
  int fives=get(n, 5); // how many fives are inside n

  int res=min(twos, fives); // 2*5=10
  cout<<res<<endl;

  return 0;
}
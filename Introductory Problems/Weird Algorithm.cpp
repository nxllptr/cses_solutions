/**
 * Problem Name: Weird Algorithm
 * Link: https://cses.fi/problemset/task/1068
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin>>n;

  long long int cur = n;

  while(1) {
    cout<<cur<<" ";

    if(cur==1)
      break;

    if(cur%2)
      cur=(cur*3)+1;

    else
      cur/=2;
  }

  cout<<endl;

  return 0;
}
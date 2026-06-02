#include<bits/stdc++.h>
using namespace std;
 
/* Shorthands */
#define elif                  else if
#define Fi                    first
#define Se                    second
#define pb                    push_back
#define nl                    '\n'
 
/*  */
#define roof(x, y)            (((x)+(y)-1)/(y))
#define sz(x)                 (int)((x).size())
#define all(x)                (x).begin(), (x).end()
#define rall(x)               (x).rbegin(), (x).rend()
#define gcd(a, b)             __gcd(a, b)
#define lcm(a, b)             ((a/gcd(a, b))*b)
 
/* */
#define RET(x)                { cout<<(x)<<endl; return; }
#define DBG(x)                { cout<<"? "<<#x<<" : "<<x<<endl; }
 
/* Aliases */
using lli   = long long int;
using PII   = pair<int, int>;
using PLL   = pair<lli, lli>;
using VI    = vector<int>;
using VLL   = vector<lli>;
 
 
/* Solve Here */
void solve(int tc) {
  int n, x;
  cin>>n>>x;

  VI v(n);
  for(auto &it:v)
    cin>>it;

  int l=0, r=0;
  int res=0;
  lli cur=0;

  while(r<n) {
    while(r<n and cur<x) {
      cur+=v[r];
      r++;
    }

    while(l<=r and cur>x) {
      cur-=v[l];
      l++;
    }

    if(cur==x) {
      res++;
      cur-=v[l];
      l++;
    }
  }

  RET(res);
}
 
 
/* Main */
int main() {
  int t = 1;
  //cin>>t;
 
  for(int i=1; i<=t; i++)
    solve(i);
 
  return 0;
}
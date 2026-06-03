#include<bits/stdc++.h>
using namespace std;
 
/* Shorthands */
#define elif                  else if
#define Fi                    first
#define Se                    second
#define pb                    push_back
#define nl                    '\n'

/* Constants */
#define IINF                  INT_MAX
#define LLINF                 1e18
 
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
  string s;
  cin>>s;

  map<char, int> cnt;
  for(auto ch:s)
    cnt[ch]++;

  char odd='?';
  bool pos=1;
  for(auto [fi, se]:cnt) {
    if(se%2) {
      if(odd!='?') {
        pos=0;
        break;
      }
      else {
        odd=fi;
      }
    }
  }

  if(!pos)
    RET("NO SOLUTION");

  string ss=s;
  int l=0, r=sz(s)-1;

  if(odd!='?') {
    ss[sz(s)/2]=odd;
    cnt[odd]--;
  }

  for(auto [fi, se]:cnt) {
    int cur=se;
    while(cur>0) {
      ss[l]=fi;
      ss[r]=fi;
      l++;
      r--;
      cur-=2;
    }
  }

  cout<<ss<<nl;
}
 
 
/* Main */
int main() {
  int t = 1;
  //cin>>t;
 
  for(int i=1; i<=t; i++)
    solve(i);
 
  return 0;
}
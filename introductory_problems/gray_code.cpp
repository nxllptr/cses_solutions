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


vector<string> get(int n) {
  if(n==1) {
    return vector<string>({"0", "1"});
  }

  vector<string> vs=get(n-1);
  int len=sz(vs);
  for(int i=0; i<len; i++)
    vs[i]="0"+vs[i];

  for(int i=len-1; i>=0; i--) {
    string cur=vs[i];
    cur[0]='1';
    vs.pb(cur);
  }

  return vs;
}


/* Solve Here */
void solve(int tc) {
  int n;
  cin>>n;

  vector<string> res = get(n);
  for(auto it:res)
    cout<<it<<nl;
}
   
   
/* Main */
int main() {
  int t = 1;
  //cin>>t;
   
  for(int i=1; i<=t; i++)
    solve(i);
   
  return 0;
}

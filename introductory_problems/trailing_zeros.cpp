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


int get(int n, int x) {
  int cur=x;
  int res=0;
  for(; ;) {
    if(cur>n)
      break;

    res+=(n/cur);
    cur*=x;
  }

  return res;
}


/* Solve Here */
void solve(int tc) {
  int n;
  cin>>n;

  int tw=get(n, 2);
  int fi=get(n, 5);

  int res=min(tw, fi);
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
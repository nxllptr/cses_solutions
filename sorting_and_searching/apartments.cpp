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
  int n, m, k;
  cin>>n>>m>>k;

  VI a(n);
  for(auto &it:a)
    cin>>it;

  VI b(m);
  for(auto &it:b)
    cin>>it;

  sort(all(a));
  sort(all(b));

  int aa=0, bb=0;
  int res=0;
  while(1) {
    if(aa>=sz(a) or bb>=sz(b))
      break;

    if(b[bb]<a[aa]-k)
      bb++;
    elif(b[bb]>a[aa]+k)
      aa++;

    if(a[aa]-k<=b[bb] and b[bb]<=a[aa]+k) {
      aa++;
      bb++;
      res++;
    }
  }

  cout<<res<<nl;
}
 
 
/* Main */
int main() {
  int t = 1;
  //cin>>t;
 
  for(int i=1; i<=t; i++)
    solve(i);
 
  return 0;
}

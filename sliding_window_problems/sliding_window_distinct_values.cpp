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
  int n, k;
  cin>>n>>k;
  VI v(n);
  for(auto &it:v)
    cin>>it;

  map<int, int> cnt;      // std::unordered_map causes TLE
  for(int i=0; i<k; i++)
    cnt[v[i]]++;
  cout<<sz(cnt)<<" ";

  for(int i=k; i<n; i++) {
    cnt[v[i-k]]--;
    if(cnt[v[i-k]]==0)
      cnt.erase(v[i-k]);

    cnt[v[i]]++;
    cout<<sz(cnt)<<" ";
  }
  cout<<nl;
}
 
 
/* Main */
int main() {
  int t = 1;
  //cin>>t;
 
  for(int i=1; i<=t; i++)
    solve(i);
 
  return 0;
}
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
#define VOUT(x)               { for(auto it:x) { cout<<it<<" "; }; cout<<nl; }
#define DBG(x)                { cout<<"? "<<#x<<" : "<<x<<endl; }
 
/* Aliases */
using lli   = long long int;
using PII   = pair<int, int>;
using PLL   = pair<lli, lli>;
using VI    = vector<int>;
using VLL   = vector<lli>;


/* Constants */
const int IINF  = 2e9;
const lli LLINF = 2e18;
const lli MOD   = 1e9+7;


int ask(int i, int j) {
  cout<<"? "<<i<<" "<<j<<nl;
  cout.flush();

  string resp;
  cin>>resp;

  return resp=="YES";
}


/* Solve Here */
void solve(int tc) {
  int n;
  cin>>n;

  VI idx(n);
  for(int i=0; i<n; i++)
    idx[i]=i;

  // sort() exceeds query limit
  stable_sort(all(idx), [&](int i, int j) { return ask(i+1, j+1); });

  VI res(n);
  for(int i=0; i<n; i++)
    res[idx[i]]=i+1;

  cout<<"! ";
  VOUT(res);
  cout<<nl;
  cout.flush();
}
   
   
/* Main */
int main() {
  int t = 1;
  // cin>>t;
   
  for(int i=1; i<=t; i++)
    solve(i);
   
  return 0;
}

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


void add(multiset<int>& l, multiset<int>& r, int n) {
  if(l.empty())
    l.insert(n);

  else {
    int l_end = *prev(l.end());

    if(n>l_end)
      r.insert(n);

    else {
      l.erase(l.find(l_end));
      r.insert(l_end);
      l.insert(n);
    }
  }
}

void rmv(multiset<int>& l, multiset<int>& r, int n) {
  if(!r.empty() and r.find(n)!=r.end())
    r.erase(r.find(n));

  else
    l.erase(l.find(n));
}

void balance(multiset<int>& l, multiset<int>& r, int sz) {
  while(l.size()<sz and !r.empty()) {
    int r_front=*r.begin();
    r.erase(r.find(r_front));
    l.insert(r_front);
  }

  while(l.size()>sz) {
    int l_end=*prev(l.end());
    l.erase(l.find(l_end));
    r.insert(l_end);
  }
}


/* Solve Here */
void solve(int tc) {
  int n, k;
  cin>>n>>k;

  VI v(n);
  for(auto &it:v)
    cin>>it;

  multiset<int> l, r;
  int l_size=roof(k, 2);

  for(int i=0; i<k; i++)
    add(l, r, v[i]);
  balance(l, r, l_size);

  cout<<*(prev(l.end()))<<" ";

  for(int i=k; i<n; i++) {
    // Remove v[i-k] first
    rmv(l, r, v[i-k]);
    balance(l, r, l_size);
    add(l, r, v[i]);
    balance(l, r, l_size);

    cout<<*(prev(l.end()))<<" ";
  }

  cout<<nl;
}
   
   
/* Main */
int main() {
  int t = 1;
  // cin>>t;
   
  for(int i=1; i<=t; i++)
    solve(i);
   
  return 0;
}

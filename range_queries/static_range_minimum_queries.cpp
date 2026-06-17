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


class SegTree {
  VI segtree;
  VI arr;
  int len;

public:
  void set_array(VI v) {
    arr=v;
    len=sz(arr);
    segtree=VI(4*len);
  }

  void build(int node, int l, int r) {
    if(l==r) {
      segtree[node]=arr[l];
      return;
    }

    int mid=(l+r)/2;
    int left_child=2*node+1;
    int right_child=2*node+2;

    build(left_child, l, mid);
    build(right_child, mid+1, r);

    segtree[node]=min(segtree[left_child], segtree[right_child]);
  }

  int query(int node, int l, int r, int target_l, int target_r) {
    if(l>target_r or r<target_l)
      return IINF;

    if(l>=target_l and r<=target_r)
      return segtree[node];

    int mid=(l+r)/2;
    int left_child=2*node+1;
    int right_child=2*node+2;

    int min_left=query(left_child, l, mid, target_l, target_r);
    int min_right=query(right_child, mid+1, r, target_l, target_r);

    return min(min_left, min_right);
  }
};


/* Solve Here */
void solve(int tc) {
  int n, q;
  cin>>n>>q;

  VI v(n);
  for(auto &it:v)
    cin>>it;

  SegTree st;
  st.set_array(v);
  st.build(0, 0, n-1);

  while(q--) {
    int l, r;
    cin>>l>>r;

    int res=st.query(0, 0, n-1, l-1, r-1);
    cout<<res<<nl;
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

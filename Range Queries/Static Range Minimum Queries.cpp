/**
 * Problem Name: Static Range Minimum Queries
 * Link: https://cses.fi/problemset/task/1647
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

// Use Segment Tree
class SegTree {
  vector<int> arr;
  vector<int> tree;

public:
  void set_vector(vector<int>& v) {
    arr=v;
    tree=vector<int>(v.size()*4);
  }

  void build(int node, int l, int r) {
    if(l==r) {
      tree[node]=arr[l];
      return;
    }

    int child_left=2*node+1;
    int child_right=2*node+2;

    int mid=(l+r)/2;

    build(child_left, l, mid);
    build(child_right, mid+1, r);

    tree[node]=min(tree[child_left], tree[child_right]);
  }

  int query(int node, int l, int r, int target_l, int target_r) {
    if(l>target_r or r<target_l)
      return INT_MAX;

    if(l>=target_l and r<=target_r)
      return tree[node];
    
    int child_left=2*node+1;
    int child_right=2*node+2;

    int mid=(l+r)/2;

    int min_left=query(child_left, l, mid, target_l, target_r);
    int min_right=query(child_right, mid+1, r, target_l, target_r);

    return min(min_left, min_right);
  }
};

int main() {
  int n, q;
  cin>>n>>q;

  vector<int> v(n);
  for(int i=0; i<n; i++)
    cin>>v[i];

  SegTree st;
  st.set_vector(v);
  st.build(0, 0, n-1);

  while(q--) {
    int l, r;
    cin>>l>>r;
    cout<<st.query(0, 0, n-1, l-1, r-1)<<endl;
  }
   
  return 0;
}

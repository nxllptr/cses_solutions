/**
 * Problem Name: Dynamic Range Minimum Queries
 * Link: https://cses.fi/problemset/task/1649/
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

// Can be solved with segment tree
class SegTree {
  vector<int> arr;
  vector<int> tree;

public:
  void set_vector(vector<int>& v) {
    arr=v;
    tree=vector<int>(arr.size()*4);
  }

  void build(int node, int l, int r) {
    if(l==r) {
      tree[node]=arr[l];
      return;
    }

    int childnode_left=2*node+1;
    int childnode_right=2*node+2;

    int mid=(l+r)/2;

    build(childnode_left, l, mid);
    build(childnode_right, mid+1, r);

    tree[node]=min(tree[childnode_left],tree[childnode_right]);
  }

  int query(int node, int l, int r, int target_l, int target_r) {
    if(l>target_r or r<target_l)
      return INT_MAX;

    if(l>=target_l and r<=target_r)
      return tree[node];
    
    int childnode_left=2*node+1;
    int childnode_right=2*node+2;

    int mid=(l+r)/2;

    int min_left=query(childnode_left, l, mid, target_l, target_r);
    int min_right=query(childnode_right, mid+1, r, target_l, target_r);

    return min(min_left, min_right);
  }

  void update(int node, int l, int r, int idx, int val) {
    if(idx>r or idx<l)
      return;

    if(l==r) {
      arr[idx]=val;
      tree[node]=val;
    }

    else {
      int mid=(l+r)/2;
      int childnode_left=2*node+1;
      int childnode_right=2*node+2;

      update(childnode_left, l, mid, idx, val);
      update(childnode_right, mid+1, r, idx, val);

      tree[node]=min(tree[childnode_left], tree[childnode_right]);
    }
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
    int c, l, r;
    cin>>c>>l>>r;

    if(c==1)
      st.update(0, 0, n-1, l-1, r);

    else
      cout<<st.query(0, 0, n-1, l-1, r-1)<<endl;
  }
   
  return 0;
}

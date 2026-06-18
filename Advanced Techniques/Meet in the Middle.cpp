/**
 * Problem Name: Meet in the Middle
 * Link: https://cses.fi/problemset/task/1628/
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

void compute(vector<int>& v, vector<long long int>& sum) {
  int n=v.size();

  for(int i=0; i<(1ll<<n); i++) {
    long long int cur_sum = 0;

    for(int j=0; j<n; j++)
      if(i&(1ll<<j))
        cur_sum+=v[j];
    
    sum.push_back(cur_sum);
  }
}

int main() {
  int n, x;
  cin>>n>>x;

  // n<=40
  // Meet in the middle: Split array t into two halves, generate all subsets and combine their result
  int n1=n/2, n2=n-n1;
  vector<int> t1(n1), t2(n2);

  for(int i=0; i<n1; i++)
    cin>>t1[i];

  for(int i=0; i<n2; i++)
    cin>>t2[i];

  vector<long long int> sum1; // All possible subset sums of t1
  vector<long long int> sum2; // All possible subset sums of t2
  
  compute(t1, sum1);
  compute(t2, sum2);

  // Use binary search
  sort(sum2.begin(), sum2.end());

  long long int res=0;
  for(auto have:sum1) {
    long long int need=x-have;

    auto ub=upper_bound(sum2.begin(), sum2.end(), need);
    auto lb=lower_bound(sum2.begin(), sum2.end(), need);

    res+=(ub-lb);
  }

  cout<<res<<endl;
   
  return 0;
}

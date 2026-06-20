/**
 * Problem Name: Polygon Area
 * Link: https://cses.fi/problemset/result/17632609/
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin>>n;

  vector<pair<int, int>> p(n);
  for(int i=0; i<n; i++)
    cin>>p[i].first>>p[i].second;

  // Matrix method
  p.push_back(p[0]);
  
  long long int area=0;
  for(int i=0; i<n; i++)
    area+=(1ll*p[i].first*p[i+1].second);

  for(int i=1; i<=n; i++)
    area-=(1ll*p[i-1].second*p[i].first);

  area=abs(area);
  cout<<area<<endl;
   
  return 0;
}

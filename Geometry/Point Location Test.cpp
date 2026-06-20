/**
 * Problem Name: Point Location Test
 * Link: https://cses.fi/problemset/task/2189
 * Author: Mehedi Rahman Mahi (nxllptr)
 */

#include<bits/stdc++.h>

using namespace std;

struct Point {
  long long int x;
  long long int y;

  void input() {
    cin>>x>>y;
  }
};

int check(Point p1, Point p2, Point p3) {
  // Equation of SL connecting p1 and p2: (x-x1)/(y-y1) = (x1-x2)/(y1-y2)
  // The value of the SL when x=p3.x, y=p3.y will speak for itself

  long long int val=(p3.x-p1.x)*(p1.y-p2.y)-(p1.x-p2.x)*(p3.y-p1.y);

  int sign;
  if(val>0)
    sign = 1;
  else if(val<0)
    sign = -1;
  else
    sign = 0;

  return sign;
}
   
   
/* Main */
int main() {
  int t = 1;
  cin>>t;
   
  for(int i=1; i<=t; i++) {
    Point p1, p2, p3;
    p1.input();
    p2.input();
    p3.input();

    int sign = check(p1, p2, p3);

    if(sign==0)
      cout<<"TOUCH"<<endl;
    else if(sign==1)
      cout<<"LEFT"<<endl;
    else
      cout<<"RIGHT"<<endl;
  }

  return 0;
}

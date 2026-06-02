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


typedef struct {
  int x, y;
} Coord;


/* Solve Here */
void solve(int tc) {
  int n, m;
  cin>>n>>m;

  vector<string> v(n);
  for(auto &it:v)
    cin>>it;

  vector<vector<char>> dir(n, vector<char>(m, '?'));
  vector<VI> steps(n, VI(m, IINF));
  
  Coord a, b;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++) {
      if(v[i][j]=='A') {
        a.x=i;
        a.y=j;
      }
      elif(v[i][j]=='B') {
        b.x=i;
        b.y=j;
      }
    }

  queue<Coord> q;
  q.push({a.x, a.y});
  steps[a.x][a.y] = 0;

  while(!q.empty()) {
    Coord cur = q.front();
    q.pop();

    int x = cur.x;
    int y = cur.y;

    // down
    if(x+1<n and v[x+1][y]!='#' and steps[x+1][y]==IINF) {
        steps[x+1][y]=steps[x][y]+1;
        dir[x+1][y]='D';
        q.push({x+1, y});
    }

    // up
    if(x-1>=0 and v[x-1][y]!='#' and steps[x-1][y]==IINF) {
        steps[x-1][y]=steps[x][y]+1;
        dir[x-1][y]='U';
        q.push({x-1, y});
    }

    // left
    if(y-1>=0 and v[x][y-1]!='#' and steps[x][y-1]==IINF) {
        steps[x][y-1]=steps[x][y]+1;
        dir[x][y-1]='L';
        q.push({x, y-1});
    }

    // right
    if(y+1<m and v[x][y+1]!='#' and steps[x][y+1]==IINF) {
        steps[x][y+1]=steps[x][y]+1;
        dir[x][y+1]='R';
        q.push({x, y+1});
    }
  }

  if(steps[b.x][b.y]==IINF)
    RET("NO");

  string path;
  Coord rev=b;
  char cur=dir[rev.x][rev.y];
  while(cur!='?') {
    path+=cur;

    if(cur=='D')
      rev.x--;
    if(cur=='U')
      rev.x++;
    if(cur=='L')
      rev.y++;
    if(cur=='R')
      rev.y--;

    cur=dir[rev.x][rev.y];
  }
  reverse(all(path));

  cout<<"YES"<<nl;
  cout<<steps[b.x][b.y]<<nl;
  cout<<path<<nl;
}
 
 
/* Main */
int main() {
  int t = 1;
  //cin>>t;
 
  for(int i=1; i<=t; i++)
    solve(i);
 
  return 0;
}
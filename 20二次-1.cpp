#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
typedef long long ll;
using vc=vector<char>;
using vvc=vector<vc>;
template<class T> bool chmin(T&a,T b){if(a>b){a=b; return true;}return false;}
template<class T> void out(T a){cout<<a<<endl;}
ll paint(ll n,ll k,vvc x,vvc y){
  rep(i,n)rep(j,n){
    if(x[i][j]!=y[i][j]) k++;
  }
  return k;
}
void solve() {
  ll n; cin>>n;
  vvc a(n,vc(n)),z(n,vc(n));
  rep(i,n)rep(j,n) cin>>a[i][j];
  rep(i,n)rep(j,n) cin>>z[i][j];
  vvc b(n,vc(n)),c(n,vc(n)),d(n,vc(n));
  rep(i,n)rep(j,n){
    b[n-j-1][i]=a[i][j];
    c[j][n-i-1]=a[i][j];
    d[n-i-1][n-j-1]=a[i][j];
  }
  ll p,q,r,s;
  p=paint(n,0,a,z);
  q=paint(n,1,b,z);
  r=paint(n,1,c,z);
  s=paint(n,2,d,z);
  vector<ll> v={p,q,r,s};
  sort(all(v));
  out(v[0]);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
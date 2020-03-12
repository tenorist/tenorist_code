#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> P;
using vi=vector<ll>;
template<class T> void out(T a){cout<<a<<endl;}
//template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<endl;}
void solve() {
  ll n; cin>>n;
  vector<P> red(n);
  rep(i,n) cin>>red[i].fi>>red[i].se;
  vi home;
  rep(i,n){
    ll k=max(red[i].fi,red[i].se); //n‚·ŠÔ’u‚«Š·‚¦
    home.eb(k+red[i].fi); //–ß‚é‚Ü‚Å
  }
  sort(all(home));
  reverse(all(home));
  out(home[0]);
  //outv(home);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}

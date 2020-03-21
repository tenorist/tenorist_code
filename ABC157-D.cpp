//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define eb emplace_back
typedef long long ll;
using vi=vector<ll>;
using vvi=vector<vi>;
template<class T> bool chmin(T&a,T b){if(a>b){a=b; return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b; return true;}return false;}
template<class T> void out(T a){cout<<a<<endl;}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<endl;}
struct UnionFind {
  vi d;
  UnionFind(ll n=0):d(n,-1) {}
  ll find(ll x){
    if(d[x]<0) return x;
    return d[x]=find(d[x]);
  }
  bool unite(ll x,ll y) {
    x=find(x); y=find(y);
    if(x==y) return false;
    if(d[x]>d[y]) swap(x,y);
    d[x]+=d[y];
    d[y]=x;
    return true;
  }
  bool same(ll x,ll y) {return find(x)==find(y);}
  ll size(ll x) {return -d[find(x)];}
};
vi p(100005),q[100005];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m,k;
  cin>>n>>m>>k;
  UnionFind uf(n);
  //friend
  rep(i,m){
    ll a,b;
    cin>>a>>b;
    a--; b--;
    p[a]++; p[b]++;
    uf.unite(a,b);
  }
  //block
  rep(i,k){
    ll c,d;
    cin>>c>>d;
    c--; d--;
    q[c].eb(d); q[d].eb(c);
  }
  vi ans;
  rep(i,n){
    ll x=uf.size(i)-p[i]-1;
    for(ll k:q[i]){if(uf.same(i,k)) x--;}
    ans.eb(x);
  }
  outv(ans);
}

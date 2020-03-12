// ACしたコード
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
typedef long long ll;
using vi=vector<ll>;
template<class T> void out(T a){cout<<a<<endl;}
vi calc(ll x){vi res; while(x>0){res.eb(x%10);x/=10;}reverse(all(res)); return res;}
ll sum_calc(ll k){
  vi v=calc(k);
  ll a=0;
  rep(i,(ll)v.size()) a+=v[i];
  return a+k;
}
void solve() {
  ll n; cin>>n;
  set<ll> s;
  s.insert(n);
  for(ll i=n;i>0;i--){
    if(s.count(sum_calc(i))) s.insert(i);
  }
  out(s.size());
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}

// ミス1(13/20TLE)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
typedef long long ll;
using vi=vector<ll>;
template<class T> void out(T a){cout<<a<<endl;}
//template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<endl;}
vi calc(ll x){vi res; while(x>0){res.eb(x%10);x/=10;}reverse(all(res)); return res;}
ll sum_calc(ll k){
  vi v=calc(k);
  ll a=0;
  rep(i,(ll)v.size()) a+=v[i];
  return a;
}
bool ds(ll n,ll k){
  while(k<=n){
    k+=sum_calc(k);
    if(k==n) return true;
  }
  return false;
}
void solve() {
  ll n,ans=1; //nは候補
  cin>>n;
  REP(i,1,n){
    if(ds(n,i)) ans++;
  }
  out(ans);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}

// ミス2(2/20TLE)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
typedef long long ll;
using vi=vector<ll>;
template<class T> void out(T a){cout<<a<<endl;}
template<class T> void outs(T v){for(auto a:v)cout<<a<<" ";cout<<endl;}
vi calc(ll x){vi res; while(x>0){res.eb(x%10);x/=10;}reverse(all(res)); return res;}
set<ll> s;
ll sum_calc(ll k){
  vi v=calc(k);
  ll a=0;
  rep(i,(ll)v.size()) a+=v[i];
  return a+k;
}
void search(ll n){
  bool f=true;
  REP(i,1,55){ // 9*6=54
    if(i>=n) break;
    if(sum_calc(n-i)==n){
      f=false;
      s.insert(n-i);
      search(n-i);
    }
  }
  if(f) return;
}
void solve() {
  ll n; cin>>n;
  s.insert(n);
  search(n);
  out(s.size());
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}

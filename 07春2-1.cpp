#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
typedef long long ll;
using vi=vector<ll>;
const ll inf=1001001001001001;
template<class T> bool chmin(T&a,T b){if(a>b){a=b; return true;}return false;}
template<class T> void out(T a){cout<<a<<endl;}

vi dp(10005,inf);

void solve() {
  ll n; cin>>n;
  vi a(n); rep(i,n) cin>>a[i];
  rep(i,n) if(ub(dp,a[i])-lb(dp,a[i])==0) chmin(dp[lb(dp,a[i])],a[i]);
  out(lb(dp,inf));
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}

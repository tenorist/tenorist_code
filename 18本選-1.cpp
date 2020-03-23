<AC>(O(NlogN))
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
typedef long long ll;
using vi=vector<ll>;
template<class T> void out(T a){cout<<a<<endl;}
void solve() {
  ll n,k; cin>>n>>k;
  vi t(n);
  rep(i,n) cin>>t[i];
  if(k==n){
    out(n);
    return;
  }
  vi u; //間隔
  rep(i,n-1) u.eb(t[i+1]-t[i]-1);
  sort(all(u));
  reverse(all(u));
  ll remove=0;
  rep(i,k-1) remove+=u[i];
  out(t[n-1]-t[0]+1-remove);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}

<50点>(O(NK))(solve部分のみ)
void solve() {
  ll n,k; cin>>n>>k;
  vi t(n);
  rep(i,n) cin>>t[i];
  vvi dp(n+2,vi(k+2,0)); //dp[i][j]...i人目までj本までのmin.
  if(k==n){
    out(n);
    return;
  }
  vi u(n); //差
  REP(i,1,n) u[i]=t[i]-t[i-1]; 
  u[0]=0;
  //outv(u);
  REP(i,1,n+1){
    REP(j,1,k+1){
      if(i==1){
        dp[i][j]=1;
        continue;
      }
      if(j==1){
        dp[i][j]=dp[i-1][j]+u[i-1];
        continue;
      }
      dp[i][j]=min(dp[i-1][j-1]+1,dp[i-1][j]+u[i-1]);
    }
  }
  out(dp[n][k]);
  //outvv(dp);
}

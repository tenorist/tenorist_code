<100点>
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
template<class T> void out(T a){cout<<a<<endl;}
ll a[3005][3005]; //O
ll b[3005][3005]; //I
void solve() {
  //初期化
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  int h,w; cin>>h>>w;
  vector<string> s(h);
  rep(i,h) cin>>s[i];
  for(ll i=h-1; i>=0; i--){
    for(ll j=w-1; j>=0; j--){
      a[i][j]=a[i][j+1];
      if(s[i][j]=='O') a[i][j]++;
    }
  }
  for(ll j=w-1; j>=0; j--){
    for(ll i=h-1; i>=0; i--){
      b[i][j]=b[i+1][j];
      if(s[i][j]=='I') b[i][j]++;
    }
  }
  ll ans=0;
  rep(i,h)rep(j,w){
    if(s[i][j]=='J') ans+=a[i][j]*b[i][j];
  }
  out(ans);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}

<50点>
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
template<class T> void out(T a){cout<<a<<endl;}
ll a[3005][3005]; //O
ll b[3005][3005]; //I
void solve() {
  //初期化
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  int h,w; cin>>h>>w;
  vector<string> s(h);
  rep(i,h) cin>>s[i];
  rep(i,h)rep(j,w){
    if(s[i][j]=='J') continue;
    else if(s[i][j]=='O') {
      if(j==0) continue;
      rep(k,j) a[i][k]++;
    }
    else {
      if(i==0) continue;
      rep(k,i) b[j][k]++;
    }
  }
  ll ans=0;
  rep(i,h)rep(j,w){
    if(s[i][j]=='J') ans+=a[i][j]*b[j][i];
  }
  out(ans);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}

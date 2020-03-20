#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
typedef long long ll;
template<class T> void out(T a){cout<<a<<endl;}
void solve(){
  string s;
  cin>>s;
  ll a=s.size();
  ll n=a*(a-1)/2;
  ll b;
  char c='a';
  rep(i,26){
    ll p=0;
    rep(j,a) if(c==s[j]) p++;
    b+=p*(p-1)/2;
    c++;
  }
  out(n-b+1);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}

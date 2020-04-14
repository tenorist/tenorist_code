#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
#define pi M_PI
#define PQ(T) priority_queue<T>
#define SPQ(T) priority_queue<T,vector<T>,greater<T>>
using ll=long long;
using P=pair<ll,ll>;
using PP=tuple<ll,ll,ll>;
using S=multiset<ll>;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
const double eps=1e-10;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<'\n';}
template<class T> void outvp(T v){rep(i,v.size())cout<<'('<<v[i].fi<<','<<v[i].se<<')';cout<<'\n';}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
template<class T> bool isin(T x,T l,T r){return (l)<=(x)&&(x)<=(r);}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return(a/gcd(a,b))*(b/gcd(a,b))*gcd(a,b);}
ll modpow(ll a,ll b){a%=mod;if(b==0)return 1;if(b&1)return a*modpow(a,b-1)%mod;ll k=modpow(a,b/2);return k*k%mod;}
void decimal(int x){cout<<fixed<<setprecision(x);}
vi calc(ll x){vi res;while(x>0){res.eb(x%10);x/=10;}reverse(all(res));return res;}
/*
struct mint {
  ll x;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const {return mint(-x);}
  mint& operator+=(const mint a) {if((x+=a.x)>=mod) x-=mod;return *this;}
  mint& operator-=(const mint a) {if((x+=mod-a.x)>=mod) x-=mod;return *this;}
  mint& operator*=(const mint a) {(x*=a.x)%=mod;return *this;}
  mint operator+(const mint a) const {return mint(*this)+=a;}
  mint operator-(const mint a) const {return mint(*this)-=a;}
  mint operator*(const mint a) const {return mint(*this)*=a;}
  mint pow(ll t) const {
    if(!t) return 1;
    mint a=pow(t>>1);
    a*=a;
    if(t&1) a*=*this;
    return a;
  }
  // for prime mod
  mint inv() const {return pow(mod-2);}
  mint& operator/=(const mint a) {return *this*=a.inv();}
  mint operator/(const mint a) const {return mint(*this)/=a;}
};
istream& operator>>(istream& is,const mint& a) {return is>>a.x;}
ostream& operator<<(ostream& os,const mint& a) {return os<<a.x;}
*/
void solve() {
  ll n;
  cin>>n;
  vi a(n);
  rep(i,n) cin>>a[i];
  //pair<PP,ll> dp
  vvi dp(3,vi(n+1,0));
  //dp[0][0]=0; dp[1][0]=0; dp[2][0]=0;
  rep(i,n){
    ll p=dp[0][i],q=dp[1][i],r=dp[2][i];
    if(a[i]==p) p++;
    else if(a[i]==q) q++;
    else r++;
    vi v={p,q,r};
    sort(all(v));
    reverse(all(v));
    dp[0][i+1]=v[0]; dp[1][i+1]=v[1]; dp[2][i+1]=v[2];
  }
  ll ans=1;
  rep(j,n){
    ll cnt=0;
    rep(i,3){
      if(a[j]==dp[i][j]) cnt++;
    }
    ans=(ans*cnt)%mod;
  }
  //outvv(dp);
  out(ans);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}

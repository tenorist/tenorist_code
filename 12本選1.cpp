//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define NP next_permutation
#define pb push_back
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
#define pi M_PI
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef multiset<ll> S;
typedef priority_queue<ll> PQ;
typedef priority_queue<P,vector<P>,greater<P>> SPQ;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;

const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;

template<class T> bool chmin(T&a,T b){if(a>b){a=b; return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b; return true;}return false;}
template<class T> void decimal(T a){cout<<fixed<<setprecision(a);}
template<class T> void out(T a){cout<<a<<endl;}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<endl;}
template<class T> void outvp(T v){rep(i,v.size())outp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<endl;}
template<class T> void outvv(T v){rep(i,v.size()){rep(j,v[i].size()){if(j)cout<<' ';cout<<v[i][j];}cout<<endl;}}

void YesNo(bool a){if(a) out("Yes"); else out("No");}
void yesno(bool a){if(a) out("yes"); else out("no");}
void YESNO(bool a){if(a) out("YES"); else out("NO");}
ll GCD(ll a,ll b){if(b==0) return a; return GCD(b,a%b);}
ll LCM(ll a,ll b){return(a/GCD(a,b))*(b/GCD(a,b))*GCD(a,b);}
ll POW(ll a,ll b){ll c=1; while(b>0){if(b&1){c=a*c %mod;}a=a*a %mod;b>>=1;}return c;}
vi calc(ll x){vi res; while(x>0){res.eb(x%10);x/=10;}reverse(all(res)); return res;}

void solve() {
  string s;
  cin>>s;
  ll n=s.size();
  vector<P> v;
  ll a,b;
  //if(i==n-1)...無意味
  rep(i,n-1){
    if(s[i-1]!='O'&&s[i]=='O') a=i;
    if(s[i]=='O'&&s[i+1]!='O'){
      b=i;
      if(b-a+1<=a&&b-a+1<=n-b-1) v.eb(make_pair(a,b));
    }
  }
  //outvp(v);
  ll ans=0;
  for(auto x:v){
    ll a,b,c;
    tie(a,b)=x;
    c=b-a+1;
    bool f=true;
    REP(i,a-c,a) if(s[i]!='J') f=false;
    REP(i,b+1,b+c+1) if(s[i]!='I') f=false;
    if(f) chmax(ans,c);
  }
  out(ans);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}

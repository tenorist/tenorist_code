#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,k,n) for(int i=k;i<(int)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
using vi=vector<int>;
template<class T> void out(T a){cout<<a<<endl;}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<endl;}

void solve() {
  int n;
  cin>>n;
  vi a(2*n),b(2*n),c;
  string s="";
  rep(i,2*n) cin>>a[i];
  rep(i,2*n) cin>>b[i];
  rep(i,2*n){
    char p,q;
    if(a[i]<b[i]){p='A';q='B';}
    else{p='B';q='A';}
    if(i==0){c.eb(min(a[i],b[i]));s+=p;}
    else{
      if(max(a[i],b[i])<c[i-1]){
        out(-1);
        return;
      }
      else if(min(a[i],b[i])<c[i-1]){
        c.eb(max(a[i],b[i]));
        s+=q;
      }
      else{c.eb(min(a[i],b[i]));s+=p;}
    }
  }
  // 以下、補正の作業
  int f=0,g,h;
  rep(i,2*n){
    if(s[i]=='A') f++;
  }
  g=2*n-f;
  h=(max(f,g)-min(f,g))/2;
  //if(h==0){goto SKIP;}
  char k,l; //kは少ない方
  vi x,y; //xは少ない方
  if(f<g){k='A';l='B';x=a;y=b;}
  else{k='B';l='A';x=b;y=a;}
  rep(i,2*n){
    if(h==0) break;
    if(s[i]==k) continue;
    if(i==0){
      if(x[0]<c[1]){s[0]=k;c[0]=x[0];h--;}
    }
    else if(i==2*n-1){
      if(x[2*n-1]>c[2*n-2]){s[2*n-1]=k;c[2*n-1]=x[2*n-1];h--;}
    }
    else{
      if(c[i-1]<x[i]&&x[i]<c[i+1]){s[i]=k;c[i]=x[i];h--;}
    }
  }
  if(h>0){
    out(-1);
    return;
  }
//SKIP:
  //outv(c);
  out(s);
  return;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}

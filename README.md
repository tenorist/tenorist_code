# tenorist_code
勉強になったコード集


tenoristです。趣味で競プロをやっています。
AtCoder、JOI、その他の問題を解き、勉強になったと思うもののコードを
（主に）あげています。

```cpp
struct UnionFind {
  vi d;
  UnionFind(ll n=0):d(n,-1){}
  ll find(ll x) {
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
  //連結成分の個数
  ll size(ll x) {return -d[find(x)];}
};
```

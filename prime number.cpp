#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <climits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <numeric>
#include <random>
using namespace std;

#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define NP next_permutation;
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define puf push_front
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> PP;
typedef multiset<ll> S;
typedef priority_queue<ll> PQ;
typedef priority_queue<P, vector<P>, greater<P>> SPQ;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

const ll inf = 1001001001001001;
const int INF = 1001001001;
const int mod = 1000000007;
const double pi = 3.14159265358979323846;

template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> void decimal(T a) { cout << fixed << setprecision(a); }
template<class T> void out(T a) { cout << a << endl; }
template<class T> void outp(T a) { cout << '(' << a.fi << ',' << a.se << ')' << endl; }
template<class T> void outvp(T v) { rep(i, v.size())outp(v[i]); }
template<class T> void outv(T v) { rep(i, v.size()) { if (i)cout << ' '; cout << v[i]; }cout << endl; }
template<class T> void outvv(T v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j)cout << ' '; cout << v[i][j]; }cout << endl; } }

void YesNo(bool a) { if (a) out("Yes"); else out("No"); }
void yesno(bool a) { if (a) out("yes"); else out("no"); }
void YESNO(bool a) { if (a) out("YES"); else out("NO"); }
ll GCD(ll a, ll b) { ll c; while (b != 0) { c = a % b; a = b; b = c; } return a; }
ll LCM(ll a, ll b) { return(a / GCD(a, b)) * (b / GCD(a, b)) * GCD(a, b); }
ll POW(ll a, ll b) { ll c = 1; while (b > 0) { if (b & 1) { c = a * c % mod; } a = a * a % mod; b >>= 1; } return c; }
vi calc(ll x) { vi res; while (x > 0) { res.pb(x % 10); x /= 10; } reverse(all(res)); return res; }

void solve() {
    ll N, ans = 0; cin >> N;
    vector<bool> prime(N+1,true); // ìYÇ¶éöÇ∆êîéöÇëŒâû
    prime[0] = false; prime[1] = false; // 0Ç∆1ÇÕëfêîÇ≈Ç»Ç¢
    REP(i, 2, sqrt(N) + 2) {
        if (prime[i] == true) {
            out(i); ans++;
            prime[i] = false;
            REP(j, 2, N / i + 1) {
                if (prime[i * j] == true) {
                    prime[i * j] = false;
                }
            }
        }
    }
    rep(i, N) {
        if (prime[i] == true) {
            out(i); ans++;
        }
    }
    cout << "all " << ans << endl;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}

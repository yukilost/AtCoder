#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for(int i = 0; i < (n); i++)
#define REPS(i, n)  for(int i = 1; i <= (n); i++)
#define RREP(i, n)  for(int i = (n)-1; i >= 0; i--)
#define RREPS(i, n) for(int i = (n); i > 0; i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl

using ll  = long long;
using pi  = pair<int, int>;
using pl  = pair<ll, ll>;
using vi  = vector<int>;
using vl  = vector<ll>;
using vs  = vector<string>;
using vb  = vector<bool>;
using vvi = vector<vi>;
using vvl = vector<vl>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll  INFL = 1e18;
const double PI = 3.14159265359;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

ll modinv(ll a, ll mod)
{
    ll b = mod, u = 1, v = 0;
    while(b)
    {
        ll t = a/b;
        a -= t*b; swap(a, b);
        u -= t*v; swap(u, v);
    }
    u %= mod;
    if(u < 0) u += mod;
    return u;
}

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll T; cin >> T;
    vl ans(T);
    REP(i, T)
    {
        ll N, S, K; cin >> N >> S >> K;
        ll n = (-S+N)%N*modinv(K, N)%N / gcd(N, K);
        if((S+n*K%N)%N != 0) ans[i] = -1;
        else ans[i] = n;
    }
    REP(i, T) cout << ans[i] << endl;
}

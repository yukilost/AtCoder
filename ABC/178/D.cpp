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

ll modpow(ll a, ll n, ll mod)
{
    ll res = 1;
    while(n > 0)
    {
        if(n&1) res = res*a % mod;
        a = a*a % mod;
        n >>= 1;
    }
    return res;
}

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

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll fact[5000];
    fact[0] = fact[1] = 1;
    for(ll i = 2; i < 5000; i++) fact[i] = fact[i-1]*i % MOD;

    ll S; cin >> S;
    ll ans = 0;
    for(ll len = 1; len * 3 <= S; len++)
    {
        ll tmp = S-3*len;
        ans += fact[len-1+tmp] * modinv(fact[len-1] * fact[tmp] % MOD, MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}

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

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

ll modpow(ll a, ll x)
{
    ll res = 1;
    while(x > 0)
    {
        if(x & 1) res *= a;
        res %= MOD;
        a = a * a;
        a %= MOD;
        x >>= 1;
    }
    return res;
}

ll modinv(ll n)
{
    return modpow(n, MOD-2) % MOD;
}

const int N = 200010;
ll fact[N];

int main()
{
    fact[0] = 1;
    for(ll i = 1; i < N; i++) fact[i] = fact[i-1]*i%MOD;
    
    ll H, W, A, B; cin >> H >> W >> A >> B;
    ll ans = 0;
    REPS(i, H-A)
    {
        if(i == H-A) W++;
        ans += fact[B+i-1] * modinv(fact[B]*fact[i-1]%MOD)%MOD * fact[W-B-2+H-i]%MOD * modinv(fact[W-B-2]*fact[H-i]%MOD)%MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}
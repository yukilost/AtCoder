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

const ll MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll  INFL = 1e18;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

ll fact[10000];

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

ll modinv(ll a)
{
    return modpow(a, MOD-2LL);
}

ll modcomb(ll n, ll r)
{
    if(n < 0 || r < 0 || n < r) return 0;
    return fact[n] * modinv(fact[n-r]*fact[r]%MOD) % MOD;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    
    fact[0] = 1;
    for(ll i = 1; i < 10000; i++) fact[i] = i * fact[i-1] % MOD;

    // 部分点
    ll R, C, X, Y, D, L; cin >> R >> C >> X >> Y >> D >> L;
    if(X*Y == D+L)
    {
        cout << (R-X+1) * (C-Y+1) % MOD * modcomb(D+L, D) % MOD << endl;
        return 0;
    }

    // 領域の位置
    ll ans = (R-X+1) * (C-Y+1) % MOD;

    // 領域内の配置
    if(X == 1 || Y == 1)
    {
        ans = ans * modcomb(X*Y-2, D+L-2) % MOD;
    }
    else
    {
        ll num = 0;
        num += modcomb(X*Y-4, D+L-4) % MOD; num %= MOD; // 4
        num += 4*modcomb(X*Y-4, D+L-3) % MOD; num %= MOD; // 3
        num += 2*modcomb(X*Y-4, D+L-2) % MOD; num %= MOD; // 対角
        //num += 2*(X-2)*modcomb(X*Y-5, D+L-3) % MOD; num %= MOD; // 隣接
        num += 2*(modcomb(X*Y-4, D+L-2) - modcomb(X*Y-2-X, D+L-2) + MOD) % MOD; num %= MOD;
        //num += 2*(Y-2)*modcomb(X*Y-5, D+L-3) % MOD; num %= MOD; // 隣接
        num += 2*(modcomb(X*Y-4, D+L-2) - modcomb(X*Y-2-Y, D+L-2) + MOD) % MOD; num %= MOD;
        //num += 4*(X-2)*(Y-2)*modcomb(X*Y-6, D+L-3) % MOD; num %= MOD; // 1
        num += 4*(modcomb(X*Y-4, D+L-1) - modcomb(X*Y-2-X, D+L-1) - modcomb(X*Y-2-Y, D+L-1) + modcomb(X*Y-X-Y, D+L-1) + MOD) % MOD; num %= MOD;
        //num += (X-2)*(X-2)*(Y-2)*(Y-2)*modcomb(X*Y-8, D+L-4) % MOD; num %= MOD; // 0
        num += modcomb(X*Y-4, D+L) % MOD; num %= MOD;
        num -= 2*modcomb(X*Y-2-X, D+L)%MOD + 2*modcomb(X*Y-2-Y, D+L)%MOD; num = (num + MOD) % MOD;
        num += modcomb(X*Y-2*X, D+L) + modcomb(X*Y-2*Y, D+L) + 4*modcomb(X*Y-X-Y, D+L)%MOD; num %= MOD;
        num -= 2*modcomb(X*Y-2*X-Y+2, D+L)%MOD + 2*modcomb(X*Y-2*Y-X+2, D+L)%MOD; num = (num + MOD) % MOD;
        num += modcomb((X-2)*(Y-2), D+L); num %= MOD;
        ans = ans * num % MOD;

    }

    // デスクとラックの配置
    ans = ans * modcomb(D+L, D) % MOD;

    cout << ans << endl;
}
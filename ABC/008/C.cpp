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

double fact[100000];
double comb(ll n, ll r)
{
    if(n < 0 || r < 0 || n < r) return 0;
    return fact[n]/(fact[n-r]*fact[r]);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll N; cin >> N;
    vl C(N); REP(i, N) cin >> C[i];

    fact[0] = fact[1] = 1;
    for(ll i = 2; i < 100000; i++) fact[i] = i*fact[i-1];

    vvl divide(N);
    REP(i, N)
    {
        for(ll d = 1; d*d <= C[i]; d++)
        {
            if(C[i] % d == 0)
            {
                divide[i].pb(d);
                if(d != C[i]/d) divide[i].pb(C[i]/d);
            }
        }
    }

    map<ll, ll> count_coins;
    REP(i, N) count_coins[C[i]]++;

    double ans = 0;
    REP(i, N)
    {
        REP(j, N)
        {
            ll c = 0;
            REP(k, (int)divide[j].size())
            {
                c += count_coins[divide[j][k]];
                if(divide[j][k] == C[j] && count_coins[divide[j][k]] > 0) c--;
            }
            for(ll k = 0; k <= i; k += 2)
            {
                ans += comb(c, k) * comb(N-1-c, i-k) * fact[i] * fact[N-1-i] / fact[N];
            }
        }
    }
    cout << ans << endl;
}

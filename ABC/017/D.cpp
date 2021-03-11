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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll N, M; cin >> N >> M;
    vl f(N); REP(i, N) cin >> f[i];
    vl dp(N+1, 0);
    map<ll, ll> m;
    m[f[0]] = 1;
    ll sum = 2;
    dp[0] = dp[1] = 1;
    ll l = 0;
    for(ll r = 1; r < N; r++)
    {
        m[f[r]]++;
        while (m[f[r]] == 2)
        {
            sum -= dp[l];
            sum %= MOD;
            if(sum < 0) sum += MOD;
            m[f[l++]]--;
        }
        dp[r+1] = sum % MOD;
        if(dp[r+1] < 0) dp[r+1] += MOD;
        sum += dp[r+1];
        sum %= MOD;
        if(sum < 0) sum += MOD;
    }
    cout << dp[N] << endl;
}
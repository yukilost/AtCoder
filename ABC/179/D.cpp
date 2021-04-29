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

//const int MOD = 1e9 + 7;
const int MOD = 998244353;
const int INF = 1e9 + 7;
const ll  INFL = 1e18;
const double PI = 3.14159265359;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, K; cin >> N >> K;
    vl L(K), R(K); REP(i, K) cin >> L[i] >> R[i];
    vl dp(N+2, 0);
    dp[1] = 1;
    ll sum = 0;
    REPS(i, N)
    {
        sum += dp[i];
        sum = (sum+MOD)%MOD;
        REP(j, K)
        {
            if(i+L[j] < N+2) dp[i+L[j]] = (dp[i+L[j]]+sum+MOD)%MOD;
            if(i+R[j]+1 < N+2) dp[i+R[j]+1] = (dp[i+R[j]+1]-sum+MOD)%MOD;
        }
    }
    cout << dp[N]%MOD << endl;
}

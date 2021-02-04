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

    ll N, W; cin >> N >> W;
    ll w[N], v[N]; REP(i, N) cin >> w[i] >> v[i];

    ll tmp = w[0];
    REP(i, N) w[i] -= tmp;
    ll dp[N+1][310]; REP(i, N+1) REP(j, 310) dp[i][j] = 0;
    REP(i, N)
    {
        RREP(j, i+1)
        {
            RREP(k, 310)
            {
                if(k+w[i] < 310) chmax(dp[j+1][k+w[i]], dp[j][k]+v[i]);
            }
        }
    }

    ll ans = 0;
    REP(i, N+1) REP(j, 310) if(tmp*i+j <= W) chmax(ans, dp[i][j]);
    cout << ans << endl;
}
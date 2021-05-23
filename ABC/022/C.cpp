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
//const int MOD = 998244353;
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

    ll N, M; cin >> N >> M;
    vvl d(N, vl(N, INFL));
    REP(i, N) d[i][i] = 0;
    REP(i, M)
    {
        ll u, v, l; cin >> u >> v >> l;
        u--, v--;
        d[u][v] = l;
        d[v][u] = l;
    }

    REP(k, N)
    {
        REP(i, N)
        {
            REP(j, N)
            {
                if(i == 0 || j == 0 || k == 0) continue;
                chmin(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    ll ans = INFL;
    REPS(i, N-1)
    {
        for(int j = i+1; j < N; j++)
        {
            chmin(ans, d[0][i] + d[i][j] + d[j][0]);
        }
    }
    if(ans == INFL) cout << -1 << endl;
    else cout << ans << endl;
}

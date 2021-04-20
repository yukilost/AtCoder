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

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, M; cin >> N >> M;
    vvi G(N);
    REP(i, M)
    {
        int A, B; cin >> A >> B;
        A--; B--;
        G[A].pb(B);
        G[B].pb(A);
    }
    int K; cin >> K;
    vi C(K); REP(i, K) cin >> C[i], C[i]--;
    map<int, int> m;
    REP(i, K)
    {
        m[C[i]] = i;
    }

    vvi dist(K, vi(N, INF));
    REP(i, K)
    {
        dist[i][C[i]] = 0;
        queue<int> q;
        q.push(C[i]);
        while(!q.empty())
        {
            int p = q.front(); q.pop();
            for(int n: G[p]) if(chmin(dist[i][n], dist[i][p]+1)) q.push(n);
        }
    }

    vvi kdist(K, vi(K));
    REP(i, K)
    {
        REP(j, K) kdist[i][j] = dist[i][C[j]];
    }

    vvi dp(1<<K, vi(K, INF));
    REP(i, K) dp[1<<i][i] = 1;
    for(int i = 1; i < (1<<K); i++)
    {
        REP(j, K)
        {
            REP(k, K)
            {
                chmin(dp[i|(1<<k)][k], dp[i][j]+kdist[j][k]);
            }
        }
    }
    int ans = *min_element(ALL(dp[(1<<K)-1]));
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

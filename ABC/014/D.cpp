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

vvi G;
vi dist;
vvi anc;

void dfs(int n, int d)
{
    dist[n] = d;
    for(int t : G[n])
    {
        if(dist[t] == INF) 
        {
            anc[0][t] = n;
            dfs(t, d+1);
        }
    }
}

int lca(int x, int y)
{
    int x_t = dist[x];
    int y_t = dist[y];
    int t = x_t - y_t; 
    if(t < 0)
    {
        swap(x, y);
        t = -t;
    }
    REP(k, 100)
    {
        if(t & 1) x = anc[k][x];
        t >>= 1;
    }
    if(x == y) return x;
    RREP(i, 100)
    {
        int px = anc[i][x];
        int py = anc[i][y];
        if(px != py)
        {
            x = px;
            y = py;
        }
    }
    return anc[0][x];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int N; cin >> N;
    G = vvi(N);
    dist = vi(N, INF);
    anc = vvi(100, vi(N, -1));
    REP(i, N-1)
    {
        int x, y; cin >> x >> y;
        x--; y--;
        G[x].pb(y);
        G[y].pb(x);
    }
    dfs(0, 0);
    anc[0][0] = 0;
    REPS(k, 99)
    {
        REP(i, N)
        {
            anc[k][i] = anc[k-1][anc[k-1][i]];
        }
    }
    int Q; cin >> Q;
    vi a(Q), b(Q);
    REP(i, Q)
    {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    REP(i, Q)
    {
        int c = lca(a[i], b[i]);
        cout << dist[a[i]] + dist[b[i]] - 2*dist[c] + 1 << endl;
    }
}

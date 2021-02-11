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

int N;
vvi G;
vi dist_from_0;
vb visited;

void dfs(int n, int d)
{
    dist_from_0[n] = d;
    for(int next : G[n])
    {
        if(dist_from_0[next] == INF) dfs(next, d+1);
    }
}

int dfs2(int n, int d)
{
    visited[n] = true;
    int res = 0;
    for(int next: G[n])
    {
        if(!visited[next] && dist_from_0[next] > d+1) res += dfs2(next, d+1);
    }
    return res+1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    cin >> N;
    G.resize(N);
    dist_from_0.resize(N, INF);
    visited.resize(N, false);
    REP(i, N-1)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    dfs(0, 0);
    int c = dfs2(N-1, 0);
    if(c < N-c) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
}

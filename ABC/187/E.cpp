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

int N;
vvi G;
vi d;

void dfs(int n)
{
    for(int next : G[n])
    {
        if(chmin(d[next], d[n]+1)) dfs(next);
    }
}

void dfs2(int n, vl& u, vl& v)
{
    for(int next: G[n])     
    {
        if(v[next] == INFL)
        {
            v[next] = v[n] + u[next];
            dfs2(next, u, v);
        }
    }
}

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N;
    vector<pi> edge(N-1);
    G = vvi(N);
    REP(i, N-1)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        edge[i] = mp(a, b);
        G[a].pb(b);
        G[b].pb(a);
    }
    d = vi(N, INF);
    d[0] = 0;
    dfs(0);

    int Q; cin >> Q;
    vl value(N, 0);
    ll sum = 0;
    REP(i, Q)
    {
        int t, e, x; cin >> t >> e >> x;
        e--;
        int a, b;
        tie(a, b) = edge[e];
        if(t == 1)
        {
            if(d[a] < d[b]) value[b] -= x, sum += x;
            else value[a] += x;
        }
        else
        {
            if(d[a] < d[b]) value[b] += x;
            else value[a] -= x, sum += x;
        }
    }

    vl ans(N, INFL);
    ans[0] = 0;
    dfs2(0, value, ans);
    REP(i, N) cout << sum + ans[i] << endl;
}

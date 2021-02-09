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

vi node;

int root(int x)
{
    if(node[x] == x) return x;
    return node[x] = root(node[x]);
}

void unite(int x, int y)
{
    int rx = root(x);
    int ry = root(y);
    node[rx] = ry;
}

bool same(int x, int y)
{
    return root(x) == root(y);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll N; cin >> N;
    node.resize(N); REP(i, N) node[i] = i;
    vector<pair<ll, int>> x(N), y(N);
    REP(i, N)
    {
        cin >> x[i].first >> y[i].first;
        x[i].second = y[i].second = i;
    }
    sort(ALL(x));
    sort(ALL(y));
    vector<tuple<ll, int, int>> edges;
    REP(i, N-1)
    {
        edges.push_back(mt(x[i+1].first-x[i].first, x[i].second, x[i+1].second));
        edges.push_back(mt(y[i+1].first-y[i].first, y[i].second, y[i+1].second));
    }

    sort(ALL(edges));
    ll ans = 0;
    REP(i, (int)edges.size())
    {
        ll cost; 
        int s, t;
        tie(cost, s, t) = edges[i];
        if(!same(s, t))
        {
            unite(s, t);
            ans += cost;
        }
    }
    cout << ans << endl;
}

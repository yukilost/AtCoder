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

    int N, M; cin >> N >> M;
    int a[M], b[M]; REP(i, M) cin >> a[i] >> b[i], a[i]--, b[i]--;
    node.resize(N);

    int ans = 0;
    REP(i, M)
    {
        REP(j, N) node[j] = j;
        REP(j, M)
        {
            if(i == j) continue;
            if(!same(a[j], b[j])) unite(a[j], b[j]);
        }
        bool isBridge = false;
        REP(j, N) if(!same(0, j)) isBridge = true;
        ans += isBridge;
    }
    cout << ans << endl;
}

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

    ll N, M, X, Y; cin >> N >> M >> X >> Y;
    X--; Y--;
    vector<vector<pi>> G(N);
    vector<pl> edges(M);
    REP(i, M)
    {
        ll a, b, t, k; cin >> a >> b >> t >> k;
        a--; b--;
        G[a].pb(mp(b, i));
        G[b].pb(mp(a, i));
        edges[i] = mp(t, k);
    }
    vl dist(N, INFL);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push(mp(0, X));
    dist[X] = 0;
    while (!q.empty())
    {
        pair<ll, int> p = q.top(); q.pop();
        ll time; int pos;
        tie(time, pos) = p;

        if(dist[pos] < time) continue;
        for(auto e: G[pos])
        {
            int next = e.first;
            ll t, k;
            tie(t, k) = edges[e.second];
            if(chmin(dist[next], (dist[pos]+k-1)/k*k+t)) q.push(mp(dist[next], next));
        }
    }
    if(dist[Y] == INFL) cout << -1 << endl;
    else cout << dist[Y] << endl;
}

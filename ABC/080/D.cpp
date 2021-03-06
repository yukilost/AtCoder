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
    
    int N, C; cin >> N >> C;    
    vector<tuple<int, int, int>> v(N);
    REP(i, N)
    {
        int s, t, c; cin >> s >> t >> c;
        v[i] = mt(c, s, t);
    }
    sort(ALL(v));

    vector<pi> p;
    int start = get<1>(v[0]), end = get<2>(v[0]);
    for(int i = 1; i < N; i++)
    {
        if(get<0>(v[i-1]) == get<0>(v[i]) && end == get<1>(v[i])) end = get<2>(v[i]);
        else
        {
            p.pb(mp(2*start-1, 2*end));
            start = get<1>(v[i]);
            end = get<2>(v[i]);
        }
    }
    p.pb(mp(2*start-1, 2*end));

    vi imos(200010, 0);
    REP(i, (int)p.size())
    {
        imos[p[i].first]++;
        imos[p[i].second]--;
    }
    REP(i, 200009) imos[i+1] += imos[i];
    int ans = 0;
    REP(i, 200010) chmax(ans, imos[i]);
    cout << ans << endl;
}

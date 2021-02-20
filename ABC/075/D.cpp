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
const ll  INFL = 5e18;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll N, K; cin >> N >> K;
    vector<pl> p(N); REP(i, N) cin >> p[i].first >> p[i].second;
    sort(ALL(p));
    ll ans = INFL;
    for(int l = 0; l < N; l++)
    {
        for(int r = l+1; r < N; r++)
        {
            for(int u = 0; u < N; u++)
            {
                for(int d = u+1; d < N; d++)
                {
                    ll x = p[l].first;
                    ll y = p[r].first;
                    ll z = p[u].second;
                    ll w = p[d].second;
                    ll c = 0;
                    for(auto itr = lower_bound(ALL(p), mp(x, min(z, w))); itr != upper_bound(ALL(p), mp(y, max(z, w))); itr++)
                    {
                        if(min(z, w) <= itr->second && itr->second <= max(z, w)) c++;
                    }
                    if(c >= K) chmin(ans, (y-x)*(abs(z-w)));
                }
            }
        }
    }
    cout << ans << endl;
}

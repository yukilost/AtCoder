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

    ll N, H; cin >> N >> H;
    ll A, B, C, D, E; cin >> A >> B >> C >> D >> E;

    if(H > N*E)
    {
        cout << 0 << endl;
        return 0;
    }

    ll ans = INFL;
    for(ll i = 0; i <= N; i++)
    {
        ll h = H + B*i;
        ll c = A*i;
        ll n = N-i;

        if(h > E*n)
        {
            chmin(ans, c);
            continue;
        }

        ll j = (E*n-h)/(D+E)+1;

        if(!(0 <= j && j <= n)) continue;
        c += C*j;
        chmin(ans, c);
    }
    for(ll j = 0; j <= N; j++)
    {
        ll h = H + D*j;
        ll c = C*j;
        ll n = N-j;

        if(h > E*n)
        {
            chmin(ans, c);
            continue;
        }

        ll i = (E*n-h)/(B+E)+1;

        if(!(0 <= i && i <= n)) continue;
        c += A*i;
        chmin(ans, c);
    }
    cout << ans << endl;
}

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

long double memo[2000][2000];

long double comb(int n, int r)
{
    if(n < r || n < 0 || r < 0) return 0;
    if(memo[n][r] != 0) return memo[n][r];
    return memo[n][r] = (comb(n-1, r) + comb(n-1, r-1)) / 2;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    memset(memo, 0, sizeof(memo));
    REP(i, 2000) memo[0][0] = 1;
    int N, D, X, Y; cin >> N >> D >> X >> Y;
    if(X % D != 0 || Y % D != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    X = abs(X/D);
    Y = abs(Y/D);
    if((N-X-Y) % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    long double ans = 0;
    for(int k = 0; k <= N; k++)
    {
        if((k+X) % 2 || (N-k+Y) % 2) continue;
        int x = (k+X)/2;
        int y = (N-k+Y)/2;
        int z = k-x;
        int w = N-k-y;
        if(z < 0 || w < 0) continue;
        ans += comb(N, k) * comb(k, x) * comb(N-k, y);
    }
    cout << ans << endl;
}

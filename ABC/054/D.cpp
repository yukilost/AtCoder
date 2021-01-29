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

int dp[50][500][500];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int N, Ma, Mb; cin >> N >> Ma >> Mb;
    REP(i, 50) REP(j, 500) REP(k, 500) dp[i][j][k] = 5000;
    dp[0][0][0] = 0;
    REP(i, N)
    {
        int a, b, c; cin >> a >> b >> c;
        REP(j, 500)
        {
            REP(k, 500)
            {
                chmin(dp[i+1][j][k], dp[i][j][k]);
                if(j+a < 500 && k+b < 500) chmin(dp[i+1][j+a][k+b], dp[i][j][k]+c);
            }
        }
    }

    int ans = INF;
    int c = 1;
    while(Ma*c < 500 && Mb*c < 500)
    {
        chmin(ans, dp[N][Ma*c][Mb*c]);
        c++;
    }
    if(ans == 5000) cout << -1 << endl;
    else cout << ans << endl;
}

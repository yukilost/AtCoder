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
//const int MOD = 998244353;
const int INF = 1e9 + 7;
const ll  INFL = 1e18;
const double PI = 3.14159265359;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

ll dp[3001][3001][4];

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int R, C, K; cin >> R >> C >> K;
    vvl v(R+1, vl(C+1, INFL));
    REP(i, K)
    {
        int r, c; cin >> r >> c;
        r--; c--;
        ll t; cin >> t;
        v[r][c] = t;
    }

    memset(dp, 0, sizeof(dp));

    REP(i, R+1)
    {
        REP(j, C+1)
        {
            REP(k, 4)
            {
                if(j<C) chmax(dp[i][j+1][k], dp[i][j][k]);
                if(i<R) chmax(dp[i+1][j][0], dp[i][j][k]);
                if(v[i][j] != INFL)
                {
                    if(j<C&&k+1<4) chmax(dp[i][j+1][k+1], dp[i][j][k] + v[i][j]);
                    if(i<R&&k<3) chmax(dp[i+1][j][0], dp[i][j][k] + v[i][j]);
                }
            }
        }
    }
    cout << max({dp[R][C][0], dp[R][C][1], dp[R][C][2], dp[R][C][3]}) << endl;
}

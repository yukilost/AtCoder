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
    
    ll H, W; cin >> H >> W;
    vs S(H); REP(i, H) cin >> S[i];
    vvl dp(H, vl(W, 0));
    vvl X(H, vl(W, 0));
    vvl Y(H, vl(W, 0));
    vvl Z(H, vl(W, 0));
    dp[0][0] = 1;
    REP(i, H)
    {
        REP(j, W)
        {
            if(i == 0 && j == 0) continue;
            if(j > 0 && S[i][j] == '.') X[i][j] = (X[i][j-1]+dp[i][j-1]) % MOD;
            if(i > 0 && S[i][j] == '.') Y[i][j] = (Y[i-1][j]+dp[i-1][j]) % MOD;
            if(i > 0 && j > 0 && S[i][j] == '.') Z[i][j] = (Z[i-1][j-1]+dp[i-1][j-1]) % MOD;
            if(S[i][j] == '.') dp[i][j] = (X[i][j]+Y[i][j]+Z[i][j]) % MOD;
        }
    }
    cout << dp[H-1][W-1] % MOD << endl;
}


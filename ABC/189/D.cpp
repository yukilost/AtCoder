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
const double PI = 3.14159265;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

vs s;

/*
int f(int n, bool b)
{
    if(n == 0) return 1;
    if(s[n] == "AND")
    {
        if(b) return f(n-1, true);
        else return 2*f(n-1, false) + f(n-1, true);
    }
    else
    {
        if(b) return 2*f(n-1, true) + f(n-1, false);
        else return f(n-1, false);
    }
}
*/

ll dp[61][2];

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N; cin >> N;
    s = vs(N+1); REPS(i, N) cin >> s[i];

    memset(dp, 0, sizeof(dp));

    dp[0][0] = dp[0][1] = 1;
    REPS(i, N)
    {
        if(s[i] == "AND")
        {
            dp[i][0] = 2*dp[i-1][0] + dp[i-1][1];
            dp[i][1] = dp[i-1][1];
        }
        else
        {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = 2*dp[i-1][1] + dp[i-1][0];
        }
    }
    cout << dp[N][1] << endl;
}

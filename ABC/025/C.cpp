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
const ll INF = 1e9 + 7;
const ll  INFL = 1e18;
const double PI = 3.14159265359;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

vvi b;
vvi c;
vvi g;

 int dfs(int n)
{
    if(n == 9)
    {
        int score = 0;
        REP(i, 2) REP(j, 3)
        {
            if(g[i][j] == g[i+1][j]) score += b[i][j];
            else score -= b[i][j];
        }
        REP(i, 3) REP(j, 2)
        {
            if(g[i][j] == g[i][j+1]) score += c[i][j];
            else score -= c[i][j];
        }
        return score;
    }
    int m;
    if(n%2==0)
    {
        m = -INF;
        REP(i, 3)
        {
            REP(j, 3)
            {
                if(g[i][j]!=-1) continue;
                g[i][j] = 0;
                chmax(m, dfs(n+1));
                g[i][j] = -1;
            }
        }
    }
    else
    {
        m = INF;
        REP(i, 3)
        {
            REP(j, 3)
            {
                if(g[i][j]!=-1) continue;
                g[i][j] = 1;
                if(chmin(m, dfs(n+1)));
                g[i][j] = -1;
            }
        }
    }
    return m;
}

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    b = vvi(2, vi(3));
    c = vvi(3, vi(2));
    g = vvi(3, vi(3, -1));
    int sum = 0;
    REP(i, 2) REP(j, 3) cin >> b[i][j], sum += b[i][j];
    REP(i, 3) REP(j, 2) cin >> c[i][j], sum += c[i][j];
    int m = dfs(0);
    cout << (sum+m)/2 << endl; 
    cout << sum-(sum+m)/2 << endl;
}

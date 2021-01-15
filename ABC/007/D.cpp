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

// [1, n]の範囲に4,9が含まれる数字はいくつあるか
ll contain(string n)
{
    if(n == "0") return 0;
    ll dp[(int)n.length()+1][2][2];
    memset(dp, 0, sizeof(dp));
    REP(k, n[0]-'0'+1)
    {
        dp[1][k == n[0]-'0'][k == 4 || k == 9]++;
    }
    REPS(i, (int)n.length()-1)
    {
        REP(j, 2)
        {
            REP(c, 2)
            {
                int l = (j == 1) ? n[i]-'0'+1 : 10;
                REP(k, l)
                {
                    dp[i+1][j && k == l-1][c || k == 4 || k == 9] += dp[i][j][c];
                }
            }
        }
    }

    return dp[(int)n.length()][0][1] + dp[(int)n.length()][1][1];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll A, B; cin >> A >> B;    
    cout << contain(to_string(B)) - contain(to_string(A-1)) << endl;
}

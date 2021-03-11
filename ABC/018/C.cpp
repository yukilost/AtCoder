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

    int r, c, k; cin >> r >> c >> k;    
    vs s(r); REP(i, r) cin >> s[i];
    vvi sum(r, vi(c+1, 0));
    REP(i, r)
    {
        REP(j, c)
        {
            sum[i][j+1] += sum[i][j] + (s[i][j] == 'o');
        }
    }

    int ans = 0;
    for(int i = k-1; i < r-k+1; i++)
    {
        for(int j = k-1; j < c-k+1; j++)
        {
            bool ok = true;
            for(int y = 0; y < k; y++)
            {
                if(sum[i+y][j+k-y]-sum[i+y][j-k+1+y] != 2*(k-y)-1) ok = false;
                if(sum[i-y][j+k-y]-sum[i-y][j-k+1+y] != 2*(k-y)-1) ok = false;
            }
            if(ok) ans++;
        }
    }
    cout << ans << endl;
}

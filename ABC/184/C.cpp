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

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    vi r(2), c(2); REP(i, 2) cin >> r[i] >> c[i];
    vi dr, dc;
    for(int i = -2; i <= 2; i++)
    {
        for(int j = -2; j <= 2; j++)
        {
            dr.pb(i);
            dc.pb(j);
        }
    }
    dr.pb(-3); dc.pb(0);
    dr.pb(3); dc.pb(0);
    dr.pb(0); dc.pb(-3);
    dr.pb(0); dc.pb(3);

    if(r[0] == r[1] && c[0] == c[1])
    {
        cout << 0 << endl;
        return 0;
    }

    bool ok = false;
    REP(i, (int)dr.size())
    {
        if(r[0]+dr[i] == r[1] && c[0]+dc[i] == c[1]) ok = true;
    }
    if(r[0]+c[0] == r[1]+c[1] || r[0]-c[0] == r[1]-c[1]) ok = true;

    if(ok)
    {
        cout << 1 << endl;
        return 0;
    }

    if((r[0]+c[0])%2 == (r[1]+c[1])%2) ok = true;
    REP(i, (int)dr.size())
    {
        if(r[0]+dr[i]+c[0]+dc[i] == r[1]+c[1] || r[0]+dr[i]-c[0]-dc[i] == r[1]-c[1]) ok = true;
        int s = r[0]+dr[i];
        int t = c[0]+dc[i];
        REP(j, (int)dr.size())
        {
            if(s+dr[j] == r[1] && t+dc[j] == c[1]) ok = true;
        }
    }

    if(ok)
    {
        cout << 2 << endl;
        return 0;
    }
    else
    {
        cout << 3 << endl;
    }
}

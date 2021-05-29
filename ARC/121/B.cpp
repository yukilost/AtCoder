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

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N; cin >> N;
    vl c(3);
    vvl a(3);
    map<char, int> idx;
    idx['R'] = 0;
    idx['G'] = 1;
    idx['B'] = 2;
    REP(i, 2*N)
    {
        ll x; cin >> x; 
        char y; cin >> y;
        a[idx[y]].pb(x);
        c[idx[y]]++;
    }
    REP(i, 3) sort(ALL(a[i]));

    if(c[0] %2 == 0 && c[1] %2 == 0 && c[2] %2 == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    ll ans = INFL;
    if(c[0] %2 == 0)
    {
        int x = 0, y = 1, z = 2;
        REP(i, (int)a[y].size())
        {
            int j = lower_bound(ALL(a[z]), a[y][i]) - a[z].begin();
            for(int d=-2; d <= 2; d++)
            {
                if(j+d < 0 || (int)a[z].size() <= j+d) continue;
                chmin(ans, abs(a[z][j+d]-a[y][i]));
            }
        }
        int k = -1;
        ll p = INFL;
        REP(i, (int)a[y].size()) 
        {
            int j = lower_bound(ALL(a[x]), a[y][i]) - a[x].begin();
            for(int d=-2; d <= 2; d++)
            {
                if(j+d < 0 || (int)a[x].size() <= j+d) continue;
                if(chmin(p, abs(a[x][j+d]-a[y][i]))) k = j+d;
            }
        }
        ll q = INFL;
        REP(i, (int)a[z].size()) 
        {
            int j = lower_bound(ALL(a[x]), a[z][i]) - a[x].begin();
            for(int d=-2; d <= 2; d++)
            {
                if(j+d == k || j+d < 0 || (int)a[x].size() <= j+d) continue;
                chmin(q, abs(a[x][j+d]-a[z][i]));
            }
        }
        chmin(ans, p+q);
        k = -1;
        p = INFL;
        REP(i, (int)a[z].size()) 
        {
            int j = lower_bound(ALL(a[x]), a[z][i]) - a[x].begin();
            for(int d=-2; d <= 2; d++)
            {
                if(j+d < 0 || (int)a[x].size() <= j+d) continue;
                if(chmin(p, abs(a[x][j+d]-a[z][i]))) k = j+d;
            }
        }
        q = INFL;
        REP(i, (int)a[y].size()) 
        {
            int j = lower_bound(ALL(a[x]), a[y][i]) - a[x].begin();
            for(int d=-2; d <= 2; d++)
            {
                if(j+d == k || j+d < 0 || (int)a[x].size() <= j+d) continue;
                chmin(q, abs(a[x][j+d]-a[y][i]));
            }
        }
        chmin(ans, p+q);
    }
    else if(c[1] %2 == 0)
    {
        int x = 0, y = 1, z = 2;
        swap(x, y);
        REP(i, (int)a[y].size())
        {
            int j = lower_bound(ALL(a[z]), a[y][i]) - a[z].begin();
            for(int d=-2; d <= 2; d++)
            {
                if(j+d < 0 || (int)a[z].size() <= j+d) continue;
                chmin(ans, abs(a[z][j+d]-a[y][i]));
            }
        }
        int k = -1;
        ll p = INFL;
        REP(i, (int)a[y].size()) 
        {
            int j = lower_bound(ALL(a[x]), a[y][i]) - a[x].begin();
            for(int d=-2; d <= 2; d++)
            {
                if(j+d < 0 || (int)a[x].size() <= j+d) continue;
                if(chmin(p, abs(a[x][j+d]-a[y][i]))) k = j+d;
            }
        }
        ll q = INFL;
        REP(i, (int)a[z].size()) 
        {
            int j = lower_bound(ALL(a[x]), a[z][i]) - a[x].begin();
            for(int d=-2; d <= 2; d++)
            {
                if(j+d == k || j+d < 0 || (int)a[x].size() <= j+d) continue;
                chmin(q, abs(a[x][j+d]-a[z][i]));
            }
        }
        chmin(ans, p+q);
        k = -1;
        p = INFL;
        REP(i, (int)a[z].size()) 
        {
            int j = lower_bound(ALL(a[x]), a[z][i]) - a[x].begin();
            for(int d=-2; d <= 2; d++)
            {
                if(j+d < 0 || (int)a[x].size() <= j+d) continue;
                if(chmin(p, abs(a[x][j+d]-a[z][i]))) k = j+d;
            }
        }
        q = INFL;
        REP(i, (int)a[y].size()) 
        {
            int j = lower_bound(ALL(a[x]), a[y][i]) - a[x].begin();
            for(int d=-2; d <= 2; d++)
            {
                if(j+d == k || j+d < 0 || (int)a[x].size() <= j+d) continue;
                chmin(q, abs(a[x][j+d]-a[y][i]));
            }
        }
        chmin(ans, p+q);
    }
    else
    {
        int x = 0, y = 1, z = 2;
        swap(x, z);
        REP(i, (int)a[y].size())
        {
            int j = lower_bound(ALL(a[z]), a[y][i]) - a[z].begin();
            for(int d=-2; d <= 2; d++)
            {
                if(j+d < 0 || (int)a[z].size() <= j+d) continue;
                chmin(ans, abs(a[z][j+d]-a[y][i]));
            }
        }
        int k = -1;
        ll p = INFL;
        REP(i, (int)a[y].size()) 
        {
            int j = lower_bound(ALL(a[x]), a[y][i]) - a[x].begin();
            for(int d=-2; d <= 2; d++)
            {
                if(j+d < 0 || (int)a[x].size() <= j+d) continue;
                if(chmin(p, abs(a[x][j+d]-a[y][i]))) k = j+d;
            }
        }
        ll q = INFL;
        REP(i, (int)a[z].size()) 
        {
            int j = lower_bound(ALL(a[x]), a[z][i]) - a[x].begin();
            for(int d=-2; d <= 2; d++)
            {
                if(j+d == k || j+d < 0 || (int)a[x].size() <= j+d) continue;
                chmin(q, abs(a[x][j+d]-a[z][i]));
            }
        }
        chmin(ans, p+q);
        k = -1;
        p = INFL;
        REP(i, (int)a[z].size()) 
        {
            int j = lower_bound(ALL(a[x]), a[z][i]) - a[x].begin();
            for(int d=-2; d <= 2; d++)
            {
                if(j+d < 0 || (int)a[x].size() <= j+d) continue;
                if(chmin(p, abs(a[x][j+d]-a[z][i]))) k = j+d;
            }
        }
        q = INFL;
        REP(i, (int)a[y].size()) 
        {
            int j = lower_bound(ALL(a[x]), a[y][i]) - a[x].begin();
            for(int d=-2; d <= 2; d++)
            {
                if(j+d == k || j+d < 0 || (int)a[x].size() <= j+d) continue;
                chmin(q, abs(a[x][j+d]-a[y][i]));
            }
        }
        chmin(ans, p+q);
    }
    
    cout << ans << endl;
}
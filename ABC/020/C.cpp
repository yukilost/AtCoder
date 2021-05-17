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

int H, W, T;
pi S, G;
vs s;

bool C(ll x)
{
    int dh[] = {-1, 0, 1, 0};
    int dw[] = {0, -1, 0, 1};
    vvl time(H, vl(W, INFL));
    time[S.first][S.second] = 0;
    queue<pi> q; q.push(S);
    while(!q.empty())
    {
        pi p = q.front(); q.pop();
        int h, w;
        tie(h, w) = p;
        REP(i, 4)
        {
            int nh = h+dh[i];
            int nw = w+dw[i];
            if(0 <= nh && nh < H && 0 <= nw && nw < W)
            {
                if((s[nh][nw] == '.' || s[nh][nw] == 'G') && chmin(time[nh][nw], time[h][w]+1)) q.push(mp(nh, nw));
                if((s[nh][nw] == '#') && chmin(time[nh][nw], time[h][w]+x)) q.push(mp(nh, nw));
            }
        }
    }
    return time[G.first][G.second] <= T;
}

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> H >> W >> T;
    s = vs(H); REP(i, H) cin >> s[i];
    REP(i, H)
    {
        REP(j, W)
        {
            if(s[i][j] == 'S') S = mp(i, j);
            else if(s[i][j] == 'G') G = mp(i, j);
        }
    }

    ll l = 1, r = INFL;
    while(r-l>1)
    {
        ll m = (l+r)/2;
        if(C(m)) l = m;
        else r = m;
    }
    cout << l << endl;
}

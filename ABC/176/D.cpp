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

    int H, W; cin >> H >> W;
    int Ch, Cw; cin >> Ch >> Cw;
    Ch--; Cw--;
    int Dh, Dw; cin >> Dh >> Dw;
    Dh--; Dw--;
    vs S(H); REP(i, H) cin >> S[i];
    vvi dist(H, vi(W, INF));
    dist[Ch][Cw] = 0;
    deque<pi> q;
    q.push_front(mp(Ch, Cw));
    int dh[] = {-1, 0, 1, 0};
    int dw[] = {0, -1, 0, 1};
    while(!q.empty())
    {
        pi p = q.front(); q.pop_front();
        int h = p.first, w = p.second;
        REP(i, 4)
        {
            int nh = h + dh[i];
            int nw = w + dw[i];
            if(0 <= nh && nh < H && 0 <= nw && nw < W && S[nh][nw] == '.')
            {
                if(chmin(dist[nh][nw], dist[h][w])) q.push_front(mp(nh, nw));
            }
        }
        for(int dh = -2; dh <= 2; dh++)
        {
            for(int dw = -2; dw <= 2; dw++)
            {
                int nh = h + dh;
                int nw = w + dw;
                if(0 <= nh && nh < H && 0 <= nw && nw < W && S[nh][nw] == '.')
                {
                    if(chmin(dist[nh][nw], dist[p.first][p.second]+1)) q.push_back(mp(nh, nw));
                }
            }
        }
    }
    if(dist[Dh][Dw] == INF) cout << - 1 << endl;
    else cout << dist[Dh][Dw] << endl;
}

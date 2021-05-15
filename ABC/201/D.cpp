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
    vs s(H); REP(i, H) cin >> s[i];
    vl score(2, 0);
    vvi grid(H, vi(W, -INF));
    queue<pi> q;
    q.push(mp(H-1, W-1));
    grid[H-1][W-1] = 0;
    while(!q.empty())
    {
        pi p = q.front(); q.pop();
        int h = p.first, w = p.second;

        int nh = h-1, nw = w;
        if(0 <= nh && nh < H && 0 <= nw && nw < W)
        {
            if((nh+nw)%2==0) 
            {
                if(grid[nh][nw] == -INF) grid[nh][nw] = grid[h][w]+(s[h][w]=='+' ? 1 : -1), q.push(mp(nh, nw));
                else if(chmax(grid[nh][nw], grid[h][w]+(s[h][w]=='+' ? 1 : -1))) q.push(mp(nh, nw));
            }
            else
            {
                if(grid[nh][nw] == -INF) grid[nh][nw] = grid[h][w]+(s[h][w]=='+' ? -1 : 1), q.push(mp(nh, nw));
                else if(chmin(grid[nh][nw], grid[h][w]+(s[h][w]=='+' ? -1 : +1))) q.push(mp(nh, nw));
            }
        }

        nh = h, nw = w-1;
        if(0 <= nh && nh < H && 0 <= nw && nw < W)
        {
            if((nh+nw)%2==0) 
            {
                if(grid[nh][nw] == -INF) grid[nh][nw] = grid[h][w]+(s[h][w]=='+' ? 1 : -1), q.push(mp(nh, nw));
                else if(chmax(grid[nh][nw], grid[h][w]+(s[h][w]=='+' ? 1 : -1))) q.push(mp(nh, nw));
            }
            else
            {
                if(grid[nh][nw] == -INF) grid[nh][nw] = grid[h][w]+(s[h][w]=='+' ? -1 : 1), q.push(mp(nh, nw));
                else if(chmin(grid[nh][nw], grid[h][w]+(s[h][w]=='+' ? -1 : +1))) q.push(mp(nh, nw));
            }
        }
    }

    if(grid[0][0] == 0) cout << "Draw" << endl;
    else if(grid[0][0] > 0) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
}
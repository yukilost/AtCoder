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

    int H, W; cin >> H >> W;
    vs s(H); REP(i, H) cin >> s[i];
    vector<vector<pi>> t(26); 
    pi start, goal;
    REP(i, H)
    {
        REP(j, W)
        {
            if(s[i][j] == 'S') start = mp(i, j);
            if(s[i][j] == 'G') goal = mp(i, j);
            if('a' <= s[i][j] && s[i][j] <= 'z') t[s[i][j]-'a'].pb(mp(i, j));
        }
    }

    int dh[] = {-1, 0, 1, 0};
    int dw[] = {0, -1, 0, 1};

    vb checked(26, false);
    vvi dist(H, vi(W, INF));
    dist[start.first][start.second] = 0;
    queue<pi> q;
    q.push(start);
    while(!q.empty())
    {
        pi p = q.front(); q.pop();
        int h = p.first, w = p.second;
        REP(i, 4)
        {
            int nh = h + dh[i];
            int nw = w + dw[i];
            if(0 <= nh && nh < H && 0 <= nw && nw < W && s[nh][nw] != '#' && chmin(dist[nh][nw], dist[h][w]+1)) q.push(mp(nh, nw));
        }
        if('a' <= s[h][w] && s[h][w] <= 'z' && !checked[s[h][w]-'a'])
        {
            REP(i, t[s[h][w]-'a'].size())
            {
                pi np = t[s[h][w]-'a'][i];
                if(chmin(dist[np.first][np.second], dist[h][w]+1)) q.push(np);
            }
            checked[s[h][w]-'a'] = true;
        }
    }
    if(dist[goal.first][goal.second] == INF) cout << -1 << endl;
    else cout << dist[goal.first][goal.second] << endl;
}

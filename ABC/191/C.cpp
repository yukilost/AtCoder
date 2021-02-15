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

int H, W;
vs s;

int dh[] = {-1, 0, 1, 0, -1, 0, 1};
int dw[] = {0, 1, 0, -1, 0, 1, 0};

bool valid(int h, int w)
{
    if(0 <= h && h < H && 0 <= w && w < W) return true;
    return false;
}

bool adj2(int h, int w)
{
    REP(i, 4)
    {
        int c = 0;
        REP(j, 2)
        {
            int nh = h + dh[i+j];
            int nw = w + dw[i+j];
            if(!valid(nh, nw)) break;
            if(s[h][w] != s[nh][nw]) c++;
        }
        if(c == 2) return true;
    }
    return false;
}

bool adj3(int h, int w)
{
    REP(i, 4)
    {
        int c = 0;
        REP(j, 3)
        {
            int nh = h + dh[i+j];
            int nw = w + dw[i+j];
            if(!valid(nh, nw)) break;
            if(s[h][w] != s[nh][nw]) c++;
        }
        if(c == 3) return true;
    }
    return false;
}

bool adj4(int h, int w)
{
    int c = 0;
    REP(i, 4)
    {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if(!valid(nh, nw)) break;
        if(s[h][w] != s[nh][nw]) c++;
        if(c == 4) return true;
    }
    return false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    cin >> H >> W;
    s.resize(H); REP(i, H) cin >> s[i];
    int ans = 0;
    REP(h, H)
    {
        REP(w, W)
        {
            if(adj4(h, w)) ans += 4;
            else if(adj3(h, w)) ans += 2;
            else if(adj2(h, w)) ans += 1;
        }
    }
    cout << ans << endl;
}

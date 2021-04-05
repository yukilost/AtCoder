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

    int H, W, N, M; cin >> H >> W >> N >> M;
    vi A(N), B(N), C(M), D(M);
    REP(i, N) cin >> A[i] >> B[i];
    REP(i, M) cin >> C[i] >> D[i];

    vector<vi> lighted_h(H+2, vi(W+2, 0));
    vector<vi> lighted_w(H+2, vi(W+2, 0));

    vvi t(H+1);
    REP(i, M) t[C[i]].pb(D[i]);
    REPS(i, H) 
    {
        t[i].pb(0);
        t[i].pb(W+1);
        sort(ALL(t[i]));
    }

    REP(i, N)
    {
        int idx = lower_bound(ALL(t[A[i]]), B[i]) - t[A[i]].begin();
        int left_block = t[A[i]][idx-1];
        int right_bloc = t[A[i]][idx];
        lighted_h[A[i]][left_block+1]++;
        lighted_h[A[i]][right_bloc]--;
    }
    REPS(i, H)
    {
        REPS(j, W-1) lighted_h[i][j+1] += lighted_h[i][j];
    }

    t = vvi(W+1);
    REP(i, M) t[D[i]].pb(C[i]);
    REPS(i, W)
    {
        t[i].pb(0);
        t[i].pb(H+1);
        sort(ALL(t[i]));
    }

    REP(i, N)
    {
        int idx = lower_bound(ALL(t[B[i]]), A[i]) - t[B[i]].begin();
        int upper_block = t[B[i]][idx-1];
        int lower_block = t[B[i]][idx];
        lighted_w[upper_block+1][B[i]]++;
        lighted_w[lower_block][B[i]]--;
    }
    REPS(j, W)
    {
        REPS(i, H-1) lighted_w[i+1][j] += lighted_w[i][j];
    }

    int ans = 0;
    REPS(i, H) REPS(j, W) if(lighted_h[i][j] > 0 || lighted_w[i][j] > 0) ans++;
    cout << ans << endl;
}

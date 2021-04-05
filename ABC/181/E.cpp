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

    int N, M; cin >> N >> M;
    vi H(N); REP(i, N) cin >> H[i];
    vi W(M); REP(i, M) cin >> W[i];
    sort(ALL(H));
    vi left((N+1)/2), right((N+1)/2);
    for(int i = 0; i+1 < N; i += 2) left[i/2+1] = left[i/2]+H[i+1]-H[i];
    for(int i = N-2; i > 0; i -= 2) right[i/2] = right[i/2+1]+H[i+1]-H[i];
    int ans = INF;
    REP(i, M)
    {
        int x = lower_bound(ALL(H), W[i])-H.begin();
        if(x & 1) x ^= 1;
        chmin(ans, left[x/2]+right[x/2]+abs(H[x]-W[i]));
    }
    cout << ans << endl;
}

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

    int N; cin >> N;    
    int a[N]; REP(i, N) cin >> a[i];
    int m = INF, p = -INF;
    int mi = 0, pi = 0;
    REP(i, N)
    {
        if(chmin(m, a[i])) mi = i;
        if(chmax(p, a[i])) pi = i;
    }

    if(m >= 0)
    {
        cout << N-1 << endl;
        REP(i, N-1) cout << i+1 << " " << i+2 << endl;
    }
    else if(p < 0)
    {
        cout << N-1 << endl;
        RREP(i, N-1) cout << i+2 << " " << i+1 << endl;
    }
    else if(abs(m) > abs(p))
    {
        cout << 2*N-1 << endl;
        REP(i, N) cout << mi+1 << " " << i+1  << endl;
        RREP(i, N-1) cout << i+2 << " " << i+1 << endl;
    }
    else
    {
        cout << 2*N-1 << endl;
        REP(i, N) cout << pi+1 << " " << i+1  << endl;
        REP(i, N-1) cout << i+1 << " " << i+2 << endl;
    }
}

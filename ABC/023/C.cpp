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

    ll R, C, K; cin >> R >> C >> K;
    ll N; cin >> N;
    vl a(R, 0), b(C, 0);
    vl r(N), c(N);
    REP(i, N)
    {
        cin >> r[i] >> c[i];
        r[i]--, c[i]--;
        a[r[i]]++;
        b[c[i]]++;
    }
    vl x(N+1, 0), y(N+1, 0);
    REP(i, R) x[a[i]]++;
    REP(i, C) y[b[i]]++;
    ll ans = 0;
    REP(i, N+1) 
    {
        if(K-i>=0) ans += x[i]*y[K-i];
    }

    REP(i, N)
    {
        if(a[r[i]]+b[c[i]] == K) ans--;
        else if(a[r[i]]+b[c[i]] == K+1) ans++;
    }

    cout << ans << endl;

}

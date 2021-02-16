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

    int n, m; cin >> n >> m;
    int a[m], b[m]; REP(i, m) cin >> a[i] >> b[i];    
    int k ; cin >> k;
    int c[k], d[k]; REP(i, k) cin >> c[i] >> d[i];
    int ans = 0;

    for(int bit = 0; bit < (1 << k); bit++)
    {
        vb dish(n+1, false);
        REP(i, k)
        {
            if(bit & (1 << i)) dish[c[i]] = true;
            else dish[d[i]] = true;
        }

        int count = 0;
        REP(i, m)
        {
            if(dish[a[i]] && dish[b[i]]) count++;
        }
        chmax(ans, count);
    }
    cout << ans << endl;
}

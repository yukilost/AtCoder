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

    ll H, W; cin >> H >> W;
    ll ans = INFL;
    REPS(i, H-1)
    {
        ll s1 = i*W; 
        ll s2 = (H-i)*(W/2);
        ll s3 = H*W-s1-s2;

        chmin(ans, max(s1, max(s2, s3))-min(s1, min(s2, s3)));

        s2 = (H-i)/2*W;
        s3 = H*W-s1-s2;
        chmin(ans, max(s1, max(s2, s3))-min(s1, min(s2, s3)));
    }

    REPS(i, W-1)
    {
        ll s1 = i*H;
        ll s2 = (W-i)*(H/2);
        ll s3 = H*W-s1-s2;
        chmin(ans, max(s1, max(s2, s3))-min(s1, min(s2, s3)));

        s2 = (W-i)/2*H;
        s3 = H*W-s1-s2;
        chmin(ans, max(s1, max(s2, s3))-min(s1, min(s2, s3)));
    }

    cout << ans << endl;
}

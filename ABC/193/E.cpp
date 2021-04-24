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

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
    return a/gcd(a, b)*b;
}

ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll g = a;
    x = 1;
    y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll T; cin >> T;
    vl ans(T);
    const ll LLMAX = numeric_limits<ll>::max()/4;
    REP(i, T)
    {
        ll t = LLMAX;
        ll X, Y, P, Q; cin >> X >> Y >> P >> Q;
        for(ll a = X; a < X+Y; a++)
        {
            for(ll b = P; b < P+Q; b++)
            {
                ll x, y, g = extgcd(P+Q, 2*X+2*Y, x, y);
                if((a-b)%g != 0) continue;
                x = (x*(a-b)/g%(2*X+2*Y)+2*X+2*Y)%(2*X+2*Y);
                chmin(t, (x*(P+Q)+b)%((2*X+2*Y)*(P+Q)/g));
            }
        }
        ans[i] = t;
    }
    REP(i, T) 
    {
        if(ans[i] < 0 || ans[i] == LLMAX) cout << "infinity" << endl;
        else cout << ans[i] << endl;
    }
}

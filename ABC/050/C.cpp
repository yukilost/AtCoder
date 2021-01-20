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

ll modpow(ll a, ll x)
{
    ll res = 1;
    while(x > 0)
    {
        if(x & 1) res *= a;
        res %= MOD;
        a = a * a;
        a %= MOD;
        x >>= 1;
    }
    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll N; cin >> N;
    ll c[N]; REP(i, N) c[i] = 0;
    REP(i, N)
    {
        ll t; cin >> t;
        c[t]++;
    }

    if(N % 2 == 0)
    {
        for(ll i = 1; i < N; i+=2)
        {
            if(c[i] != 2)
            {
                cout << 0 << endl;
                return 0;
            }
        }
        cout << modpow(2, N/2) << endl;
    }
    else
    {
        if(c[0] != 1)
        {
            cout << 0 << endl;
            return 0;
        }
        for(ll i = 2; i < N; i+=2)
        {
            if(c[i] != 2)
            {
                cout << 0 << endl;
                return 0;
            }
        }
        cout << modpow(2, (N-1)/2) << endl;
    }
}

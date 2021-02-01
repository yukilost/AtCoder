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

ll comb(ll n, ll r)
{
    ll res = 1;
    for(ll i = 1; i <= r; i++)
    {
        res *= (n+1-i);
        res /= i;
    }
    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll N, A, B; cin >> N >> A >> B;    
    vl v(N); REP(i, N) cin >> v[i];
    sort(ALL(v));

    ll sum = 0;      
    ll m = v[0];
    ll c = 0;
    for(int i = N-1; i >= N-A; i--)
    {
        sum += v[i];
        if(m == v[i]) c++;
        else
        {
            c = 1;
            m = v[i];
        }
    }
    cout << (double)sum/A << endl;

    ll n = upper_bound(ALL(v), m)-lower_bound(ALL(v), m);
    if(m == v[N-1])
    {
        ll t = 0; 
        for(ll i = A; i <= B; i++)  t += comb(n, i);
        cout << t << endl;
    }
    else
    {
        cout << comb(n, c) << endl;
    }
}

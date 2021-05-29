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

    ll N; cin >> N;
    vector<pl> x(N), y(N); 
    vector<pl> p(N);
    REP(i, N)
    {
        cin >> x[i].first >> y[i].first;
        x[i].second = i; y[i].second = i;
        p[i].first = x[i].first;
        p[i].second = y[i].first;
    }

    sort(ALL(x));
    sort(ALL(y));
    set<int> s;
    REP(i, 2)
    {
        s.insert(x[i].second);
        s.insert(y[i].second);
        s.insert(x[N-i-1].second);
        s.insert(y[N-i-1].second);
    }

    ll m1 = -INFL, m2 = -INFL;
    vl d;
    for(auto itr = s.begin(); itr != s.end(); itr++)
    {
        for(auto itr2 = itr; itr2 != s.end(); itr2++)
        {
            if(itr == itr2) continue;
            d.pb(max(abs(p[*itr].first-p[*itr2].first), abs(p[*itr].second-p[*itr2].second)));
        }
    }
    sort(RALL(d));
    cout << d[1] << endl;
}
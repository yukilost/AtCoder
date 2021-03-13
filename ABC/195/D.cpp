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

    ll N, M, Q; cin >> N >> M >> Q;    
    vector<pl> p(N); REP(i, N) cin >> p[i].second >> p[i].first;
    vl x(M); REP(i, M) cin >> x[i];
    sort(RALL(p));
    vector<pl> q(Q); REP(i, Q) cin >> q[i].first >> q[i].second, q[i].first--, q[i].second--;
    REP(i, Q)
    {
        ll l = q[i].first, r = q[i].second;
        vl y = x;
        y.erase(y.begin()+l, y.begin()+r+1);
        sort(RALL(y));

        vl in(y.size(), 0);
        REP(j, N) 
        {
            ll w = p[j].second, v = p[j].first;
            int z = -1;
            REP(k, y.size())
            {
                if(y[k] >= w && in[k] == 0) z = k;
            }
            if(z != -1) in[z] = v;
        }
        ll t = 0;
        REP(j, y.size()) t += in[j];
        cout << t << endl;
    }
}

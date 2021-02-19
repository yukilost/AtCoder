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

    int A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
    double m = 0;
    int ans_w = 0, ans_s = 0;
    REP(a, 31)
    {
        REP(b, 31)
        {
            int water = 100*(a*A+b*B);
            if(water > F) break;
            int constraint = min(E*(a*A+b*B), F-water);
            REP(c, constraint/C+1)
            {
                int sugar = c*C + (constraint-c*C)/D*D;
                if(chmax(m, (double)sugar/((double)water+(double)sugar))) ans_w = water, ans_s = sugar;
            }
        }
    }
    if(ans_s == 0) cout << A*100 << " " << 0 << endl;
    else cout << ans_w+ans_s << " " << ans_s << endl;
}

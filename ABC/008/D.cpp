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

vector<pl> machine;
map<pair<pl, pl>, ll> memo;

ll f(pl bl, pl ur)
{
    if(memo[mp(bl, ur)] != 0) return memo[mp(bl, ur)];
    ll ret = 0;
    for(auto itr = lower_bound(ALL(machine), bl); itr != upper_bound(ALL(machine), ur); itr++)
    {
        if(bl.first <= itr->first && itr->first < ur.first && bl.second <= itr->second && itr->second < ur.second)
        {
            ll tmp = ur.first-bl.first + ur.second-bl.second - 1;
            tmp += f(bl, *itr);
            tmp += f(mp(bl.first, itr->second+1), mp(itr->first, ur.second));
            tmp += f(mp(itr->first+1, bl.second), mp(ur.first, itr->second));
            tmp += f(mp(itr->first+1, itr->second+1), ur);
            chmax(ret, tmp);
        }
    }
    return memo[mp(bl, ur)] = ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll W, H; cin >> W >> H;
    ll N; cin >> N;
    machine = vector<pl>(N); REP(i, N) cin >> machine[i].first >> machine[i].second;
    sort(ALL(machine));

    ll ans = 0;
    chmax(ans, f(mp(1, 1), mp(W+1, H+1)));
    cout << ans << endl;
}

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
const ll  INFL = 5e18;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

int cost(int n, int a, int b)
{
    int ret = 0;
    if(a > 0) ret += n*a, b -= a, a = 0;
    if(b <= 0) ret += n*(-b+1), a += -b+1, b = 1;
    n--;
    int s = n/2;
    int t = n-s;
    if((abs(a) >= s && abs(b-1) >= t) || (abs(a) >= t && abs(b-1) >= s)) return s*(s+1)/2 + t*(t+1)/2 + ret;
    else
    {
        s = min(abs(a), abs(b-1));
        t = n-s;
        return s*(s+1)/2 + t*(t+1)/2 + ret;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int R, G, B; cin >> R >> G >> B;
    int ans = INF;
    for(int left = -300; left <= 300; left++)
    {
        for(int right = left+1; right <= 300; right++)
        {
            if(right-left < G) continue;
            int sum_cost = cost(R, -1000, left+100) + cost(G, left, right) + cost(B, right-100, 1000);
            chmin(ans, sum_cost);
        }
    }
    cout << ans << endl;
}

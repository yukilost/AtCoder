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
const ll INF = 1e9 + 7;
const ll  INFL = 1e18;
const double PI = 3.14159265359;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

ll N, K;
vvl A;

// 中央値がx以下にできるか
bool C(ll x)
{
    vvl s(N+1, vl(N+1, 0));
    REP(i, N)
    {
        REP(j, N)
        {
            s[i+1][j+1] += s[i+1][j]+s[i][j+1]-s[i][j]+(A[i][j]<=x);
        }
    }
    for(int i = 0; i+K<= N; i++)
    {
        for(int j = 0; j+K<=N; j++)
        {
            if(K % 2 == 0 && K*K/2 <= s[i+K][j+K]-s[i][j+K]-s[i+K][j]+s[i][j]) return true;
            if(K % 2 == 1 && K*K/2+1 <= s[i+K][j+K]-s[i][j+K]-s[i+K][j]+s[i][j]) return true;
        }
    }
    return false;
}

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N >> K;
    A = vvl (N, vl(N));
    REP(i, N) REP(j, N) cin >> A[i][j];
    ll l = -1, r = INF;
    while(r-l > 1)
    {
        ll m = (l+r)/2;
        if(C(m)) r = m;
        else l = m;
    }
    cout << r << endl;
}
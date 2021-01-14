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

    ll N, T; cin >> N >> T;
    vl A(N); REP(i, N) cin >> A[i];

    vi max_idx(N);
    max_idx[N-1] = N-1;
    RREP(i, N-1)
    {
        if(A[i] < A[max_idx[i+1]]) max_idx[i] = max_idx[i+1];
        else max_idx[i] = i;
    }

    // REP(i, N) cout << A[max_idx[i]] << " ";
    // cout << endl;

    ll p = 0;
    REP(i, N) chmax(p, A[max_idx[i]]-A[i]);
    // cout << p << endl;

    int ans = 0; 
    REP(i, N)
    {
        ll m = A[max_idx[i]];
        if(m-A[i] == p)
        {
            ans++;
            A[max_idx[i]]--;
        }
    }
    cout << ans << endl;
}

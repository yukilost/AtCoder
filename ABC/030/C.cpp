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

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, M, X, Y; cin >> N >> M >> X >> Y;
    vl A(N); REP(i, N) cin >> A[i];
    vl B(M); REP(i, M) cin >> B[i];

    sort(ALL(A));
    sort(ALL(B));
    int ia = 0, ib = 0;
    bool a = true;
    ll c = 0;
    while(ia < N && ib < M)
    {
        if(a)
        {
            ll t = A[ia]+X; 
            while(ib < M && B[ib] < t) ib++;
            a = false;
        }
        else
        {
            ll t = B[ib]+Y;
            c++;
            while(ia < N && A[ia] < t) ia++;
            a = true;
        }
    }
    cout << c << endl;
}

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

    int N; cin >> N;
    vector<pair<double, double>> A(N), B(N);
    REP(i, N) cin >> A[i].first >> A[i].second;
    REP(i, N) cin >> B[i].first >> B[i].second;

    double x0 = 0, y0 = 0;
    double x1 = 0, y1 = 0;
    REP(i, N) 
    {
        x0 += A[i].first, y0 += A[i].second;
        x1 += B[i].first, y1 += B[i].second; 
    }
    x0 /= N, y0 /= N;
    x1 /= N, y1 /= N;

    double s0 = 0, s1 = 0;
    REP(i, N)
    {
        A[i].first -= x0, A[i].second -= y0;
        B[i].first -= x1, B[i].second -= y1;
        s0 += sqrt(pow(A[i].first, 2)+pow(A[i].second, 2));
        s1 += sqrt(pow(B[i].first, 2)+pow(B[i].second, 2));
    }
    s0 /= N, s1 /= N;
    cout << s1/s0 << endl;
}

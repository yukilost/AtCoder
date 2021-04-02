#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

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
const double PI = 3.14159265359;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string X; cin >> X;
    ll M; cin >> M;

    ll d = *max_element(ALL(X))-'0';
    if(X.size() == 1)
    {
        if(d <= M) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    ll l = d, r = INFL+1;
    cpp_int mm = M;
    while(r-l > 1)
    {
        ll m = (l+r)/2;
        cpp_int p = 1, sum = 0;
        RREP(i, X.size())
        {
            sum += p*(X[i]-'0');
            p *= m;
        }
        if(sum <= mm) l = m;
        else r = m;
    }
    cout << l-d << endl;
}

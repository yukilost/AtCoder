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

    int a, b; cin >> a >> b; 
    cout << 100 << " " << 100 << endl;
    a--; b--;
    vector<vector<char>> s(100, vector<char>(100, '.'));
    for(int i = 50; i < 100; i++) REP(j, 100) s[i][j] = '#';

    for(int i = 99; i >= 50; i -= 2)
    {
        for(int j = 0; j < 100; j += 2)
        {
            if(a > 0)
            {
                s[i][j] = '.';
                a--;
            }
        }
    }
    for(int i = 0; i < 50; i += 2)
    {
        for(int j = 0; j < 100; j += 2)
        {
            if(b > 0)
            {
                s[i][j] = '#';
                b--;
            }
        }
    }
    REP(i, 100)
    {
        REP(j, 100) cout << s[i][j];
        cout << endl;
    }
}

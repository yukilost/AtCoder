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
const double PI = 3.14159265359;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

ll convert(string s, map<char, ll>& m)
{
    ll ret = 0;
    if(m[s[0]] == 0) return 0;
    REP(i, (int)s.length())
    {
        ret *= 10;
        ret += m[s[i]];
    }
    return ret;
}

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string s[3]; REP(i, 3) cin >> s[i];
    vl nums(10); REP(i, 10) nums[i] = i;
    vb chars(26, false);
    REP(i, 3)
    {
        REP(j, (int)s[i].length())
        {
            chars[s[i][j]-'a'] = true;
        }
    }
    vector<char> c;
    REP(i, 26) if(chars[i]) c.pb(i);
    if(c.size() > 10) 
    {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }
    do
    {
        map<char, ll> m;
        REP(i, (int)c.size()) m[(char)(c[i]+'a')] = nums[i];

        ll x0 = convert(s[0], m);
        if(x0 == 0) continue;
        ll x1 = convert(s[1], m);
        if(x1 == 0) continue;
        ll x2 = convert(s[2], m);
        if(x2 == 0) continue;
        if(x0+x1 == x2)
        {
            cout << x0 << endl << x1 << endl << x2 << endl;
            return 0;
        }
    } while (next_permutation(ALL(nums)));
    cout << "UNSOLVABLE" << endl;
}
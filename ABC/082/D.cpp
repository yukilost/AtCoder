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
    
    string s; cin >> s;    
    int x, y; cin >> x >> y;
    vi u, v;
    int count_t = 0;
    int count_f = 0;
    REP(i, (int)s.length())
    {
        if(s[i] == 'T')
        {
            if(count_t % 2 == 0) u.pb(count_f);
            else v.pb(count_f);
            count_t++;
            count_f = 0;
        }
        else
        {
            count_f++;
        }
    }
    if(count_t % 2 == 0) u.pb(count_f);
    else v.pb(count_f);
    vi reachable_u(20000, 0); 
    reachable_u[10000] = 1;
    REP(i, (int)u.size())
    {
        vi tmp(20000, 0);
        if(i == 0)
        {
            REP(j, 20000)
            {
                if(reachable_u[j])
                {
                    if(j+u[i] < 20000) tmp[j+u[i]] = 1;
                }
            }
        }
        else
        {
            REP(j, 20000)
            {
                if(reachable_u[j])
                {
                    if(j+u[i] < 20000) tmp[j+u[i]] = 1;
                    if(j-u[i] >= 0) tmp[j-u[i]] = 1;
                }
            }
        }
        reachable_u = tmp;
    }


    vi reachable_v(20000, 0); 
    reachable_v[10000] = 1;
    REP(i, (int)v.size())
    {
        vi tmp(20000, 0);
        REP(j, 20000)
        {
            if(reachable_v[j])
            {
                if(j+v[i] < 20000) tmp[j+v[i]] = 1;
                if(j-v[i] >= 0) tmp[j-v[i]] = 1;
            }
        }
        reachable_v = tmp;
    }

    if(reachable_u[x+10000] && reachable_v[y+10000]) Yes;
    else No;
}

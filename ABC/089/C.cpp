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
    
    int N; cin >> N;
    ll c[5]; REP(i, 5) c[i] = 0;
    REP(i, N)
    {
        string s; cin >> s;
        switch (s[0])
        {
        case 'M':
            c[0]++;
            break;
        case 'A':
            c[1]++;
            break;
        case 'R':
            c[2]++;
            break;
        case 'C':
            c[3]++;
            break;
        case 'H':
            c[4]++;
            break;
        }
    }

    ll ans = 0;
    REP(i, 5)
    {
        for(int j = i+1; j < 5; j++)
        {
            for(int k = j+1; k < 5; k++)
            {
                ans += c[i]*c[j]*c[k];
            }
        }
    }
    cout << ans << endl;
}

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
    string s; cin >> s;
    int str[N]; REP(i, N) s[i] == 'o' ? str[i] = 1 : str[i] = 0;

    REP(b, 1 << 2)
    {
        int isSheep[N]; REP(i, N) isSheep[i] = -1;
        isSheep[0] = (b & (1 << 0)) > 0;
        isSheep[1] = (b & (1 << 1)) > 0;
        bool ok = true;
        REP(i, N)
        {
            //cout << isSheep[1] << " " << str[1] << endl;
            if(isSheep[(i+2)%N] == -1)
            {
                if(isSheep[(i+1)%N] == str[(i+1)%N]) isSheep[(i+2)%N] = isSheep[i%N];
                else isSheep[(i+2)%N] = !isSheep[i%N];
            }
            else
            {
                if(isSheep[(i+1)%N] == str[(i+1)%N])
                {
                    if(isSheep[(i+2)%N] != isSheep[i%N]) ok = false;
                }
                else
                {
                    if(isSheep[(i+2)%N] == isSheep[i%N]) ok = false;
                }
            }
        }
        if(ok)
        {
            REP(i, N) cout << (isSheep[i] ? 'S' : 'W');
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}

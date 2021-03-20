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

    int H, W, A, B; cin >> H >> W >> A >> B;    
    int ans = 0;
    for(int x = 0; x < (1 << (H*(W-1))); x++)
    {
        for(int y = 0; y < (1 << ((H-1)*W)); y++)
        {
            int area = 0;
            if(__builtin_popcount(x) + __builtin_popcount(y) != A) continue;
            bool used[H][W]; memset(used, 0, sizeof(used));
            REP(i, H*(W-1))
            {
                if((x >> i & 1) && !used[i/(W-1)][i%(W-1)] && !used[i/(W-1)][i%(W-1)+1])
                {
                    used[i/(W-1)][i%(W-1)] = true;
                    used[i/(W-1)][i%(W-1)+1] = true;
                    area += 2;
                }
            }
            REP(i, (H-1)*W)
            {
                if((y >> i & 1) && !used[i/W][i%W] && !used[i/W+1][i%W])
                {
                    used[i/W][i%W] = true;
                    used[i/W+1][i%W] = true;
                    area += 2;
                }
            }
            if(area == 2*A) ans++;
        }
    }
    cout << ans << endl;
}
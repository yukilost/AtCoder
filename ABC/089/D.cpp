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
    
    int H, W, D; cin >> H >> W >> D;
    pi A[H*W+1];
    REPS(i, H)
    {
        REPS(j, W)
        {
            int t; cin >> t;
            A[t] = mp(i, j);
        }
    }

    int d[D+1][H*W/D+1];
    REPS(i, D)
    {
        if(i == D)
        {
            d[i][1] = 0;
            for(int j = 2; j*D <= H*W; j++)
            {
                d[i][j] = d[i][j-1] + abs(A[j*D].first-A[(j-1)*D].first) + abs(A[j*D].second-A[(j-1)*D].second);
            }
        }
        else
        {
            d[i][0] = 0;
            for(int j = 1; i+j*D <= H*W; j++) 
            {
                d[i][j] = d[i][j-1] + abs(A[i+j*D].first-A[i+(j-1)*D].first) + abs(A[i+j*D].second-A[i+(j-1)*D].second);
            }
        }
    }

    int Q; cin >> Q;
    int L[Q], R[Q]; REP(i, Q) cin >> L[i] >> R[i];
    REP(i, Q)
    {
        cout << d[(L[i]+D-1)%D+1][R[i]/D] - d[(L[i]+D-1)%D+1][L[i]/D] << endl;
    }
}

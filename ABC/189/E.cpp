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

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N; cin >> N;
    vl x(N), y(N); REP(i, N) cin >> x[i] >> y[i];
    ll M; cin >> M;
    vector<pl> op(M);
    REP(i, M)
    {
        cin >> op[i].first;
        if(op[i].first <= 2) op[i].second = 0;
        else cin >> op[i].second;
    }
    ll Q; cin >> Q;
    vector<tuple<ll, ll, ll>> query(Q);
    REP(i, Q)
    {
        ll A, B; cin >> A >> B;
        B--;
        query[i] = mt(A, B, i);
    }
    sort(ALL(query));

    vector<pl> ans(Q);
    vvl mat(3, vl(3, 0)); REP(i, 3) mat[i][i] = 1;
    ll k = 0;
    REP(i, Q)
    {
        ll A, B, n;
        tie(A, B, n) = query[i];
        while(k < A)
        {
            vvl tmp(3, vl(3, 0));
            pl p = op[k];
            if(p.first == 1)
            {
                tmp[0][0] = mat[1][0];
                tmp[0][1] = mat[1][1];
                tmp[0][2] = mat[1][2];
                tmp[1][0] = -mat[0][0];
                tmp[1][1] = -mat[0][1];
                tmp[1][2] = -mat[0][2];
                tmp[2][0] = mat[2][0];
                tmp[2][1] = mat[2][1];
                tmp[2][2] = mat[2][2];
            }
            else if(p.first == 2)
            {
                tmp[0][0] = -mat[1][0];
                tmp[0][1] = -mat[1][1];
                tmp[0][2] = -mat[1][2];
                tmp[1][0] = mat[0][0];
                tmp[1][1] = mat[0][1];
                tmp[1][2] = mat[0][2];
                tmp[2][0] = mat[2][0];
                tmp[2][1] = mat[2][1];
                tmp[2][2] = mat[2][2];
            }
            else if(p.first == 3)
            {
                ll t = p.second;
                tmp[0][0] = -mat[0][0];
                tmp[0][1] = -mat[0][1];
                tmp[0][2] = -mat[0][2] + 2*t;
                tmp[1][0] = mat[1][0];
                tmp[1][1] = mat[1][1];
                tmp[1][2] = mat[1][2];
                tmp[2][0] = mat[2][0];
                tmp[2][1] = mat[2][1];
                tmp[2][2] = mat[2][2];
            }
            else
            {
                ll t = p.second;
                tmp[0][0] = mat[0][0];
                tmp[0][1] = mat[0][1];
                tmp[0][2] = mat[0][2];
                tmp[1][0] = -mat[1][0];
                tmp[1][1] = -mat[1][1];
                tmp[1][2] = -mat[1][2] + 2*t;
                tmp[2][0] = mat[2][0];
                tmp[2][1] = mat[2][1];
                tmp[2][2] = mat[2][2];
            }
            mat = tmp;
            k++;
        }
        ans[n] = mp(mat[0][0]*x[B]+mat[0][1]*y[B]+mat[0][2], mat[1][0]*x[B]+mat[1][1]*y[B]+mat[1][2]);
    }
    REP(i, Q) cout << ans[i].first << " " << ans[i].second << endl;
}

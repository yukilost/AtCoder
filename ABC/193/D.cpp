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
const double PI = 3.14159265;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

ll score(vl &v)
{
    ll sum = 0;
    REPS(i, 9)
    {
        sum += (ll)i*(ll)pow(10, v[i]);
    }
    return sum;
}

int main()
{ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll K; cin >> K;
    string S, T; cin >> S >> T;
    vl s(10), t(10); REP(i, 4) s[S[i]-'0']++, t[T[i]-'0']++;
    ll div = (9*K-8)*(9*K-9);
    ll sum = 0;
    REPS(i, 9)
    {
        s[i]++;
        REPS(j, 9)
        {
            t[j]++;
            bool ok = true;
            REPS(k, 9) if(s[k]+t[k] > K) ok = false;
            if(ok && score(s) > score(t))
            {
                if(i == j) sum += (K-s[i]-t[i]+2)*(K-s[i]-t[i]+1);
                else sum += (K-s[i]-t[i]+1)*(K-s[j]-t[j]+1);
            }
            t[j]--;
        }
        s[i]--;
    }
    cout << (double)sum / (double)div << endl;
}

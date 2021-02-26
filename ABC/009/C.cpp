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

    int n, K; cin >> n >> K;    
    string s; cin >> s;
    string t = "";

    int count[26]; REP(i, 26) count[i] = 0;
    REP(i, n) count[s[i]-'a']++;

    REP(i, n)
    {
        REP(j, 26)
        {
            char c = 'a'+j;
            if(count[c-'a'] <= 0) continue;
            count[c-'a']--;
            int x = 0; // 不一致数
            REP(k, i) if(s[k] != t[k]) x++;
            if(s[i] != c) x++;
            int count2[26]; REP(k, 26) count2[k] = 0;
            for(int k = i+1; k < n; k++) count2[s[k]-'a']++;
            int y = 0;
            REP(k, 26) y += min(count[k], count2[k]);
            x += n-i-1-y;
            if(x <= K)
            {
                t += c;
                break;
            }
            count[c-'a']++;
        }
    }
    cout << t << endl;
}

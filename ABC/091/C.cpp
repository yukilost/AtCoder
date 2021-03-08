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

template <class T>
struct Edge
{
    int rev, from, to;
    T cap, original_cap;
    Edge(int r, int f, int t, T c) : rev(r), from(f), to(t), cap(c), original_cap(c) {}
};

template <class T>
struct Graph
{
    vector<vector<Edge<T>>> G;
    Graph(int n = 0) : G(n) {}
    vector<Edge<T>>& operator[](int i) { return G[i]; }
    const size_t size() const { return G.size(); }
    Edge<T>& redge(Edge<T> e) { return G[e.to][e.rev]; }
    void add_edge(int from, int to, T cap)
    {
        G[from].push_back(Edge<T>((int)G[to].size(), from, to, cap));
        G[to].push_back(Edge<T>((int)G[from].size()-1, to, from, 0));
    }
};

template <class T>
struct FordFulkerson
{
    vector<int> used;

    FordFulkerson() {};
    T dfs(Graph<T>& G, int v, int t, T f)
    {
        if(v == t) return f;
        used[v] = true;
        for(auto& e : G[v])
        {
            if(!used[e.to] && e.cap > 0)
            {
                T d = dfs(G, e.to, t, min(f, e.cap));
                if(d > 0)
                {
                    e.cap -= d;
                    G.redge(e).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T max_flow(Graph<T>& G, int s, int t)
    {
        T flow = 0;
        while(true)
        {
            used.assign(G.size(), 0);
            T f = dfs(G, s, t, INF);
            if(f == 0) return flow;
            else flow += f;
        }
        return 0;
    }
};


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int N; cin >> N;
    vector<pi> r(N), b(N);
    REP(i, N) cin >> r[i].first >> r[i].second;
    REP(i, N) cin >> b[i].first >> b[i].second;

    Graph<int> G(2*N+2);
    REP(i, N)
    {
        G.add_edge(0, i+1, 1);
        G.add_edge(N+i+1, 2*N+1, 1);
    }
    REP(i, N)
    {
        REP(j, N)
        {
            if(r[i].first < b[j].first && r[i].second < b[j].second) G.add_edge(i+1, N+j+1, 1);
        }
    }

    FordFulkerson<int> f;
    cout << f.max_flow(G, 0, 2*N+1) << endl;
}

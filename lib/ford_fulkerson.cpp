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

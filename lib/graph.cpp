#include "template.cpp"

struct Edge
{
    int to;
};

class Graph
{
public:
    Graph(int N)
    {
        adj = vector<vector<Edge>>(N);
    }

    void addEdge(int u, Edge e)
    {
        adj[u].pb(e);
    }

private:
    vector<vector<Edge>> adj;
};
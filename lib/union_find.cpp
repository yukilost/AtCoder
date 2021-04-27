#include "template.cpp"

vi node;

int root(int x)
{
    if(node[x] == x) return x;
    return node[x] = root(node[x]);
}

void unite(int x, int y)
{
    int rx = root(x);
    int ry = root(y);
    node[rx] = ry;
}

bool same(int x, int y)
{
    return root(x) == root(y);
}
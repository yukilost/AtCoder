#include "template.cpp"

template <typename Monoid>
class SegmentTree
{
private:
    int n;
    vector<Monoid> data;
    Monoid identity;
    function<Monoid(Monoid, Monoid)> op;
    function<Monoid(Monoid, Monoid)> ch;

    Monoid _query(int a, int b, int k, int l, int r) 
    {
        if(r <= a || b <= l) return identity;
        if(a <= l && r <= b) return data[k];
        Monoid c1 = _query(a, b, 2*k+1, l, (l+r)/2);
        Monoid c2 = _query(a, b, 2*k+2, (l+r)/2, r);
        return op(c1, c2);
    }

public:
    SegmentTree<Monoid>(int _n, Monoid _identity, function<Monoid(Monoid, Monoid)> _op, function<Monoid(Monoid, Monoid)> _ch)
    : identity(_identity), op(_op), ch(_ch)
    {
        n = 1;
        while(n < _n) n *= 2;
        data = vector<Monoid>(2*n-1, identity);
    }

    void update(int idx, Monoid new_value)
    {
        idx += n-1;
        data[idx] = ch(data[idx], new_value);
        while(idx > 0)
        {
            idx = (idx-1)/2;
            data[idx] = op(data[idx*2+1], data[idx*2+2]);
        }
    }

    Monoid query(int a, int b)
    {
        return _query(a, b, 0, 0, n);
    }

    Monoid operator[](int idx)
    {
        return data[idx+n-1];
    }
};

/*
SegmentTree<int> st(5, INF, 
    [](int a, int b) { return min(a, b); },
    [](int a, int b) { return b; }
);
*/
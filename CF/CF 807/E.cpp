#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+500;

struct Node
{
    int cnt, maxpos;
    Node() : cnt(0), maxpos(0)
    {
    }
};

class LazySegTree
{
    int n;
    int root = 1;
    vector<Node> v;
    vector<int> lazy;
    vector<int> lc, rc;

    inline int m_getNo()
    {
        v.emplace_back(Node());
        lazy.push_back(0);
        lc.push_back(0);
        rc.push_back(0);
        return rc.size() - 1;
    }

    inline int m_lson(int o)
    {
        if (!lc[o])
            lc[o] = m_getNo();
        return lc[o];
    }

    inline int m_rson(int o)
    {
        if (!rc[o])
            rc[o] = m_getNo();
        return rc[o];
    }

    inline void m_pushdown(int o, int l, int r)
    {
        if (lazy[o] == 0)
            return;
        if (lazy[o] == 1)
        {
            v[o].cnt = r - l + 1;
            v[o].maxpos = r;
        }
        else
        {
            v[o].cnt = v[o].maxpos = 0;
        }

        if (l != r)
        {
            lazy[m_lson(o)] = lazy[o];
            lazy[m_rson(o)] = lazy[o];
        }

        lazy[o] = 0;
    }

    void m_maintain(int o, int l, int r)
    {
        v[o].cnt = v[l].cnt + v[r].cnt;
        v[o].maxpos = max(v[l].maxpos, v[r].maxpos);
    }

    void m_update(int x, int ql, int qr, int l, int r, int o)
    {
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr)
        {
            lazy[o] = x;
            m_pushdown(o, l, r);
            return;
        }

        m_pushdown(o, l, r);
        int mid = (l + r) / 2;
        m_update(x, ql, qr, l, mid, m_lson(o));
        m_update(x, ql, qr, mid + 1, r, m_rson(o));
        m_maintain(o, m_lson(o), m_rson(o));
    }

    Node m_query(int ql, int qr, int l, int r, int o)
    {
        if (qr < l || r < ql)
            return Node();

        m_pushdown(o, l, r);
        if (ql <= l && r <= qr)
        {
            return v[o];
        }

        int mid = (l + r) / 2;
        Node lr = m_query(ql, qr, l, mid, m_lson(o));
        Node rr = m_query(ql, qr, mid + 1, r, m_rson(o));

        lr.cnt += rr.cnt;
        lr.maxpos = max(lr.maxpos, rr.maxpos);
        return lr;
    }

public:
    LazySegTree(int n) : n(n), v(2), lc(2), rc(2), lazy(2), root(1)
    {
    }

    void update(int x, int ql, int qr)
    {
        m_update(x, ql, qr, 1, n, 1);
    }

    Node query(int ql, int qr)
    {
        return m_query(ql, qr, 1, n, 1);
    }

    // 找到第k个v
    int findKthV(int k, int v)
    {
        int l = 1, r = n, o = 1;
        while (l < r)
        {
            int ls = m_lson(o), rs = m_rson(o);
            int mid = (l + r) / 2;
            m_pushdown(ls, l, mid);
            m_pushdown(rs, mid + 1, r);

            int cnt = this->v[ls].cnt;
            if (v == 0)
                cnt = (mid - l + 1) - cnt;

            if (cnt >= k)
            {
                r = mid;
                o = ls;
            }
            else
            {
                l = mid + 1;
                k -= cnt;
                o = rs;
            }
        }
        return r;
    }

    // 找到位置大于k的下一个v
    int findNext(int k, int v)
    {
        int cnt = query(1, k).cnt;
        if (v == 0)
            cnt = k - cnt;
        return findKthV(cnt + 1, v);
    }
};

inline void add(int pos,LazySegTree &seg)
{
    int x = seg.findNext(pos -1,0);
    if(x == pos)
    {
        seg.update(1,pos,pos);
    }
    else
    {
        seg.update(-1,pos,x-1);
        seg.update(1,x,x);
    }
}
inline void sub(int pos,LazySegTree &seg)
{
    int x = seg.findNext(pos -1,1);
    if(x == pos)
    {
        seg.update(-1,pos,pos);
    }
    else
    {
        seg.update(1,pos,x-1);
        seg.update(-1,x,x);
    }
}
void solve()
{
    int n, q;
    cin>>n>>q;
    vector<int> a(n+1),b(maxn);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    LazySegTree seg(maxn);
    for(int i=1;i<=maxn-1;i++)
    {
        b[i+1]+=b[i]/2;
        if(b[i]&1)
        {
            seg.update(1,i,i);
        }
    }

    while(q--)
    {
        int k,l;cin>>k>>l;
        add(l,seg);
        sub(a[k],seg);
        a[k] = l;

        cout<<seg.query(1,maxn).maxpos<<endl;
    }

    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    using ll = long long;
    struct node
    {
        int sum, l, r, add ,mul;
    } t[50010];

    ll mod = 1329120301239;

    void build(ll p, ll l, ll r)
    {
        t[p].l = l;
        t[p].r = r;
        t[p].mul = 1;
        if (l == r)
        {
            t[p].sum = 0;
            return;
        }
        ll mid = (l + r) >> 1;
        build(p * 2, l, mid);
        build(p * 2 + 1, mid + 1, r);
        t[p].sum = (t[p * 2].sum + t[p * 2 + 1].sum) % mod;
    }

    void spread(ll p)
    {
        t[p * 2].sum = (ll)(t[p].mul * t[p * 2].sum + ((t[p * 2].r - t[p * 2].l + 1) * t[p].add) % mod) % mod;
        t[p * 2 + 1].sum = (ll)(t[p].mul * t[p * 2 + 1].sum + ((t[p * 2 + 1].r - t[p * 2 + 1].l + 1) * t[p].add) % mod) % mod;

        t[p * 2].mul = (ll)(t[p * 2].mul * t[p].mul) % mod;
        t[p * 2 + 1].mul = (ll)(t[p * 2 + 1].mul * t[p].mul) % mod;

        t[p * 2].add = (ll)(t[p * 2].add * t[p].mul + t[p].add) % mod;
        t[p * 2 + 1].add = (ll)(t[p * 2 + 1].add * t[p].mul + t[p].add) % mod;

        t[p].mul = 1;
        t[p].add = 0;
    }

    void add(ll p, ll l, ll r, ll k)
    {
        if (t[p].l >= l && t[p].r <= r)
        {
            t[p].add = (t[p].add + k) % mod;
            t[p].sum = (ll)(t[p].sum + k * (t[p].r - t[p].l + 1)) % mod;

            return;
        }
        spread(p);
        t[p].sum = (t[p * 2].sum + t[p * 2 + 1].sum) % mod;
        ll mid = (t[p].l + t[p].r) >> 1;
        if (l <= mid)
            add(p * 2, l, r, k);
        if (r > mid)
            add(p * 2 + 1, l, r, k);
        t[p].sum = (t[p * 2].sum + t[p * 2 + 1].sum) % mod;
    }
    void mul(ll p, ll l, ll r, ll k)
    {
        if (t[p].l >= l && t[p].r <= r)
        {
            t[p].add = (t[p].add * k) % mod;
            t[p].mul = (t[p].mul * k) % mod;
            t[p].sum = (ll)(t[p].sum * k) % mod;
            return;
        }

        spread(p);
        t[p].sum = (t[p * 2].sum + t[p * 2 + 1].sum) % mod;
        ll mid = (t[p].l + t[p].r) >> 1;
        if (l <= mid)
            mul(p * 2, l, r, k);
        if (r > mid)
            mul(p * 2 + 1, l, r, k);
        t[p].sum = (t[p * 2].sum + t[p * 2 + 1].sum) % mod;
    }

    ll ask(ll p, ll l, ll r)
    {
        if (t[p].l >= l && t[p].r <= r)
        {
            return t[p].sum;
        }
        spread(p);
        ll val = 0;
        ll mid = (t[p].l + t[p].r) >> 1;
        if (mid >= l)
            val = (val + ask(p * 2, l, r)) % mod;
        if (mid < r)
            val = (val + ask(p * 2 + 1, l, r)) % mod;

        return val;
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    SegmentTree row, col;
    row.build(1, 1, n);
    col.build(1, 1, n);
    while (q--)
    {
        int sign, a, b, c, d;
        //    cout<<sign<<endl;
        cin >> sign;
        if (sign == 1)
        {
            cin >> a >> b;
            row.add(1, a, a, 1);
            col.add(1, b, b, 1);
        }
        else if (sign == 2)
        {
            cin >> a >> b;
            row.add(1, a, a, -1);
            col.add(1, b, b, -1);
        }
        else
        {
            cin >> a >> b >> c >> d;
            if (row.ask(1, a, c) == c - a+1 || col.ask(1, b, d) >= d- b+1)
            {
                cout << "Yes" << endl;
            }
            else
                cout << "No" << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //   cout<<1<<endl;
    solve();
}
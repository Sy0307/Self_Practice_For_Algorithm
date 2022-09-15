#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 8e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
istream &operator>>(istream &in, vector<int> &v)
{
    for (auto &i : v)
        in >> i;
    return in;
}
ostream &operator<<(ostream &out, vector<int> &v)
{
    for (auto &i : v)
        out << i << " ";
    return out;
}

int a[maxn], fa[maxn], id[maxn / 2];
set<pii> st;
int cnt = 0;

inl int find(int x)
{
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

inl void init(int k)
{
    fr(i, 1, k)
    {
        fa[i] = i;
    }
}
void solve()
{
    int n;
    cin >> n;
    fr(i, 1, n)
    {
        cin >> a[i];
        id[i] = i;
        st.insert(make_pair(a[i], i));
    }
    cnt = n;

    int q;
    cin >> q;
    init(n + q);
    while (q--)
    {
        int op, x, y;
        cin >> op >> x;
        // cout << op << endl;
        if (op == 1)
        {
            cin >> y;
            st.insert({a[id[x] = ++cnt] = y, cnt});
        }
        else if (op == 2)
        {
            cout << a[find(id[x])] << "\n";
            ;
        }
        else
        {

            cin >> y;
            vector<int> l, r;
            for (auto it = st.lower_bound(make_pair(x, 0)); it != st.end() && it->first <= y; it = st.erase(it))
            {
                {
                    if (it->first <= (x + y) / 2)
                    {
                        l.push_back(it->second);
                    }
                    else
                    {
                        r.push_back(it->second);
                    }
                }
            }
            if (!l.empty())
            {
                for (auto x : l)
                {
                    fa[x] = l[0];
                }
                st.insert(make_pair(a[l[0]] = x - 1, l[0]));
            }
            if (!r.empty())
            {
                for (auto x : r)
                {
                    fa[x] = r[0];
                }
                st.insert(make_pair(a[r[0]] = y + 1, r[0]));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    // while (T--)
    // {
    //     solve();
    // }
    return 0;
}
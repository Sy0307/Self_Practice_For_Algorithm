#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
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

stack<pii> st;
void solve()
{
    int n;
    cin >> n;
    fr(i, 1, n)
    {
        int x;
        cin >> x;
        if (st.empty())
        {
            st.push({x, 1});
            cout<<1<<endl;
            continue;
        }
        if (st.top().first == x)
        {
            st.push({x, st.top().second + 1});
        }
        else
        {
            st.push({x, 1});
        }

        if (st.size() && st.top().first == st.top().second)
        {
            int t = st.top().first;
            while (t--)
            {
                st.pop();
            }
        }
        cout << st.size() << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
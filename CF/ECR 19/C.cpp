#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
#define inl inline
#define endl '\n'
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

char f[maxn];
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    f[n + 1] = 'z' + 1;
    for (int i = n; i >= 1; i--)
    {
        f[i] = min(f[i + 1], s[i]);
    }
    stack<char> st;
    string ans = "";
    fr(i,1,n)
    {
        st.push(s[i]);
        while(st.size()&&st.top()<=f[i+1])
        {
            ans+=st.top();
            st.pop();
        }
    }
    while(st.size())
    {
        ans+=st.top();
        st.pop();
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
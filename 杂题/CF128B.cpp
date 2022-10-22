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

string s;
using psi = pair<string, int>;
multiset<psi> st;
void solve()
{
    cin >> s;
    int len = s.size();
    fr(i, 0, len - 1)
    {
        st.insert({s.substr(i,1), i+1});
        // cout<<s.substr(i,1)<<endl;
    }
    int cnt = 0;
    int k;
    cin >> k;
    while (st.size())
    {
        auto now = st.begin();
        auto tmp = *now;
        cnt++;
        if (cnt == k)
        {
            cout << tmp.first << endl;
            return;
        }
        st.erase(now);
        string str="";
        if (tmp.second < len)
        {
            str = tmp.first;
            str += s[tmp.second];
            st.insert({str, tmp.second + 1});
        }
    }
    cout << "No such line." << endl;
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
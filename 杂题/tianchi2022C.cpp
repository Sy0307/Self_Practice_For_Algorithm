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

class Solution
{
public:
    vector<int> arrangeBookshelf(vector<int> &order, int limit)
    {
        map<int, int> mp,ins;
        for (auto x : order)
            mp[x]++;
        vector<int> ans;
        for (int x : order)
        {
            if (ins[x] == limit)
            {
                mp[x] --;
                continue;
            }
            while (ans.size() && x < ans.back() && mp[ans.back()] > limit)
            {
                ins[ans.back()]--;
                mp[ans.back()]--;
                ans.pop_back();
            }
            ans.push_back(x);
            ins[x]++;
        }
        return ans;
    }
};
void solve()
{
    Solution s;
    vector<int> order = {2,3,2,2,1,1,2,1,3,2,3,4,2};
    int limit = 3;
    auto ans  =  s.arrangeBookshelf(order, limit) ;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
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
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define ford(i, a, b) for(int i = a; i >= b; i--)
#define forall(i, a) for(auto &i : a)

void solve()
{
    string s;
    cin >> s;
    auto bfs = [&]()
    {
        map<string, int> mp;
        queue<pair<string, int>> q;
        q.push({ s,0 });
        int ans = 0;
        while (q.size())
        {
            auto now = q.front();
            auto cnt = now.second;
            auto cur = now.first;
            q.pop();
            if (cur == "atcoder")
            {
                ans = cnt;
                return ans;
            }
            for (int i = 0;i < s.size() - 1;i++)
            {
                int j = i + 1;
                {
                    if (i == j) continue;
                    swap(cur[i], cur[j]);
                    if (!mp.count(cur))
                    {
                        q.push({ cur,cnt + 1 });
                        mp[cur] = 1;
                    }
                    swap(cur[i], cur[j]);
                }
            }
        }
        return ans;
    };
    cout << bfs() << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
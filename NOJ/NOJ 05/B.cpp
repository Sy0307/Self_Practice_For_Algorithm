#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxn = 1e5 + 5, INF = 0x3f3f3f3f;
char s1[maxn], s2[maxn];

void solve()
{
        int n;
        cin >> n >> s1 + 1 >> s2 + 1;
        set<int> pos[3];
        bool success = 1;
        for (int i = 1; i <= n; i++)
            pos[s1[i] - 'a'].insert(i);
        for (int i = 1; i <= n; i++)
        {
            if (s1[i] != s2[i])
            {
                if (s1[i] == 'a' && s2[i] == 'b')
                {
                    auto itb = pos[1].lower_bound(i);
                    if (itb != pos[1].end())
                    {
                        auto itc = pos[2].lower_bound(i);
                        if (itc == pos[2].end() || *itc > *itb)
                        {
                            swap(s1[i], s1[*itb]);
                            int t = *itb;
                            pos[0].erase(i);
                            pos[0].insert(t);
                            pos[1].erase(t);
                            pos[1].insert(i);
                        }
                    }
                }
                else if (s1[i] == 'b' && s2[i] == 'c')
                {
                    auto itc = pos[2].lower_bound(i);
                    if (itc != pos[2].end())
                    {
                        auto ita = pos[0].lower_bound(i);
                        if (ita == pos[0].end() || *ita > *itc)
                        {
                            swap(s1[i], s1[*itc]);
                            int t = *itc;
                            pos[1].erase(i);
                            pos[1].insert(t);
                            pos[2].erase(t);
                            pos[2].insert(i);
                        }
                    }
                }
            }
            if (s1[i] != s2[i])
            {
                success = 0;
                break;
            }
        }
        cout << (success ? "YES" : "NO") << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
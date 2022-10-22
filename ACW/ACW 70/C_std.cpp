#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

using i64 = long long;

constexpr int INF = 1E9, P = 1E9 + 7;
constexpr double pi = acos(-1);

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.setf(ios::fixed); cout.precision(15);

    int n;
    cin >> n;

    vector<int> w(n);
    for (auto &wi : w)
        cin >> wi;

    vector<pair<int, int>> g[n];

    vector<vector<i64>> dp(n, vector<i64> (2, 0));

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a --, b --;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    i64 ans = 0;
    function<void(int, int)> DFS = [&] (int u, int fa) {
        dp[u][0] = 0, dp[u][1] = w[u];
        i64 tmx1 = 0, tmx2 = 0;
        for (auto it : g[u]) {
            int v = it.fi, cost = it.se;
            if (v == fa)
                continue;
            DFS(v, u);

            if (dp[v][1] > cost) {
                if (dp[v][1] - cost > tmx1) {
                    tmx2 = tmx1;
                    tmx1 = dp[v][1] - cost;
                } else if (dp[v][1] - cost > tmx2) {
                    tmx2 = dp[v][1] - cost;
                }
            }

            dp[u][0] = max(dp[u][0], max(dp[v][0], dp[v][1]));
        }

        ans = max(ans, tmx1 + tmx2 + dp[u][1]);
        dp[u][1] += tmx1;

        return ;
    };

    DFS(0, -1);

    cout << max(ans, max(dp[u][0], dp[u][1]) << "\n";

    return 0;
}




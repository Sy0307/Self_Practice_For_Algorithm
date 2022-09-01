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

double f[maxn];
void solve()
{
    int n;
    cin >> n;
    f[1] = 3.5;
    fr(i, 2, n)
    {
        fr(j, 1, 6)
        {
            if (double(j) > f[i-1])
            {
                f[i] += 1.0 * j;
            }
            else
                f[i] += f[i - 1];
        }
        f[i] /= 6.0;
    }
    printf("%.10f\n", f[n]);
}
int main() {
    //ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    solve();
    return 0;
}
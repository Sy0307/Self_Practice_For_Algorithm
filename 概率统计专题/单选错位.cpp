#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e7 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

int n,a[maxn];
void init()
{
    int A,B,C;
    scanf("%d%d%d%d%d", &n, &A, &B, &C, a + 1);
    for (int i = 2; i <= n; i++)
        a[i] = ((long long)a[i - 1] * A + B) % 100000001;
    for (int i = 1; i <= n; i++)
        a[i] = a[i] % C + 1;
}
void solve()
{
    init();
    double ans = 0;
    a[n+1] = a[1];
    fr(i, 1, n )
    {
        ans += 1.0 / (double)max(a[i], a[i + 1]);
    }
    cout << fixed<<setprecision(3)<< ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    //   cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
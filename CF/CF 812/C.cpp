#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

void solve()
{
    int n;
    cin >> n;
 //   cout<<n<<endl;
    vector<int> a(n + 1);
    int w = n, now = n;
    while (n)
    {
        int t = sqrt(n);
        while(!(n-1<=t*t && t*t <=2*(n-1))) t++;
        int kk = t*t - (n-1);
        int x = n - kk;
        for(int i=1;i<=x;i++)
        {
            a[now] = t*t - now +1 ;
            now--;
        }
        n-=x;
    }
    for (int i = 1; i <= w; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
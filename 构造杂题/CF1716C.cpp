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

int n;
void print(vector<int> &a)
{
    fr(i,1,n)
    {
        cout<<a[i]<<" ";
    }   
    cout<<"\n";
}
void solve()
{
    cin >> n;

    cout << n << "\n";
    vector<int> a(n + 1);
    fr(i, 1, n)
    {
        a[i] = i;
    }
    print(a);
    swap(a[1], a[n]);
    print(a);
    int pos = n;
    fr(i,2,n-1)
    {
        swap(a[pos] , a[i]);
        pos = i;
        print(a);
    }
}
int main()
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
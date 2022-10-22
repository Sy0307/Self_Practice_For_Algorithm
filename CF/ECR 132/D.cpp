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

char s[maxn];
bool check(int n)
{
    int sum = 0;
    fr(i, 1, n)
    {
        if (s[i] == '(')
        {
            sum++;
        }
        else
            sum--;
        if (sum < 0)
        {
            return true;
        }
    }
    return false;
}

void solve()
{
    cin >> (s + 1);
    int n = strlen(s+1);
    int l = 0, r = 0;
    fr(i, 1, n)
    {
        if (s[i] == '(')
        {
            l++;
        }
        else if (s[i] == ')')
        {
            r++;
        }
    }
    if (l == n / 2 || r == n / 2)
    {
        cout << "YES" << endl;
        return;
    }
    int maxr = INT_MAX, minl = INT_MIN;
    l = n/2 - l;
    fr(i, 1, n)
    {
        if (s[i] == '?')
        {
            if (l)
            {
                l--;
                s[i] = '(';
                minl = max(i, minl);
            }
            else
            {
                s[i] = ')';
                maxr = min(i, maxr);
            }
        }
    }
    swap(s[minl], s[maxr]);
    if (check(n))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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
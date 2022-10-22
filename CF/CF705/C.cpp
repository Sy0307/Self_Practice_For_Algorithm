#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 4e5 + 10;
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

int k, n;
int cnt[maxn];
int get(int x)
{
    return (k - x % k) % k;
}
void solve()
{
    cin >> n >> k;
    memset(cnt, 0, sizeof(cnt));
    string s;
    cin >> s;
    for (auto c : s)
    {
        cnt[c - 'a']++;
    }

    int sum = 0;
    fr(i, 0, 25)
    {
        sum += get(cnt[i]);
    }
    bool f = 1;
    if (!sum)
        cout << s << endl;
    else if (n % k != 0)
        cout << -1 << endl;
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            sum = sum - get(cnt[s[i] - 'a']) +
                  get(--cnt[s[i] - 'a']);
            for (int j = s[i] - 'a' + 1; j < 26; j++)
            {
                int last = sum;
                sum = sum - get(cnt[j]) + get(++cnt[j]);
                if (sum + i + 1 <= n)
                {
                    fr(pos, 0, i - 1)
                    {
                        cout << s[pos];
                    }
                    cout << (char)('a' + j);

                    fr(pos, 1, n - sum - (i + 1))
                    {
                        cout << 'a';
                    }

                    for (int pos = 0; pos < 26; pos++) // sum个需要的字符
                    {
                        int res = get(cnt[pos]);
                        while (res)
                            res--, cout << char(pos + 'a');
                    }

                    cout << endl;
                    f = 0;
                    break;
                }
                cnt[j]--;
                sum = last;
            }
            if (!f)
                break;
        }
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
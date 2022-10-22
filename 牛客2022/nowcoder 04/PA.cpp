#include <bits/stdc++.h>
using namespace std;
long long a[100010], b[20], c[100010];
int main()
{
    ios::sync_with_stdio(0);
    long long n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        for (int j = 0; j <= 15; j++)
        {
            b[j] += (a[i] >> j) & 1;
        }
    }
    if (n == 1)
        cout << "0/1";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 15; j++)
        {
            if (b[j])
            {
                c[i] += (1 << j);
                b[j]--;
            }
        }
    }
    if ((sum % n) == 0)
    {
        long long ave = sum / n;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (c[i] - ave) * (c[i] - ave);
        }
        if (ans == 0)
        {
            cout << "0/1";
            return 0;
        }
        long long zzz = __gcd(ans, n);
        ans /= zzz;
        n /= zzz;
        cout << ans << "/" << n;
    }
    else
    {
        long long u1 = sum / __gcd(sum, n);
        long long u2 = n / __gcd(sum, n);
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (c[i] * u2 - u1) * (c[i] * u2 - u1);
        }
        u2 = u2 * u2 * n;
        long long qqq = __gcd(ans, u2);
        ans = ans / qqq;
        u2 = u2 / qqq;
        cout << ans << "/" << u2;
    }
}
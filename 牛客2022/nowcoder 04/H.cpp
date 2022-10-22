#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        int n;
        cin >> n;
        int fg[110] = {0};
        int s = 0 ;
        for(int i=1;i<=n;i++)
        {
            s+=(n-i+1)*i;
        }
        for (int i = 1; i <= n; i++)
        {
            fg[i] = n + 1 - i;
        }
        for (int i = (int)sqrt(s); i >= 1; i--)
        {
            if (s % i == 0)
            {
                a = max(i, s / i);
                b = min(i, s / i);
                break;
            }
        }
        cout<<a<<" "<<b<<endl;
        cout << 2 * (a + b) << endl;
        for (int i = 1; i <= b; i++)
        {
            int t = a;
            for (int j = n; j >= 1; j--)
            {
                while (fg[j] && j <= t)
                {
                    cout << i - 1 << " " << a - t << " " << i << " " << a - t + j << endl;
                    fg[j]--;
                    t -= j;
                }
                if (t == 0)
                    break;
            }
        }
    }
}
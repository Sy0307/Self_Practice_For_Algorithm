#include <iostream>
using namespace std;
int a[200010];
bool ddd = 0;
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        bool fg = 1;
        long long n, a0, k, sssu = 0, aas = 0;
        cin >> n >> a0 >> k;
        aas = a0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            aas += a[i];
        }
        int i = 1, j = 0;
        while (1)
        {
            if (a0 == aas)
                break;
            if (a0 >= 100000)
                break;
            if (sssu == n)
                break;
            if (a0 >= a[j + 1] && a[j + 1])
            {
                a0 += a[j + 1];
                a[j + 1] = 0;
                sssu++;
                i++;
                j++;
            }
            else
            {
                for (int l = j + 2; l <= j + k; l++)
                {
                    if (a0 == aas)
                        break;
                    if (sssu == n)
                        break;
                    if (!a[l])
                        continue;
                    int sum = 0, ffg = 1;
                    for (int m = l; m >= j + 1; m--)
                    {
                        if (a0 + sum >= 100000)
                        {
                            ddd = 1;
                            break;
                        }
                        if (a0 + sum >= a[m])
                        {
                            sum += a[m];
                        }
                        else
                        {
                            ffg = 0;
                            break;
                        }
                    }
                    if (ddd)
                        break;
                    if (ffg)
                    {
                        a0 += sum;
                        j++;
                        for (int m = l; m >= j + 1; m--)
                        {
                            if (!a[m])
                            {
                                j = m + 1;
                                break;
                            }
                            sssu++;
                            a[m] = 0;
                        }
                        break;
                    }
                    if (l == j + k)
                        fg = 0;
                }
            }
            if (ddd)
                break;
            if (!fg)
                break;
        }
        if (fg)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
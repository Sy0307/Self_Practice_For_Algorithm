#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int flag, x;
    int label = 0;
    while (q--)
    {
        cin >> flag;
        if (flag == 1)
        {
            cin >> x;
            label += x;
            label %= n;
        }
        else
        {
            cin >> x;
            x--;
            cout << s[(x+ n -label) % n] << endl;
        }
    }
}
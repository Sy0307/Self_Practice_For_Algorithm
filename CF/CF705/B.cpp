#include <bits/stdc++.h>

const int N = 400010;
const int mod = 998244353;
#define forn(i, b, e, k) for (int i = b; i <= e; i += k)
#define fori(i, b, e, k) for (int i = b; i >= e; i -= k)
#define vi std::vector<int>
#define pii std::pair<int, int>
#define ll long long

int t, h, m;
char s[10];

int ref(int x)
{
    if (!x || x == 1 || x == 8)
        return x;
    if (x == 2)
        return 5;
    if (x == 5)
        return 2;
    return -1;
}

bool ok(int x, int y)
{
    int newx1 = ref(y % 10);
    int newx0 = ref(y / 10);
    int newy1 = ref(x % 10);
    int newy0 = ref(x / 10);
    int newx = newx1 * 10 + newx0;
    int newy = newy1 * 10 + newy0;
    return newx1 != -1 && newx0 != -1 && newy1 != -1 && newy0 != -1 &&
           newx >= 0 && newx < h && newy >= 0 && newy < m;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%s", &h, &m, s + 1);
        int a = (s[1] - '0') * 10 + s[2] - '0';
        int b = (s[4] - '0') * 10 + s[5] - '0';
        int cura = a, curb = b;
        while (1)
        {
            if (ok(cura, curb))
            {
                break;
            }
            ++curb;
            if (curb == m)
                cura = (cura + 1) % h, curb = 0;
        }
        printf("%d%d:%d%d\n", cura / 10, cura % 10, curb / 10, curb % 10);
    }
    return 0;
}
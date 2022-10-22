#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int value(char ch)
{
    if (ch == 'T')
        return 8;
    if (ch == 'J')
        return 9;
    if (ch == 'Q')
        return 10;
    if (ch == 'K')
        return 11;
    if (ch == 'A')
        return 12;
    return ch - '2';
}

int color(char ch)
{
    if (ch == 'S')
        return 0;
    if (ch == 'H')
        return 1;
    if (ch == 'D')
        return 2;
    if (ch == 'C')
        return 3;
    return -1;
}

int tests(char cards[][3])
{
    //冒泡终于有用武之地了╮(╯▽╰)╭
    for (int i = 5; i > 1; --i)
        for (int j = 1; j < i; ++j)
            if (cards[j - 1][0] > cards[j][0])
            {
                swap(cards[j - 1][0], cards[j][0]);
                swap(cards[j - 1][1], cards[j][1]);
            }

    int maps[5][13];
    memset(maps, 0, sizeof(maps));
    for (int i = 0; i < 5; ++i)
    {
        maps[color(cards[i][1])][value(cards[i][0])]++;
        maps[4][value(cards[i][0])]++;
    }
    // royal-flush
    //  royal-flush | straight-flush
    for (int i = 0; i < 4; ++i)
        for (int j = 8; j >= 0; --j)
            if (maps[i][j] & maps[i][j + 1] & maps[i][j + 2] & maps[i][j + 3] & maps[i][j + 4])
            {
                if (maps[i][8] && maps[i][9] && maps[i][10] && maps[i][11] && maps[i][12])
                {
                    return INT_MAX - 1;
                }
                else
                {
                    return 13 * 13 * 13 * 13 * 13 + 40 + j;
                }
            }
    // four-of-a-kind
    for (int i = 0; i < 13; ++i)
        if (maps[4][i] >= 4)
            return 13 * 13 * 13 * 13 * 13 + 20 + i;
    // full-house
    int three = 0, two = 0;
    for (int i = 12; i >= 0; --i)
    {
        if (maps[4][i] == 2)
            two = two * 15 + i + 1;
        if (maps[4][i] == 3)
            three = i + 1;
    }
    if (two && three)
        return 13 * 13 * 13 * 13 * 13 + three + 1;
    // flush
    for (int i = 0; i < 4; ++i)
    {
        int count = 0, number = 0;
        for (int j = 12; j >= 0; --j)
            for (int k = 0; k < maps[i][j]; ++k)
            {
                ++count;
                number = number * 13 + j;
            }
        if (count == 5)
            return number;
    }
    // straight
    for (int i = 0; i < 9; ++i)
        if (maps[4][i] & maps[4][i + 1] & maps[4][i + 2] & maps[4][i + 3] & maps[4][i + 4])
            return i - 20;
    // three-of-a-kind
    if (three)
        return three - 40;

    int ans = 0;
    for (int i = 12; i >= 0; --i)
        if (maps[4][i] == 1)
            ans = ans * 13 + i;
    // two-pairs
    if (two >= 15)
        return two * 15 + ans - 8000;
    // one-pair
    if (two)
        return two * 13 * 13 * 13 + ans - 13 * 13 * 13 * 13 * 30;
    // high-card
    return ans - 13 * 13 * 13 * 13 * 50;
}

char white[5][3], black[5][3];
char community[10][3];
char b[5][3], w[5][3];
map<pair<int, int>, int> mp;
int sg(int c, int lhs, int rhs)
{
    if (mp.count({lhs, rhs}))
        return mp[{lhs, rhs}];
    if (c == 6)
    {
        int lv = tests(black), rv = tests(white);
        int res = lv == rv;
        if (!res && lv > rv)
            res = 2;
        return mp[{lhs, rhs}] = res;
    }
    else
    {
        int sta = 0, res;
        const int rul = lhs | rhs;
        for (int i = 0; sta != 2 && i < 6; ++i)
        {
            if ((rul >> i) & 1)
                continue;
            if (c & 1)
            {
                strcpy(white[2 + (c >> 1)], community[i]);
                res = 2 - sg(c + 1, lhs, rhs | (1 << i));
            }
            else
            {
                strcpy(black[2 + (c >> 1)], community[i]);
                res = 2 - sg(c + 1, lhs | (1 << i), rhs);
            }
            sta = max(res, sta);
        }
        return mp[{lhs, rhs}] = sta;
    }
};

void solve()
{
    for (int i = 0; i < 2; ++i)
        scanf("%s", black[i]);
    for (int i = 0; i < 2; ++i)
        scanf("%s", white[i]);
    for (int i = 0; i < 6; ++i)
        scanf("%s", community[i]);
    mp.clear();
    int res = sg(0, 0, 0);
    if (res == 1)
        cout << "Draw" << endl;
    else if (res)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
}

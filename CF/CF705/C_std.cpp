int get(int x)
{
    return (k - x % k) % k;
}
void solve()
{
    cin >> n >> k;
    memset(cnt, 0, sizeof cnt);
    string s;
    cin >> s;
    //统计每个字母的出现次数
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;

    int sum = 0; //计算
    for (int i = 0; i < 26; i++)
        sum += get(cnt[i]);
    bool flag = 1;
    if (sum == 0)
        cout << s << '\n';
    else if (n % k != 0)
        cout << -1 << '\n';
    else
    {
        for (int i = n - 1; i >= 0; i--) //从后往前依次枚举每一个位置,
        {
            sum = sum - get(cnt[s[i] - 'a']) + get(--cnt[s[i] - 'a']);
            //删去当前位置造成的影响
            for (int j = s[i] - 'a' + 1; j < 26; j++) //枚举放每一个字母
            {
                int last = sum;
                sum = sum - get(cnt[j]) + get(++cnt[j]); //更新状态
                if (sum + i + 1 <= n)                    //不超过n个字符 合法
                {
                    // 0~i 个 原本保留的字符
                    for (int pos = 0; pos < i; pos++)
                        cout << s[pos];

                    cout << char('a' + j); //当前字符

                    for (int pos = 1; pos <= n - sum - (i + 1); pos++) //空缺的字符
                        cout << 'a';

                    for (int pos = 0; pos < 26; pos++) // sum个需要的字符
                    {
                        int res = get(cnt[pos]);
                        while (res)
                            res--, cout << char(pos + 'a');
                    }

                    cout << '\n';
                    flag = 0;
                    break;
                }
                cnt[j]--;
                sum = last;
            }
            if (flag == 0)
                break;
        }
    }
}
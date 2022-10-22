#include <cstdio> //码风凑合看吧QAQ
#include <iostream>
#include <algorithm>
#define N 10000050
using namespace std;
struct node
{
    int num; //在输入中是第几个
    int t;   //到期日
} market[N]; //超市牛奶
int cmp(struct node a, struct node b)
{
    if (a.t != b.t)
        return a.t < b.t;
    else
        return a.num < b.num;
} //比较函数
int home[N], answer[N], spare[N]; //见解析
int main()
{
    int i, t, n, m, k, maxt = 0, sum = 0, now = 1, q = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &t);
        maxt = max(maxt, t); // maxt记录保质期最大是多少天
        home[t]++;           //家里有多少牛奶这一天到期
    }
    for (i = 1; i <= m; i++)
    {
        scanf("%d", &market[i].t);
        market[i].num = i;
        maxt = max(maxt, market[i].t);
    }
    sort(market + 1, market + m + 1, cmp);
    for (i = maxt; i >= 0; i--) //注意从后往前遍历
    {
        if (home[i] <= k)           //如果这一天家里要解决的数量小于k
            spare[i] = k - home[i]; //这一天还可以喝多少瓶
        else
        {
            if (i == 0) //到了第0天还有超过k的牛奶要解决
            {
                printf("-1");
                return 0;
            }
            home[i - 1] += home[i] - k; //前一天要解决的数量要加上今天没解决完的数量
        }
    }
    for (i = 0; i <= maxt; i++)
    {
        if (spare[i] > 0) //如果可以买
        {
            while (market[now].t < i && now <= m)
                now++;                       //筛去已经到保质期的
            while (spare[i] > 0 && now <= m) //将能加的都加上
            {
                answer[++q] = market[now].num;
                spare[i]--;
                now++;
            }
        }
    }
    sort(answer + 1, answer + 1 + q); //把答案按照输入数据排序
    printf("%d\n", q);
    for (i = 1; i <= q; i++)
        printf("%d ", answer[i]);
}
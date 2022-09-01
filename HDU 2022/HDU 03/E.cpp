#include <bits/stdc++.h>

#define I scanf
#define OL puts
#define O printf
#define F(a, b, c) for (a = b; a < c; a++)
#define FF(a, b) for (a = 0; a < b; a++)
#define FG(a, b) for (a = b - 1; a >= 0; a--)
#define LEN 100010
#define MAX 1 << 30
#define V vector<int>
#define ll long long
#define LS(i) i << 1
#define RS(i) i << 1 | 1

using namespace std;

int ans;

struct node
{
    int l, r, x, y, w;
    node() { v = 0; }
} tree[LEN * 4];
int x[LEN];
int y[LEN];
int w[LEN];
//建树
void build(int l, int r, int i)
{ //记录 [ l , r ]上的值，当前索引为 i
    tree[i].l = l;
    tree[i].r = r;
    if (l == r)
    { //如果访问到了叶子节点
        tree[i].w = w[l];
        tree[i].x = x[l];
        tree[i].y = y[l];
        //当前值就是arr[l,r]的值
        return;
    }
    int m = (l + r) / 2;                       //二分
    build(l, m, LS(i));                        //左子树
    build(m + 1, r, RS(i));                    //右子树
    tree[i].v = tree[LS(i)].v + tree[RS(i)].v; //递归建树出栈后，前驱结点的值为后继结点的和
}
//区间查询
void query(int i, int l, int r, int x, int y)
{ // i 为当前树的索引，初试化调用为 1 。查询 [ l , r ]区间上的和
    if (tree[i].l >= l && tree[i].r <= r)
    {                     //如果查询区间包裹住了当前结点区间
        ans = max(ans,min(x-tree[i].x,)); //直接加上这个结点的值
        return;
    }
    if (l <= tree[LS(i)].r)       //查询的 l 比左子树的右端点小
        query(LS(i), l, r, x, y); //向左递归
    if (r >= tree[RS(i)].l)       //查询的 r 比右子树的左端点大
        query(RS(i), l, r, x, y); //向右递归
}

int main()
{
    ios::sync_with_stdio(false);
    int n, q, i, t, op, k;
    I("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i] >> w[i];
    }
    build(1, n, 1);
    while (q--)
    {
        int x, y, z;
        cin >> x >> y;
        query(1, 1, n, x, )
    }
    return 0;
}
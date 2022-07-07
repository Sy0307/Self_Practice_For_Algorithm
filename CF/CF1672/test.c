#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a[10005];
int inc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int n;
    scanf("%d", &n);
    int res[10005];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), inc);
    if (n == 0||n==1)
    {
        printf("%d", n);
        return 0;
    }
    int last = a[0], ans = 0;
    int now = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != last)
        {
            if (now & 1)
                ans++;
            now = 1;
        }
        else
            now++;
        last = a[i];
    }
    if (now & 1)
        ans++;
    printf("%d", ans);
    return 0;
}
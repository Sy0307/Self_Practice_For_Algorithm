#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;

// vector<int> alls;

int ans = 0;
struct node
{
    int a;
    int b;
} z[maxn];
bool cmp(node aa, node bb)
{
    if (aa.a == bb.a)
        return aa.b < bb.b;
    return aa.a < bb.a;
}
/*int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}*/
int main()
{
    int t;
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        ans = 0;
        // alls.clear();
        priority_queue<int> s;
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> z[i].a >> z[i].b;
            // alls.push_back(z[i].a);
            // alls.push_back(z[i].b);
        }
        // sort(alls.begin(), alls.end());
        // alls.erase(unique(alls.begin(), alls.end()), alls.end());
        // for(int i=0;i<n;i++) z[i].a=find(z[i].a),z[i].b=find(z[i].b);
        sort(z, z + n, cmp);
        for (int i = 0; i < n; i++)
        {
            if (s.empty())
            {
                s.push(-z[i].b);
                continue;
            }
            while (z[i].a > abs(s.top()))
            {
                ans++;
                for (int j = 0; j < k; j++)
                {
                    if (s.empty())
                    {
                        break;
                    }
                    s.pop();
                }
                if (s.empty())
                {
                    break;
                }
            }
            s.push(-z[i].b);
        }
        cout << ans + ((s.size() + k - 1) / k) << endl;
    }
}
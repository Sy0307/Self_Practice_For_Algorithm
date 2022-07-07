#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5, INF = 0x3f3f3f3f;
int ans[maxn], a[maxn];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        if (n & 1){
            cout << "NO" << '\n';
            continue;
        }
        sort(a + 1, a + n + 1);
        for(int i = 1, j = 1; i <= n; i += 2, j++) ans[i] = a[j];
        for(int i = 2, j = n / 2 + 1; i <= n; i += 2, j++) ans[i] = a[j];
        bool success = 1;
        for(int i = 2; i <= n - 1; i++){
            if (ans[i] > ans[i - 1] && ans[i] > ans[i + 1]) continue;
            if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) continue;
            success = 0;
            break;
        }
        if (!(ans[1] > ans[n] && ans[1] > ans[2]) && !(ans[1] < ans[n] && ans[1] < ans[2])){
            success = 0;
        }
        if (!(ans[n] > ans[n - 1] && ans[n] > ans[1]) && !(ans[n] < ans[n - 1] && ans[n] < ans[1])){
            success = 0;
        }
        if (success){
            cout << "YES" << '\n';
            for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
            cout << '\n';
        }
        else cout << "NO" << '\n';
    }

}
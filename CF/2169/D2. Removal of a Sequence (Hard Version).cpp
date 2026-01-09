#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
double pi = acos(-1);
const int N = 1e12, mod = 998244353, inf = 1e18 + 5;
/*
    k_i = k_(i+1) + (k_(i+1) - 1) / (y - 1)
    k_i 每次增量为cur =  (k_(i+1) - 1) / (y - 1)
    考虑将相等的cur一次性加给k_i

    若相同增量cur的个数为n
    则 k_(i+n) = k_i + n * cur
*/
void solve() {
    int x,y,k; cin >> x >> y >> k;
    // x: 操作次数
    // y: 删除下标base
    // k: 第k位置
    if(y == 1){
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < x; ){ 
        int cur = (k - 1) / (y - 1); 
        if (cur == 0) break; // 增量cur = 0表示k的值不再发生变化
        int n = ((y - 1) - ((k - 1) % (y - 1)) + (cur - 1)) / cur; 
        int cnt = min(x - i, n); // 实际批量处理的步数
        k = k + cnt * cur; 
        if(k > N){
            cout << -1 << endl;
            return;
        }
        i += cnt;
    }
    cout << k << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}


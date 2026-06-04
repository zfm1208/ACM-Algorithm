#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'

/*
题目要求：
轮盘上有 1 到 N，初始指针指向 1。
第一阶段先把轮盘顺时针旋转 K 次。
第二阶段每次操作包含两步：
1. 翻转从指针开始、顺时针方向的前 N - 1 个数字。
2. 翻转除指针外的 N - 1 个数字。
求最少操作几次能恢复初始状态，不能恢复输出 -1。

中文思路：
假设当前从指针开始顺时针看到的序列是：
a1, a2, a3, ..., aN

第一步翻转前 N - 1 个数字后变成：
a(N-1), a(N-2), ..., a1, aN

第二步再翻转除指针外的 N - 1 个数字后变成：
a(N-1), aN, a1, a2, ..., a(N-2)

这相当于在“旋转次数”的意义下，又顺时针旋转了 2 次。
所以第一阶段后总旋转量是 K，每次恢复操作让旋转量 +2。

问题变成求最小非负整数 x，使得：
K + 2x ≡ 0 (mod N)

也就是：
2x ≡ -K (mod N)

分类讨论：
1. N 为奇数时，2 和 N 互质，一定有解。
   2 在模 N 意义下的逆元是 (N + 1) / 2。
2. N 为偶数时，2x 一定是偶数。
   如果 K 是奇数，则不可能凑成 N 的倍数，输出 -1。
   如果 K 是偶数，把式子两边同时除以 2，答案为：
   x ≡ -K / 2 (mod N / 2)。
*/
void solve(){
    int n, k;
    cin >> n >> k;

    // 只关心旋转量对 n 取模后的结果。
    k %= n;

    if(n % 2 == 0){
        if(k % 2 == 1){
            cout << -1 << endl;
            return;
        }

        int m = n / 2;
        int need = (k / 2) % m;
        int ans = (m - need) % m;
        cout << ans << endl;
    }else{
        // n 为奇数时，inv2 是 2 在 mod n 下的逆元。
        int inv2 = (n + 1) / 2;
        int need = (n - k) % n;
        int ans = (__int128)need * inv2 % n;
        cout << ans << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}

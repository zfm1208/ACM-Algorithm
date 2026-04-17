#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
/*
 * 【核心思路与数学推导】
 * * 1. 破除异或伪装，反向推导：
 * 题目定义 p[i] = a[1] ⊕ a[2] ⊕ ... ⊕ a[i]
 * 显然可得 p[i] = p[i-1] ⊕ a[i]
 * 根据异或的自反性，可推导出：a[i] = p[i-1] ⊕ p[i]
 * * 2. 核心等价转换（降维打击）：
 * 题目要求我们选择 a[i] 满足 0 <= a[i] < 2^t。
 * 因为 a[i] = p[i-1] ⊕ p[i]，只要我们保证构造出的 p[i-1] 和 p[i] 都在 [0, 2^t - 1] 范围内，
 * 它们异或出来的结果 a[i] 就必定也在 [0, 2^t - 1] 范围内（两个小于 2^t 的数异或绝对不会超出 2^t - 1）。
 * => 结论：选择合法 a[i] 的过程，完全等价于直接、自由地在 [0, 2^t - 1] 范围内选择 p[i]！
 * * 3. 极简问题化：
 * 原问题转化为：有 n 个独立的变量 p[i]，每个变量的取值范围都是 [0, 2^t - 1]。
 * 问它们的总和能否恰好等于 S？
 * 因为变量可以取该范围内的任意整数，所以它们能凑出的总和是一个连续的区间：
 * - 最小总和：所有 p[i] 都取 0，Sum_min = 0
 * - 最大总和：所有 p[i] 都取 2^t - 1，Sum_max = n * (2^t - 1)
 * 只要目标 S 落在这个闭区间 [0, Sum_max] 内，就一定存在合法的分配方案。
 */
void solve(){
    int n, t, S;
    cin >> n >> t >> S;
    int max_S = n * ((1LL << t) - 1);
    if(S <= max_S){
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
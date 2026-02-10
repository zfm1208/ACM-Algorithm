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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
/*
    翡翠定理:
    如果你有一堆整数 v1, v2, .... , vm，你把它们加加减减（乘以任意整数系数），你能且只能凑出它们的最大公约数 (GCD) 的倍数。
    sum = v1 * k1 + v2 * k2 + v3 * k3 + ... + vm * km
    sum = __gcd(v1,v2,...,vm) * k
*/

/**
 * * 【题意简述】
 * 给定一个 N*M 的矩阵，每个格子有数值和类型（0或1）。
 * 我们可以对任意 k*k 的子矩阵内所有元素加上任意整数 c。
 * 问：是否能通过若干次操作，使得类型 0 的总和等于类型 1 的总和？
 * * 【解题思路】
 * 1. 转化目标：
 * 设 Sum0 为类型 0 的总和，Sum1 为类型 1 的总和。
 * 目标是让 Sum0 == Sum1，即让初始差值 Diff = |Sum0 - Sum1| 变为 0。
 * * 2. 分析操作影响 (Invariant)：
 * 对于任意一个 k*k 的子矩阵，假设其中有 cnt0 个类型 0，cnt1 个类型 1。
 * 如果我们给这个子矩阵都加上 c：
 * - Sum0 增加 c * cnt0
 * - Sum1 增加 c * cnt1
 * - 此时总差值 Diff 的变化量 delta = c * (cnt0 - cnt1)。
 * 即：我们可以让总差值增加或减少 |cnt0 - cnt1| 的任意整数倍。
 * * 3. 数学模型 (GCD & 裴蜀定理)：
 * 我们有许多个可能的 k*k 子矩阵，每个子矩阵提供一个“变化能力” v_i = |cnt0 - cnt1|。
 * 根据裴蜀定理，这些 v_i 的线性组合能凑出的数值，一定是它们最大公约数 (GCD) 的倍数。
 * 设 g = GCD(所有可能的子矩阵的 |cnt0 - cnt1|)。
 * 只要初始 Diff 是 g 的倍数 (Diff % g == 0)，我们就能通过操作将 Diff 消除为 0。
 * * 4. 实现细节：
 * - 暴力枚举每个 k*k 区域内的 cnt0 和 cnt1 会超时。
 * - 使用【二维前缀和】预处理类型的数量，从而在 O(1) 时间内算出任意区域的 cnt1。
 * - cnt0 = k*k - cnt1。
 * - 时间复杂度：O(N*M)。
 */
void solve(){
    int n,m,k; cin >> n >> m >> k;
    vector<vector<int>> a(n+2,vector<int>(m+7));
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    vector<vector<int>> ai(n+2,vector<int>(m+7));
    vector<vector<int>> pre(n+2,vector<int>(m+7));
    int sum0 = 0, sum1 = 0;
    for(int i = 1; i <= n; i++){
        string s; cin >> s; s = " " + s;
        for(int j = 1; j <= m; j++){
            ai[i][j] = s[j] - '0'; 
            if(ai[i][j] == 0){
                sum0 += a[i][j];
            }else{
                sum1 += a[i][j];
            }
            pre[i][j] = ai[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }
    int diff = abs(sum0 - sum1);
    if(diff == 0){
        cout << "YES" << endl;
        return;
    }
    int gcd = 0;
    for(int i = 1; i <= n - k + 1; i++) {
        for(int j = 1; j <= m - k + 1; j++) {
            int r2 = i + k - 1;
            int c2 = j + k - 1;
            int cnt1 = pre[r2][c2] - pre[i-1][c2] - pre[r2][j-1] + pre[i-1][j-1];
            int cnt0 = k * k - cnt1;
            gcd = __gcd(gcd, abs(cnt0 - cnt1));
        }
    }
    if(gcd != 0 && diff % gcd == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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
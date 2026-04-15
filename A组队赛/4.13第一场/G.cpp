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
// https://qoj.ac/problem/5414

/*
================================================================================
【题解】Stop, Yesterday Please No More (QOJ 5414) - 相对运动与二维差分
================================================================================
核心思路：不追踪"洞"在哪里，而是追踪"绝对不死的袋鼠"作为一个刚体的运动轨迹。

[Step 1] 寻找"不死袋鼠"初始矩阵 (相对运动视角)
    - 假设没有洞，只有边界。袋鼠移动，等价于"袋鼠不动，网格边界反向移动"。
    - 维护相对边界 (u, d, l, r)。例如袋鼠往下走(D)，等于边界整体往上移(u--, d--)。
    - 取所有历史边界的交集 [U, D] 行和 [L, R] 列，这就是初始时站在里面、
      且全程绝对不会掉出边界的"不死袋鼠群"。它们在移动时始终保持这个矩形队形。

[Step 2] 计算洞口的"KPI"
    - 最终要求剩下 k 只袋鼠。
    - 初始的不死袋鼠总数为 total_safe = (D - U + 1) * (R - L + 1)。
    - 那么这个洞【必须】精准吃掉 remain = total_safe - k 只袋鼠。
    - 如果 remain < 0，说明不死袋鼠都不够 k 只，绝对无解 (0)。
    - 如果完全没有不死袋鼠 (L > R 或 U > D)，那存活必为 0。此时若 k 也是 0，
      则任意格子当洞都可以 (n * m)；否则无解 (0)。

[Step 3] 刚体平移与二维差分 (绝对运动视角)
    - 洞如何才能吃到"不死袋鼠"？只要不死矩形在移动中，曾经覆盖过洞口，
      洞口就能吃掉一只。（一只袋鼠只能死一次，所以去重极度关键）。
    - 重新模拟袋鼠的真实物理移动，此时追踪"不死矩形"的真实位置 (U, D, L, R)。
    - 每走到一个【全新】的位置 (用 vis 数组去重)，矩形所覆盖的区域内的任何一个
      格子如果作为洞口，都会让其吃掉的袋鼠数 + 1。
    - 使用二维差分 O(1) 将这个矩形区域 +1。

[Step 4] 前缀和统计答案
    - 跑一次二维前缀和，还原每个格子作为洞口能吃掉的袋鼠总数。
    - 统计值为 remain 的格子数量，即为答案！
================================================================================
*/
void solve(){
    int n,m,k; 
    cin >> n >> m >> k;
    string s; cin >> s;
    int U = 1, D = n, L = 1, R = m;
    int u = 1, d = n, l = 1, r = m;
    for(char c: s)
    {
        if(c == 'D') {u--,d--;}
        else if(c == 'U') {u++; d++;}
        else if(c == 'L') {r++; l++;}
        else if(c == 'R') {r--; l--;}
        
        L = max(L, l);
        R = min(R, r);
        U = max(U, u);
        D = min(D, d);
    }
    // 绝对安全袋鼠在 [U,D]行 [L,R]列
    if(L > R || U > D) {
        cout << (k == 0 ? n * m : 0) << endl;       
        return;
    }
    int remain = (D - U + 1) * (R - L + 1) - k;
    if(remain < 0) {
        cout << 0 << endl;
        return;
    }
    vector<vector<int>> dp(n+2,vector<int>(m+2));
    vector<vector<int>> vis(n+2, vector<int> (m+2));

    auto add = [&](int r1, int c1, int r2, int c2) {
        dp[r1][c1]++;
        dp[r1][c2 + 1]--;
        dp[r2 + 1][c1]--;
        dp[r2 + 1][c2 + 1]++;
    };

    add(U,L,D,R);
    vis[U][L] = 1;
    for(auto c: s)
    {
        if(c == 'D') {U++, D++;}
        else if(c == 'U') {U--; D--;}
        else if(c == 'L') {L--; R--;}
        else if(c == 'R') {L++; R++;}
        if(vis[U][L]) continue;
        vis[U][L] = 1;
        add(U,L,D,R);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            if(dp[i][j] == remain) ans++;
        }
    }
    cout << ans << endl;
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
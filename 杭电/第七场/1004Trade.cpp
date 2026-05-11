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
const int N = 505, mod = 998244353, inf = 1e18 + 5;

// dp[i][j][op1][op2] 
// i: 第 i 天结束
// j: 手里持有 j 股
// op1: 第 i 天的操作 (0:卖出, 1:买入, 2:无操作)
// op2: 第 i-1 天的操作 (0:卖出, 1:买入, 2:无操作)
int dp[N][N][3][3];
int A[N];

void solve(){
    int n; 
    cin >> n;
    // 注意：价格有 n+1 天，第 n+1 天用于清仓
    rep(i, 1, n + 1) cin >> A[i];

    // 1. 初始化 DP 数组为极小值（因为要求最大收益）
    rep(i, 0, n) {
        rep(j, 0, n) {
            rep(op1, 0, 2) {
                rep(op2, 0, 2) {
                    dp[i][j][op1][op2] = -inf;
                }
            }
        }
    }

    // 2. 初始边界：第 0 天结束时，持有 0 股，前两天的操作都是 "无操作(2)"，收益为 0
    dp[0][0][2][2] = 0;

    // 3. 开始状态转移
    rep(i, 1, n) {
        // 第 i 天之前，最多可能持有 i-1 股
        rep(j, 0, i - 1) { 
            rep(op1, 0, 2) {
                rep(op2, 0, 2) {
                    // 如果这个历史状态是不合法的，直接跳过
                    if (dp[i-1][j][op1][op2] == -inf) continue;

                    // =============== 选项 A: 今天选择买入 (买入不受限制) ===============
                    dp[i][j+1][1][op1] = max(dp[i][j+1][1][op1], dp[i-1][j][op1][op2] - A[i]);

                    // =============== 选项 B: 今天选择卖出 ===============
                    if (j > 0) { // 核心规则 1：手里必须有股票才能卖 (不允许卖空)
                        bool can_sell = true;
                        
                        // 核心规则 2：FOMO 浮盈加仓限制
                        // 如果当前是第 3 天及以后，且前两天都买了(op1==1 且 op2==1)，且价格没跌
                        if (i >= 3 && op1 == 1 && op2 == 1 && A[i-1] >= A[i-2]) {
                            can_sell = false; // 被强制要求买入，今天禁止卖出！
                        }
                        
                        // 如果允许卖出
                        if (can_sell) {
                            dp[i][j-1][0][op1] = max(dp[i][j-1][0][op1], dp[i-1][j][op1][op2] + A[i]);
                        }
                    }
                }
            }
        }
    }

    // 4. 结算答案
    int ans = -inf;
    // 遍历第 n 天结束时的所有合法状态
    rep(j, 0, n) {
        rep(op1, 0, 2) {
            rep(op2, 0, 2) {
                if (dp[n][j][op1][op2] != -inf) {
                    // 第 n+1 天无条件清仓：手里剩下的 j 股全部按 A[n+1] 卖掉
                    ans = max(ans, dp[n][j][op1][op2] + j * A[n+1]);
                }
            }
        }
    }
    
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
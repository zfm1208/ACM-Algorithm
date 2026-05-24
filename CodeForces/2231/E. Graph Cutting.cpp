#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 2005;

// dp[u][k][L]: 在 u 的子树中选了 k 个点，包含这 k 个点和 u 的最小连通块有 L 条边的方案数
long long dp[MAXN][3][MAXN];
int sz[MAXN]; // 记录子树中可能的最大边数，用于优化常数
vector<int> adj[MAXN];
long long total_ans;
int n, d;

void dfs(int u, int p) {
    // 1. 初始化当前节点 u 的状态
    for (int i = 0; i <= 2; ++i) {
        for (int L = 0; L <= d; ++L) {
            dp[u][i][L] = 0;
        }
    }
    dp[u][0][0] = 1; // 选 0 个点
    dp[u][1][0] = 1; // 选 u 作为 1 个点
    sz[u] = 0;

    // 2. 遍历合并子树
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);

        // 使用临时数组存放合并后的状态
        long long new_dp[3][MAXN];
        for (int i = 0; i <= 2; ++i) {
            for (int L = 0; L <= min(d, sz[u] + sz[v] + 1); ++L) {
                new_dp[i][L] = 0;
            }
        }

        // 树上背包合并
        for (int i = 0; i <= 2; ++i) {
            for (int Lu = 0; Lu <= min(d, sz[u]); ++Lu) {
                if (!dp[u][i][Lu]) continue; // 剪枝

                for (int j = 0; j <= 2; ++j) {
                    for (int Lv = 0; Lv <= min(d, sz[v]); ++Lv) {
                        if (!dp[v][j][Lv]) continue; // 剪枝

                        // 如果子树 v 贡献了点 (j > 0)，则必须走过 (u, v) 这条边，边数 + 1
                        int cost = (j > 0) ? 1 : 0;
                        int next_L = Lu + Lv + cost;

                        if (next_L > d - 1) continue; // 超过目标边数，直接舍弃

                        if (i + j == 3) {
                            // 凑齐 3 个点了！并且它们的 LCA 刚好是当前的 u
                            if (next_L == d - 1) {
                                total_ans += dp[u][i][Lu] * dp[v][j][Lv];
                            }
                        } else if (i + j < 3) {
                            // 还没凑齐 3 个点，把状态传递下去
                            new_dp[i + j][next_L] += dp[u][i][Lu] * dp[v][j][Lv];
                        }
                    }
                }
            }
        }

        // 3. 将临时数组更新回 dp[u]，并扩大背包容量上限
        sz[u] = min(d, sz[u] + sz[v] + 1);
        for (int i = 0; i <= 2; ++i) {
            for (int L = 0; L <= sz[u]; ++L) {
                dp[u][i][L] = new_dp[i][L];
            }
        }
    }
}

void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    total_ans = 0;
    // 从任意点（例如 1）为根开始 DFS 即可
    dfs(1, 0);
    
    cout << total_ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
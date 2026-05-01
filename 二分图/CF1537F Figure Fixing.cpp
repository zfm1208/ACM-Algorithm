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
    *题目的核心操作是：选择一条边，给它的两个端点同时 +k
    *我们在做这种“无限次操作判断是否能达到目标状态”的题时，第一反应永远是寻找不变量
    *如果我们看全图的总和：一次操作让总和增加了 2k。
    *这说明全图总和的奇偶性是永远不变的。（这是一个线索，但还不够解题）。
    *我们需要一个更强的不变量。
    *试想，怎么才能让这个操作的影响“抵消”掉？
    *节点 u 增加了 k，节点  v 也增加了 k。
    *如果在数学上我们赋予它们相反的符号，即让 u 的权重是 +1，v 的权重是 -1，
    *那么这次操作对带权总和的影响就是：k * (+1) + k * (-1) = 0
    
    ! 下面都是考察的二分图：
    ! 每次对一条边的两个端点同时增加/减少某值
    ! 每次交换相邻的两个元素
    ! 网格图（Grid）上每次覆盖 $1 \times 2$ 的多米诺骨牌 
*/
/*
 * 【核心模型：图论 - 二分图与奇偶环性质】
 * 
 * 1. 状态定义：
 *    令 d[i] = t[i] - v[i] (即每个节点距离目标的差值)。
 *    目标是让所有节点的 d[i] 变为 0。
 * 
 * 2. 操作等价转换：
 *    每次选一条边 (u, v) 加上 k，等价于 d[u] 和 d[v] 同时减去 k。
 *    性质：每次操作必定对两个相邻节点的差值产生【完全相同】的变化。
 * 
 * 3. 分类讨论 (基于图是否含奇环)：
 * 
 *    情况 A：图是二分图 (无奇环)
 *    - 可以将图进行黑白染色，每条边的两个端点必然是一黑一白。
 *    - 每次操作必定同时改变一个黑点和一个白点的值，且改变幅度相同。
 *    - 核心不变量：黑点差值总和 与 白点差值总和 的【差值】永远不变。
 *    - 判定的充要条件：初始状态下，必须有 sum(黑点d[i]) == sum(白点d[i])。
 * 
 *    情况 B：图不是二分图 (存在奇环)
 *    - 借助奇环，我们可以通过交替的 +k, -k 操作，实现“单点权值加减一个偶数，且不影响图上其他任何点”。
 *    - 这意味着我们可以把所有节点的差值互相转移、抵消，直到只剩 0 或 1。
 *    - 宏观限制：每次边操作都会让全图的总差值和 sum(d[1...n]) 改变 2k（偶数）。
 *    - 核心不变量：全图总差值和的【奇偶性】永远不变。
 *    - 判定的充要条件：初始状态下，全图差值总和 sum(d[1...n]) 必须是偶数。
 * 
 * 4. 解题流程 (1-based 索引)：
 *    - 计算差值数组 d[i]，同时累加全图总和 tot (注意开 long long 防止溢出)。
 *    - 从节点 1 开始跑一边 DFS 进行黑白染色 (1 和 2)。
 *    - 遍历中维护：是否遇到同色相邻节点 (即是否存在奇环 ok = 1)，以及颜色1的总和 cnt1、颜色2的总和 cnt2。
 *    - 判断：
 *      if (有奇环 ok == 1) return (tot % 2 == 0);
 *      else return (cnt1 == cnt2);
 */
void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n+1),b(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> d(n+1);
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        d[i] = b[i] - a[i];
        sum += d[i];
    }
    if(sum & 1){
        cout << "NO" << endl;
        return;
    }
    vector<int> vis(n+1);
    bool ok = 0;
    int tot = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    auto dfs = [&](auto& self, int u, int c) -> void {
        vis[u] = c;
        tot += d[u];
        if(c == 1) cnt1 += d[u];
        else cnt2 += d[u];
        for(int v: adj[u]){
            if(vis[v] == 0){
                self(self, v, 3 - c);
            }else if(vis[v] == vis[u]){
                ok = 1;
            }
        }
    };  
    for(int i = 1; i <= n; i++){
        ok = 0;
        tot = 0;
        cnt1 = 0;
        cnt2 = 0;
        if(vis[i] == 0)
        {
            dfs(dfs, i, 1);
            if(ok == 1)
            {
                if(tot & 1){
                    cout << "NO" << endl;
                    return;
                }
            }else{
                if(cnt1 != cnt2){
                    cout << "NO" << endl;
                    return;
                }
            }            
        }
    }

    cout << "YES" << endl;
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
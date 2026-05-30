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
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
/*
 * 题目：P8907 [USACO22DEC] Making Friends P
 * * 【核心思想】 延时连边 + 启发式合并 + 容斥统计
 * * 1. 延时连边 (找接盘侠)：
 * - 题意要求：牛 i 离开时，其所有仍在农场的朋友互相连边。若直接暴力两两连边，最坏复杂度会退化。
 * - 优化转化：牛 i 离开时，只需找到其朋友中【编号最小】的牛 u（即这群人里下一个将要离开的）。
 * - 将 i 剩下的所有朋友强行塞进 u 的朋友集合中。因为 u 离开时会触发相同的规则，
 * 这种“把任务交给下一个离开的人”的延时策略，保证了该连的边绝不会漏，且减少了冗余操作。
 * * 2. 启发式合并 (小集合并入大集合)：
 * - 图的维护：使用 set<int> adj[N] 维护每头牛“编号大于自己”的朋友集合。
 * - 性能优化：当把牛 i 的集合合并给牛 u 时，比较两者大小。若 i 的集合更大，
 * 直接使用 swap(adj[i], adj[u]) 交换底层指针（O(1) 复杂度）。
 * - 这样保证了每次暴力 insert 的元素始终来自较小的集合，根据启发式合并定理，
 * 总时间复杂度被严格压缩至 O(M log^2 N)。
 * - 避坑：合并前必须用变量 (int u = *it) 提前存下 u 的值，避免 erase 后迭代器失效导致 RE/WA。
 * * 3. 容斥统计 (巧妙计算新边数)：
 * - 最终公式：新增边数 = 最终形成的总边数 - 初始边数 M。
 * - 初始化 ans = -M。
 * - 在牛 i 离开并准备交接前，adj[i].size() 正好就是最终图中与 i 相连且编号比 i 大的边数。
 * - 直接执行 ans += adj[i].size()。全部遍历完后，ans 自然就是纯新增的边数，
 * 完美避开了在 insert 时去判断是否为新朋友的繁琐逻辑。
 */
void solve(){
    int n,m; cin >> n >> m;
    vector<set<int>> adj(n+1);
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        if(u > v) swap(u,v);
        adj[u].insert(v);
    }
    int ans = -m;
    for(int i = 1; i <= n; i++){
        if(adj[i].empty()) continue;
        auto it = adj[i].begin();
        int u = *it; 
        ans += adj[i].size();
        adj[i].erase(it);
        if(adj[i].size() > adj[u].size()){
            swap(adj[i], adj[u]); 
        }
        for(int v : adj[i])  adj[u].insert(v);
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}
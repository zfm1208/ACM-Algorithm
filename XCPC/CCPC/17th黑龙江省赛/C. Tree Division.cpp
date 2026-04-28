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
    题目要求把树分成两个集合 A 和 B
        集合A: 从根向下走，值必须严格递增
        集合B: 从根向下走，值必须严格递减
    节点 u 的合法性，只取决于离它最近的同集合祖先

    * 分析:
    假设你现在沿着树往下走，走到了节点 u
    题目要求 A 集合递增，B 集合递减
    为了决定下一个节点 v 能不能放进 A 或者 B, 你必须随时在口袋里揣着两个数字:

    1. 上一个被分到 A 集合的节点的值（假设叫 last_A）
    2. 上一个被分到 B 集合的节点的值（假设叫 last_B）

    遇到新节点 V 时：
    1. 如果想把 V 扔进 A，必须满足 a[v] > last_A
    2. 如果想把 V 扔进 B，必须满足 a[v] < last_B

    卡住的原因： 在树上做普通的 DP 时，如果我们要在每个节点都记录(last_A, last_B) 这一对数字
    状态就太多了，没法高效dp

    * 转换视角
    当程序运行到节点 u 时，
    不管上面的祖先是怎么分的，u 最终只有两种归宿要么进 A，要么进 B
    1. 假设 u 决定进 A
        口袋里的 last_A 就变成了 u 自己的值 a[u]
        此时，last_A 是已知且确定的。
        唯一未知的，就是从上面传下来的 last_B 到底是多少
    2. 假设 u 决定进 B
        同理，对于它的后代来说，口袋里的 last_B 变成了 a[u]
        此时唯一未知的，就是从上面传下来的 last_A 到底是多少

    ! 因为当前节点一定会覆盖掉 A 或 B 其中的一个记录
    ! 所以我们只需要用 DP 去“求”另一个未知的记录即可！

    * 带入具体场景（自下而上的“提要求”）
    既然我们在 U 点只知道自己的值，不知道另一个集合祖先的值
    那我们就反过来想：让子节点来向我提要求！

    假设当前节点是父亲 u (a[u] = 10)
    它的儿子v (a[v] = 5)

    现在父亲 u 假设自己进入了 A 集合
    因为父亲进了 A，所以儿子 v 的 last_A 变成了 10

    对于孩子v:
    1. v 去 A
        规则是递增，但儿子的值 5 小于父亲的值 10，去不了
    2. v 去 B
        进 B 的规则是：必须小于上面的 last_B
        但父亲 u 进了 A，给不了他 last_B,
        所以儿子 v 需要保证 他们传下来的 last_B 必须严格大于 5否则进不去B了
    
    对于u (a[u] = 10):
    如果u 进 A ,为了保证我下面的儿子们都能活下去
    我需要上面的祖先传给我的 last_B 最少不能低于 5

    dp[u][0]：当前 u 决定进 A。
    为了保住下面的小弟，它需要向爷爷辈索要的 B 的地板（下限）
    这个下限越低越好（越容易满足）

    dp[u][1]：当前 u 决定进 B。
    为了保住下面的小弟，它需要向爷爷辈索要的 A 的天花板（上限）
    这个上限越高越好（越容易满足）

*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dp(n+1,vector<int>(2,0));

    auto dfs =  [&] (auto& self, int u, int p) -> void {
        dp[u][0] = -inf; // 如果叶子节点u进入A, 对B祖先的要求，初始-inf
        dp[u][1] = inf;  // 如果叶子节点u进入B, 对A祖先的要求，初始inf
        for(int v: adj[u]){
            if(v == p) continue;
            self(self, v, u);

            // 假设 u 在集合 A
            int c1 = (a[v] > a[u]) ? dp[v][0] : inf;
            int c2 = (a[u] < dp[v][1]) ? a[v] : inf;
            dp[u][0] = max(dp[u][0], min(c1,c2));

            int d1 = (a[u] > dp[v][0]) ? a[v] : -inf;
            int d2 = (a[v] < a[u]) ? dp[v][1] : -inf;
            
            dp[u][1] = min(dp[u][1], max(d1, d2));            
        }
    };

    dfs(dfs, 1, 0);

    if(dp[1][0] != inf || dp[1][1] != -inf){
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
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
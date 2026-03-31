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
    【树上贪心 / 树上连通块划分 经典模型】
    * 核心思想：自底向上（后序遍历），局部最优解层层递交。
    破题视角：与其考虑“在哪切”，不如考虑“在节点内部怎么尽可能多地保留边（合并）”。

    * DFS 函数设计与基层主管思维：
    
    - 返回值定义：dfs(u, fa) 返回以节点 u 为顶点的、尚未超载的连通块大小（等待被上级收编）。
    
    * 算法 4 步走：
    1. 向下委派：先递归所有子节点 v，收集它们上报的残余连通块大小，存入数组 ch。
    2. 就地排队（贪心）：为了尽可能少砍边（多收编），优先挑选“较小”的连通块合并。
    将 ch 数组从小到大排序。
    3. 尝试收编与斩断：
    - 初始化当前大小 cur = 1（节点 u 本身）。
    - 遍历排序后的 ch，若 cur + x <= m，完美接纳，cur += x。
    - 若装不下（超载），必须“斩断”这条边，记录切割次数 ans++。
    4. 向上呈递：返回合并后的 cur，交给上级父节点去统筹。
    
    * 避坑注意：
    1. 树的边数是 n-1，输入循环记得是 i < n。
    2. ans 记录的是切割次数（切了几刀），最终连通块数量 = 切割次数 + 1。
 */
void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans = 0;
    auto dfs = [&](auto &self, int u, int fa) -> int {
        vector<int> ch;
        for(int v: adj[u]){
            if(v == fa) continue;
            int siz = self(self,v,u);
            ch.pb(siz);
        }
        sort(ch.begin(),ch.end());
        int cur = 1;
        for(int x : ch){
            if(cur + x <= m){
                cur += x;
            }else ans++;
        }
        return cur;
    };
    dfs(dfs,1,0);
    cout << ans + 1 << endl;
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
#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
// #define endl '\n'  交互题一定要关！！！！！
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
    题目大意：
        DAG 图，按字典序给出路径。
        在 N+M 次询问内还原所有边 (N <= 30)。
    核心思路 (DFS + 动态规划/记忆化):
        1. 询问限制 N+M 提示我们必须 "一次询问确定一条边或一个状态"。
        2. 核心性质：
           - 设 Size[u] 为以 u 为起点的路径总数。
           - Size[u] = 1 + sum(Size[v])，其中 v 是 u 的所有邻居。
           - 这个结构具有递归性。
        3. 算法流程：
           - 我们按字典序 1..N 处理每个起点。
           - 定义 dfs(u, depth)：计算 Size[u] 并找出 u 的所有出边。
           - 当我们在 u 的路径集合中发现边 u->v 时：
             a. 如果 Size[v] 已知 (siz[v])：直接跳过 Size[v] 个询问 (剪枝)。
             b. 如果 Size[v] 未知：递归调用 dfs(v, depth+1)。
                注意：此时我们处于 u->v... 的路径上下文中，这刚好等价于 v... 的路径结构。
           - 通过这种方式，每个节点只会被完整遍历一次，每条边只会被“发现”一次。
    
    复杂度：O(N + M) 次询问。
*/
void solve(){
    int n; cin >> n;
    vector<pii> ans;
    auto ask = [&] (int k) -> vector<int> {
        cout << "? " << k << endl;
        int len; cin >> len;
        if(len == -1) exit(0); 
        if(len == 0) return {};
        vector<int> path(len);
        for(int &x: path) cin >> x;
        return path;
    };
    vector<int> siz(35,-1); // siz[u]: 存储以u开头的路径总数
    int now = 1;
    // 递归 计算siz[u] 并 找出u的所有出边
    // depth : 当前节点u 在 ask() 返回的路径数组的下标 
    auto dfs = [&](auto& self, int u, int depth) -> int {
        int sz = 1;
        now++;
        while(1){
            vector<int> path = ask(now);
            if(path.size() == 0 || path.size() <= depth + 1 || path[depth] != u){
                break;
            }
            // u 的一条出边： u -> v
            int v = path[depth + 1];
            ans.pb({u,v});
            if(siz[v] != -1){
                sz += siz[v];
                now += siz[v];
            }else {
                sz += self(self, v, depth+1);
            }
        }
        return siz[u] = sz;
    };
    for(int u = 1; u <= n; u++){
        if(siz[u] != -1){
            now += siz[u];
        }else{
            dfs(dfs,u,0);
        }
    }
    cout << "! " << ans.size() << endl;
    for(auto[u,v]: ans){
        cout << u << " " << v << endl;
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
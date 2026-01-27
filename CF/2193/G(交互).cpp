#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
// #define endl '\n'  
// 交互题目移动要取消 #define endl '\n'  ！！！！！！！！
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
    【核心思路：BFS 层序消消乐】
    
    1. 关键约束：询问次数限制为 n/2 + 1
       这意味着我们每一次查询 "? u v"，必须达到以下两个效果之一：
       (A) 排除掉 2 个点（u 和 v 都不可能是答案）。
       (B) 直接找到答案。

    2. 为什么放弃拓扑排序/剥叶子？
       剥叶子（拓扑排序）在星形图等特殊结构下，难以凑齐“一对”不经过中心点的路径，导致退化成单点查询，查询次数爆炸。

    3. 新策略：BFS 层序遍历（从根向下，成对检查）
       我们维护一个队列，按层序遍历树。每次从队头取出两个节点 u, v 进行询问。

       <情况 1>: query(u, v) == 0
       说明隐藏路径既不经过 u，也不经过 v。
       -> 结论：u 和 v 都可以排除（淘汰）。
       -> 操作：将 u 和 v 的子节点加入队列（下一层待查），u, v 丢弃。
       -> 收益：消耗 1 次询问，排除 2 个点。完美符合限制。

       <情况 2>: query(u, v) == 1
       说明隐藏路径与 u-v 的路径有交点。
       -> 核心逻辑：因为我们是 BFS 从上往下查的，u 和 v 的祖先们已经在之前的轮次中被排除（查询结果为0）。
          如果路径相交，交点不可能在祖先上（否则祖先那轮就该返回 1 了）。
          所以，交点必然是路径目前的“最低端点”，也就是 u 或者 v 本身。
       -> 操作：直接检查 u ("? u u")。是 1 则输出 u，否则输出 v。

    4. 总结
       这其实不是在“找路径”，而是在“批量体检”。
       每次拉两个人出来查，没病就淘汰换下一批（孩子），有病肯定就在这两人身上。
*/

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);

    }
    auto query = [&] (int u, int v) -> int {
        cout << "? " << u << " " << v << endl;
        int res; cin >> res;
        return res;
    };  
    vector<int> vis(n+1);
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        vis[u] = 1;
        if(q.empty()){
            for(auto v: adj[u]){
                if(!vis[v]) q.push(v);
            }
            if(q.empty()) {
                cout << "! " << u << endl;
                return;
            }
            int v = q.front(); q.pop();
            vis[v] = 1;

            int res = query(u,v);
            if(res == 1){
                if(query(u,u)) {
                    cout << "! " << u << endl;
                    return;
                }else{
                    cout << "! " << v << endl;
                    return;   
                }
            }else{
                for(auto nv: adj[v]){
                    if(!vis[nv]) q.push(nv);
                }
            }
        }else{
            int v = q.front(); q.pop();
            vis[v] = 1;

            int res = query(u,v);
            if(res == 1){
                if(query(u,u)) {
                    cout << "! " << u << endl;
                    return;
                }else{
                    cout << "! " << v << endl;
                    return;   
                }
            }else{
                for(auto nu: adj[u]){
                    if(!vis[nu]) q.push(nu);
                }
                for(auto nv: adj[v]){
                    if(!vis[nv]) q.push(nv);
                }
            }
        }
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
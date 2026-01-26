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
    1.注意到询问次数：n/2 + 1
    所以每次询问时如果得到0的回答，我们要排除至少2个点才行
    如果得到1的回答，我们直接二分就行了

    2.找树上面的路径-什么路径好找？-怎样拆一个树最快？
    -拓扑排序-选树的叶子（如果询问两个叶子，回答是0，那么这两个路径上的所有点都没用了）

    3.一旦某次询问回答1，那么说明u,v之间的路径有合法的点，直接二分查找即可

    <1>: 删不可能的点（不断缩小问题的规模）
        1.把度数为1的叶子放进集合
        2.每次从集合中选取两个叶子u,v（最好在一个联通分量中）
        3.删节点，会有新的度数为1的叶子，加入集合，直到询问得到1

    <2>: 二分查找

*/

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> du(n+1),vis(n+1);
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        du[u]++;
        du[v]++;
    }
    vector<int> yz;
    for(int i = 1; i <= n; i++){
        if(du[i] == 1){
            yz.pb(i);
        }
    }
    vector<int> path; // 寻找同一个联通分量里面的其他叶子
    auto dfs = [&] (auto& self, int u, int fa, int st) -> int {
        path.pb(u);
        if(u != st && du[u] == 1) return u;
        for(int v: adj[u]){
            if(v == fa || vis[v]) continue;
            int ans = self(self,v,u,st);
            if(ans != -1) return ans;
        }
        path.pop_back();
        return -1;
    };
    auto query = [&] (int u, int v) -> int {
        cout << "? " << u << " " << v << endl;
        int res; cin >> res;
        return res;
    };
    int i = 0;
    while(i < yz.size()){
        int u = yz[i];
        i++;
        if(vis[u]) continue;
        path.clear();
        int v = dfs(dfs, u, -1, u);
        if(v == -1) {
            if(query(u, u) == 1){
                cout << "! " << u << endl;
                return;
            }else{
                vis[u] = 1;
                continue;
            }
        }
        int res = query(u, v);
        if(res == 1){
            int l = 0, r = path.size() - 1;
            int ans = 0;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(query(path[l], path[mid])){
                    ans = mid;
                    r = mid - 1;
                } else{
                    l = mid + 1;
                }
            }
            cout << "! " << path[ans] << endl;
            return;
        } else{
            for(auto u : path){
                vis[u] = 1; 
                for(auto v : adj[u]){
                    if(!vis[v]){
                        du[v]--;
                        if(du[v] == 1) yz.pb(v);
                    }
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
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
    一个有根树，每个叶子都有樱桃，预收集所有樱桃
        1操作次数必须是3的倍数
        2每次摇晃v可以将一个节点v的所有叶子的樱桃都收集
        3每个叶子最多只能被收集一次(不能2次摇晃)
    对于树上任意一个节点u，有两种策略去收集u及其孩子
    1.直接摇晃u，操作次数1
    2.依赖u的每一个子节点v，操作次数为所有子节点操作次数之和

    考虑dp，我们需要知道子树信息此案决定当前节点怎么做 - 最优子结构
    dp[i][j] = 0/1:
    以i为根的子树，是否有一种方案能收集完子树内樱桃且操作总次数为j (j = 0/1/2)

    最后考虑dp[1][0]是否为 true
*/

void solve(){
    int n; cin >> n;
    vector<vector<int>> e(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    vector<vector<int>> dp(n+1,vector<int>(3));
    auto dfs = [&] (auto & self, int u, int fa) -> void {
        bool ok = 1;
        vector<int> cur{1,0,0};
        for(auto v: e[u]){
            if(v == fa) continue;
            ok = 0;
            self(self,v,u);
            vector<int> nxt{0,0,0};
            for(int i = 0; i < 3; i++){
                if(cur[i]){
                    for(int j = 0; j < 3; j++){
                        if(dp[v][j]){
                            nxt[(i+j)%3] = 1;
                        }
                    }
                }
            }
            cur = nxt;
        }
        rep(i,0,2) dp[u][i] = 0;
        if(ok){ // 叶子节点
            dp[u][1] = 1;
        }else{
            dp[u] = cur;
            dp[u][1] = 1;
        }
    };
    dfs(dfs,1,0);
    cout << (dp[1][0] ? "YES" : "NO") << endl;
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
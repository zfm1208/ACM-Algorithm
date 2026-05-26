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
struct BIT {
    int n;
    vector<int> tr;
    BIT(int _n) : n(_n), tr(_n + 1, 0) {}
    int lowbit(int x) { return x & -x; }
    
    void add(int x, int c) {
        if (x <= 0) return; 
        for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }
    
    int query(int x) {
        int res = 0;
        for (int i = x; i > 0; i -= lowbit(i)) res += tr[i];
        return res;
    }
    
    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};
/*
    <1>.  我们不能遇到一个查询就跑一遍子树
    <2>.  不能每次都从头查有几个颜色>=k
    
    对于<1>:  树上启发式合并 (DSU on Tree)
        既然每次重新遍历太慢，我们能不能全树只遍历一次，算完所有答案?
        假设我们在算父节点的答案，而它下面有两个子节点（两个子树）。
        我们可以直接把子节点算好的数据拿过来用，而不是重新去数一遍。

        但这里有个大问题：大家共用一个记事本，数据会串号！
        算完左子树，如果不把记事本擦干净就去算右子树，右子树就会把左子树的颜色也当成自己的
        如果每次算完都擦干净，那父节点又要重新算，毫无优化。

        => 
        (1) :找出树里节点数最多的那个分支，叫它“重儿子”。其他的叫“轻儿子”
        (2) :我们先去算所有的轻儿子，算完轻儿子的答案后，老老实实把记事本擦干净
        (3) :最后去算重儿子。重儿子有特权，算完之后不用擦记事本，直接保留数据
        (4) :此时记事本上留着重儿子的庞大数据,父节点只需要把刚才擦掉的轻儿子们再稍微补算一下，加上自己，就能得到完整的答案。

        这样时间复杂度优化到 O(nlog n)

    对于<2>: 树状数组 (BIT)
        我们可以用树状数组 (Binary Indexed Tree) 来维护“频率的频率”
        BIT bit(n+5)
        树状数组的下标 x，代表的是出现次数
        树状数组里的值 tr[x]，代表的是有几种颜色出现了这么多次
        当我们在树上多发现一个红点时（比如红色从 2 个变成 3 个），代码是这样运作的:
        原本红色的次数是 2，所以我们在树状数组下标 2 的位置减去 1  bit.add(2, -1)
        红色的次数变成了 3，所以我们在树状数组下标 3 的位置加上 1  bit.add(3, 1)

        当我们需要查“出现次数 >= k 的颜色有几种”时，只需要用树状数组求一个区间和：
        bit.query(k, n)


        这样时间复杂度就是O(log n)
*/

void solve(){
    int n,m; cin >> n >> m;
    vii col(n+1);
    rep(i,1,n) cin >> col[i];
    
    vector<vii> adj(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<pii>> qs(n+1);
    for(int i = 1; i <= m; i++){
        int u,k; cin >> u >> k;
        qs[u].push_back({k,i});
    }
    
    vii ans(m+1); // ans[i]: 第i次询问答案
    vii siz(n+1); // siz[u]: 以u为根的子树大小
    vii big(n+1); // big[u]: 以u为根的子树的重儿子编号
    
    // 找子树大小, 以及重儿子
    auto dfs = [&](auto& self, int u, int fa) -> void {
        siz[u] = 1;
        big[u] = 0;
        for(int v: adj[u]){
            if(v == fa) continue;
            self(self, v, u);
            siz[u] += siz[v];
            if(big[u] == 0 || siz[v] > siz[big[u]]){
                big[u] = v;
            }
        }
    };
    dfs(dfs, 1, 0);
    
    vii cnt(100005); 
    BIT bit(n + 5); 
    
    auto update = [&](auto& self, int u, int fa, int skip, int op) -> void {
        int c = col[u];
        if(op == 1){ 
            if(cnt[c] > 0) bit.add(cnt[c], -1);
            cnt[c]++;
            bit.add(cnt[c], 1);
        }else{ 
            bit.add(cnt[c], -1);
            cnt[c]--;
            if(cnt[c] > 0) bit.add(cnt[c], 1);
        }
        
        for(int v: adj[u]){
            if(v == fa || v == skip) continue;
            self(self, v, u, skip, op);
        }
    };

    auto dfs1 = [&](auto& self, int u, int fa, int ok) -> void {
        for(int v: adj[u]){
            if(v == fa || v == big[u]) continue;
            self(self, v, u, 0);
        }

        if(big[u] != 0) self(self, big[u], u, 1);

        for(int v: adj[u]){
            if(v == fa || v == big[u]) continue;
            update(update, v, u, 0, 1);
        }

        int c = col[u];
        if(cnt[c] > 0) bit.add(cnt[c], -1);
        cnt[c]++;
        bit.add(cnt[c], 1);

        for(auto [k, id]: qs[u]){
            if (k <= n) {
                ans[id] = bit.query(k, n);
            } else {
                ans[id] = 0; 
            }
        }
        // 算完这棵子树后 数据要不要留ok = 0不留,ok = 1留
        if(ok == 0) update(update, u, fa, 0, -1);
    };

    dfs1(dfs1, 1, 0, 0);
    rep(i,1,m) cout << ans[i] << endl;
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
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
// https://qoj.ac/contest/1834/problem/9713

/*
    * 前提知识, 假设我们现在在节点u,它的距离之和是c[w],现在我们想向它的邻居v走一步,看看距离和c[v]会不会变小

    u -> v
    往v方向的那一piano4子树(大小siz[v]), 所有的点都离我们进了1步
    除了v方向以外的所有点(大小n - siz[v]), 都离我们远了1步
    * 我们距离的变化量为:
    (n - siz[v]) - siz[v] = n - 2 * siz[v]
    如果siz[v] > n/2, 那么2 * siz[v] > n, 此时变化量 < 0, 说明往v走距离和会变小,u肯定不是重心
    只有当u的所有邻居所联通的大小都 <= n/2时,无论往哪个方向走，距离之和都不会变化或不变，此时u就是重心

    * 为什么要找“最深”的子节点重心?(为什么要顺着重儿子往上爬?)
    重心的偏移
    子树u的重心,一定存在于从u到ans[hv[u]]的这条路上
    由于重心是往上移动的，我们只要从“最深”的那个可能位置（也就是重儿子的重心 pos）开始，
    一步一步往上爬（pos = fa[pos]）去试探就可以了

    * 什么时候停下？
    结合刚才重心的判定依据：以 pos 为界，切断它和父节点的连线
    pos 下面的节点数是 siz[pos]
    pos 上面的节点数（包含 u 和轻儿子）是 siz[u] - siz[pos]
    只要pos上面的节点数还 > siz[u]/2，说明还要往上找
    一旦 siz[u] - siz[pos] <= siz[u] / 2, 说明pos就是重心

    * 怎么判断2个重心?
    我们还是用刚才的“移动法”来解释：
    如果 u 是重心，且它有一个邻居 v。当我们从 u 走到 v 时，
    距离和的变化量是 n - 2 * siz[v]
    
    如果siz[v] = n/2, 说明u和v一样是重心
*/
/*
    * 拆解题意
    题中给了一个核心公式：c[w] <= min(c[u]),其中c[w] 是到树上其他点的距离之和
    在树论中,距离所有之和最小的点,就是这棵树的 "重心".
    所以题目让求的就是 ：
    求这个树上,以每个节点i为根的子树的所有重心(一棵树最多有2个重心,如果有2个，必定相邻)

    * 思路
    如果对每一个子树都跑一遍找重心的DFS,会TLE
    树的重心性质:
    1. 一颗树的重心, 一定在它重儿子的重心,到根节点的这条路径上
    2. 已知子树总大小为siz[u], 从下往上找, 第一个满足其上方的节点总数<=siz[u]/2的节点, 就是最深的那个重心.

    因此,我们可以用一次O(n)的自底向上DFS来实现
    1.像往常一样求每个节点的siz,和hv(重儿子)
    2.在回溯时,对于节点u， 我们不需要从头找它的重心, 我们直接继承它重儿子的最深重心pos
    3.只要pos上面属于u子树的节点数量(即siz[u] - siz[pos] 还严格大于siz[u] / 2),就让pos = fa[pos]
    4.停下来的地方就是u的其中一个重心
    5.怎么判断有没有第二个重心, 如果siz[pos] * 2 == siz[u], 那么pos的父节点也是重心
*/
void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    vector<vector<int>> res(n + 1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> siz(n+1),fa(n+1),hv(n+1);
    vector<int> ans(n+1);// 记录以i为根的最深重心
    auto dfs = [&](auto& self, int u, int p) -> void {
        siz[u] = 1;
        fa[u] = p;
        hv[u] = 0;
        int mx = 0;
        for(int v:g[u]){
            if(v == p) continue;
            self(self, v, u);
            siz[u] += siz[v];
            if(siz[v] > mx){
                mx = siz[v];
                hv[u] = v;
            }
        }
        if(hv[u] == 0) // 叶子节点
        {
            ans[u] = u;
            res[u].pb(u);
        }else{
            int pos = ans[hv[u]];
            while(siz[u] - siz[pos] > siz[u] / 2){
                pos = fa[pos];
            }
            ans[u] = pos;
            res[u].pb(pos);
            if(siz[pos] * 2 == siz[u]) {
                res[u].pb(fa[pos]);
            }
            sort(res[u].begin(),res[u].end());
        }
    };

    dfs(dfs, 1, 0);
    for(int i = 1; i <= n; i++){
        for(int x: res[i]) cout << x << " ";
        cout << endl;
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
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
    题目:
        你需要在一个有n座建筑和m条道路的城市中完成一次旅行，访问所有的建筑。城市中有k个核酸检测点。
        核酸结果有效期为t分钟。每次进入任何建筑必须保证距离上次检测不超过t。
        移动速度为v。求最小整数速度v
    思路:
    1.  数据规模与算法选择: 
        N <= 300，数据范围很小。
        为了判断任意两点间是否能在有限时间内到达，我们需要全源最短路，
        因此使用 Floyd-Warshall 算法 (O(N^3)) 预处理任意两点间的最短距离 d[i][j]
    2.  二分答案:
        答案具有单调性，二分速度 v。
        将时间限制转化为路程限制：最大单次有效行程 L = v * t。
    3.  连通性判定 (Check逻辑):
        利用 并查集 (DSU) 将“安全互通”的区域合并
        我们遍历所有点对 (i, j)：
        - 情况 A (检测点互通): 如果 i 和 j 都是检测点，且 d[i][j] <= L，
            说明可以在有效期内从一个检测站跑到另一个，它们属于同一个安全网络，unite(i, j)。
        - 情况 B (建筑挂载): 如果 i 是普通建筑，j 是检测点。
            要想访问 i，必须能从 j 出发到达 i，并且还能再回到 j (或去往其他检测点)
            最坏情况是原路返回，所以限制是 往返距离。
            即如果 2 * d[i][j] <= L，说明 i 可以安全地依附于 j，unite(i, j)。
    4.  合法性:
        如果最终 DSU 的连通分量数量为 1 (count == 1)，说明所有检测点互通，
        且所有普通建筑都能被某个检测点覆盖，返回 true

    实现:
    1.  预处理: 
        初始化邻接矩阵 d[i][j]，跑一遍 Floyd 算法，求出全图任意两点最短路。
    2.  二分: 
        二分速度 v，范围 [1, 2e14]。
    3.  Check(v):
        - 计算 L = v * t (注意用 __int128 防止溢出)。
        - 初始化 DSU。
        - 双重循环遍历所有点对 (i, j)。
        - 若 d[i][j] 为 INF 跳过。
        - 若 i, j 均为检测点且 d[i][j] <= L -> 合并。
        - 若 i 为普通点, j 为检测点且 2 * d[i][j] <= L -> 合并。
        - 检查 dsu.count 是否为 1。
*/

struct DSU {
    vector<int> fa;
    int count = 0; // 联通块的数量
    DSU(int n){
        fa.resize(n+1);
        for(int i = 1; i <= n; i++){
            fa[i] = i;
        }
        count = n;
    }
    int find(int x) {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    void unite(int x, int y){
        int rx = find(x);
        int ry = find(y);
        if(rx != ry){
            fa[rx] = ry;
            count--;
        }
    }
};

void solve(){
    int n,m,k; cin >> n >> m >> k;
    int t; cin >> t;
    vector<vector<int>> d(n+1,vector<int> (n+1));
    vector<int> vis(n+1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = inf;
        }
    }
    for(int i = 1; i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }
    for(int i = 1; i <= k; i++){
        int x; cin >> x;
        vis[x] = 1;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }    
    auto check = [&] (int v) -> bool {
        __int128_t L = (__int128_t)v * t;
        DSU dsu(n);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(d[i][j] >= inf) continue;
                if(vis[i] && vis[j]) {
                    if((__int128_t)d[i][j] <= L) dsu.unite(i, j);
                }
                else if(!vis[i] && vis[j]) {
                    if((__int128_t)2 * d[i][j] <= L) dsu.unite(i, j);
                }
            }
        }
        return dsu.count == 1;
    };
    int l = 1, r = 2e14;
    int ans = -1;    
    if(check(r) == false){
        cout << -1 << endl;
        return;
    }
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
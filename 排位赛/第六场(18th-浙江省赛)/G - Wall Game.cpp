#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define rep(i,l,r) for(int i = l; i <= r; i++)
const int N = 2e5+10, mod = 1e9+7, base = 131;
#define pb push_back
/*
 * ==================================================================================
 * 题目名称: G. Wall Game (第18届浙江省大学生程序设计竞赛)
 *
 * 【题目描述】
 * 在一个由正六边形（蜂巢状）平铺的无限平面上，进行 n 次操作。
 * 操作分为两类：
 * 1. 攻击 (op=1, x, y): 征服位于坐标 (x, y) 的六边形格子。
 * 2. 查询 (op=2, x, y): 询问如果从已征服的格子 (x, y) 出发，在不越过“墙”的情况下，
 * 能触摸到的墙壁总数是多少。
 *
 * "墙壁"定义为：已征服格子与未征服格子之间的公共边。
 * "领地"定义为：所有相互连通的已征服格子的集合。
 * 查询实质上是问：(x, y) 所在的连通块的周长（即该连通块与外部未征服区域的接触边数）。
 *
 * 【解题思路：并查集维护连通块周长】
 *
 * 1. 问题建模：
 * - 每个六边形格子有 6 条边。
 * - 当一个新格子被征服时，它初始贡献 6 条边作为墙壁。
 * - 如果它与某个相邻的已征服格子接壤，它们之间的公共边就不再是墙壁了。
 * 这会导致两个格子的墙壁数各减少 1（总共减少 2）。
 * - 因此，连通块的总墙壁数 = Σ(块内每个格子的初始边数 6) - 2 * (块内相邻边的数量)。
 * 或者更动态地维护：
 * Merge(u, v) 时，New_Perimeter = Perimeter(u) + Perimeter(v) - 2。
 *
 * 2. 坐标系统与邻居：
 * 题目给出的六边形坐标系比较特殊，通过观察图示或尝试推导，可以确定邻居偏移量。
 * 在 (x, y) 处的六边形，其 6 个相邻格子的坐标偏移量 (dx, dy) 为：
 * (1, 0), (0, 1), (0, -1), (-1, 0), (1, -1), (-1, 1)
 * 注意：这个坐标系不同于常见的二维网格，dy 的变化会影响 dx 的相对位置。
 * (代码中定义的 dx/dy 数组准确地反映了这一邻接关系)
 *
 * 3. 并查集 (DSU) 的应用：
 * - 使用并查集来维护已征服格子的连通性。
 * - DSU 结构体中维护两个数组：
 * a. fa[i]: 节点 i 的父节点，用于查找根节点。
 * b. zc[i]: 以 i 为根的连通块的当前总周长（墙壁数）。
 * - 映射：由于坐标 (x, y) 范围很大，不能直接开二维数组。
 * 使用 std::map<pair<int,int>, int> 将坐标映射为从 1 开始的整数 ID。
 *
 * 4. 操作流程：
 * - 对于操作 1 (征服 x, y)：
 * a. 分配新 ID，初始化该格子的周长 zc[ID] = 6。
 * b. 遍历 6 个方向的邻居。如果邻居 (nx, ny) 已经被征服：
 * - 找到邻居的根节点 root_neighbor 和当前格子的根节点 root_curr。
 * - 如果它们不在同一个集合（root_neighbor != root_curr）：
 * 说明是两个独立连通块合并。合并时，总周长 = zc[root_curr] + zc[root_neighbor] - 2。
 * (代码实现上先各自减1再合并加和，效果一样：减去的2代表这两个格子中间那条公共边消失了)
 * - 如果它们已经在同一个集合（root_neighbor == root_curr）：
 * 说明是在同一个连通块内部填补了一个空缺，依然减少 2 条公共边（墙壁）。
 * zc[root_curr] -= 2。
 * - 对于操作 2 (查询 x, y)：
 * a. 找到 (x, y) 对应的 ID。
 * b. 查找其 DSU 根节点。
 * c. 输出根节点维护的 zc 值。
 *
 * 5. 复杂度分析：
 * - 时间复杂度：O(N * logN * α(N))。
 * map 的操作是 logN，并查集操作接近常数 α(N)，每个操作遍历 6 个邻居是常数。
 * - 空间复杂度：O(N)，用于存储 DSU 和 map。
 *
 * ==================================================================================
 */
const int dx[] = {1,0,0,-1,1,-1};
const int dy[] = {0,1,-1,0,-1,1};
struct DSU{
    vector<int> fa,zc;
    DSU(int n){
        fa.resize(n+1);
        zc.resize(n+1);
        for(int i = 1; i <= n; i++){
            fa[i] = i;
        }
    }
    int find(int x){
        if(fa[x] != x){
            return fa[x] = find(fa[x]);
        }
        return x;
    }
    void link(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx != fy){
            fa[fx] = fy;
            zc[fy] += zc[fx];
        }
    }
};

void solve(){
    int n; cin >> n;
    DSU dsu(n);
    map<pii,int> mp;
    int num = 1;
    for(int k = 1; k <= n; k++){
        int op,x,y; cin >> op >> x >> y;
        if(op == 1){
            mp[{x,y}] = num;
            dsu.zc[mp[{x,y}]] = 6;
            for(int i = 0; i < 6; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(mp[{nx,ny}]){
                    dsu.zc[dsu.find(mp[{nx,ny}])] -= 1;
                    dsu.zc[mp[{x,y}]] -= 1;
                    dsu.link(mp[{nx,ny}],mp[{x,y}]);
                }
            }
            num++;
        }else{
            cout << dsu.zc[dsu.find(mp[{x,y}])] << endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
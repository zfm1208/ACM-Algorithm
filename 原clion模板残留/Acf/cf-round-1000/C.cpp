#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
int u, v;
void solve() {
    int n; cin >> n;
    vector<int> a[n+1];  // 邻接表，存储树的边
    vector<int> du(n+1);  // 存储每个顶点的度数
    // 输入n-1条边，并更新邻接表和度数
    rep(i,1,n-1) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        du[u]++;
        du[v]++;
    }
    priority_queue<pii> q; // 使用优先队列（最大堆）来存储顶点的度数及其编号
    rep(i,1,n) q.push({du[i],i});
    // 获取度数最大的顶点及其度数
    int id = q.top().se;  // 度数最大的顶点的编号
    int mx = q.top().fi;  // 最大的度数
    vector<int> vis(n+1), mv;  // vis用于标记顶点是否被处理，mv存储所有度数最大的顶点
    rep(i,1,n){
        if(du[i] == mx) {
            vis[i]++;  // 标记这些顶点
            mv.push_back(i);  // 将这些顶点加入mv
        }
    }
    int ans = 0;  // 用于存储最终的连通分量数量
    // 遍历所有度数最大的顶点，找到一个合适的顶点进行删除
    for(auto x:mv){
        int cnt = 0;
        for(auto y:a[x]) cnt += vis[y];  // 计算与该顶点相邻的度数最大的顶点的数量
        if(cnt < 2){  // 如果相邻的度数最大的顶点少于2个，则选择该顶点
            id = x;
            break;
        }
    }
    ans += du[id];  // 增加连通分量的数量
    // 删除该顶点及其相连的边，更新相邻顶点的度数
    for(auto i : a[id]) du[i]--;
    du[id] = 0;  // 将该顶点的度数置为0
    mx = 0;  // 重置最大度数
    // 再次找到度数最大的顶点
    rep(i,1,n) {
        if(du[i] > mx){
            mx = du[i];
            id = i;
        }
    }
    ans += du[id];  // 增加连通分量的数量
    // 输出结果，减去1是因为初始的连通分量数量为1（整棵树）
    cout << ans - 1 << endl;
}
// 主函数
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
int head[N],cnt;
// 使用链表存边的信息
// 一个点对应一个链表
struct Edge{
    int next; // 下一个边的编号
    int to; // 这一条边的终点
    int w; // 这一条边的权值
}e[N * 2];//注意，我们是以边的编号来存的图，所以数组的大小要按边开，这里开两倍是因为连的是无向图
void add(int u, int v, int w){
    ++cnt;
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
void dfs(int u, int fa){
    for(int i = head[u]; i != -1; i = e[i].next){
        int to = e[i].to;
        if(to == fa) continue;
        dfs(to,u);
    }
}
void solve() {
    int n,m; cin >> n >> m;
    cnt = 0;
    memset(head,-1,sizeof(head));
    while(m--){
        int u,v,w; cin >> u >> v >> w;
        add(u,v,w);
        add(v,u,w);
    }
    dfs(1,-1);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}

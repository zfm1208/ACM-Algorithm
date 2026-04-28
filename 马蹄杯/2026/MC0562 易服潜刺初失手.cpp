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
/*
    结论： 对于一个连通块
    如果节点数和边的数量奇偶性相同，那么ans += 节点数
    否则 ans += 节点数 - 1
*/
struct DSU {
    vector<int> fa;
    vector<int> siz;
    vector<int> cnt;
    DSU(int n) {
        fa.resize(n+1);
        siz.resize(n+1);
        cnt.resize(n+1);
        for(int i = 1; i <= n; i++){
            siz[i] = 1;
            cnt[i] = 0;
        }
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x){
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    
    void link(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx != fy){
            fa[fx] = fy;
            siz[fy] += siz[fx];
            cnt[fy] += cnt[fx];
            cnt[fy]++;
        }else{
            cnt[fy]++;
        }
    }
};

void solve(){
    int n, m; cin >> n >> m;
    DSU dsu(n);
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        dsu.link(u,v);
    }
    int ans = 0;
    vector<int> vis(n+1);
    for(int i = 1; i <= n; i++){
        int fa = dsu.find(i);
        if(vis[fa] == 0){
            int cnt = dsu.cnt[fa];
            int siz = dsu.siz[fa];
            // cout << i << " " << cnt << " " << siz << endl;
            if(cnt % 2 == siz % 2){
                ans += siz;
            }else{
                ans += siz-1;
            }
            vis[fa] = 1;
        }
    }
    cout << ans << endl;
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
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
int n,m,st,ed;
int a[505];
vector<pii> e[505];
int dis[505];
int vis[505];
int cnt[505]; // 在最短路下 从st到i结点的方案数量
int jiuyuan[505]; // 在最短路下 从st到i结点的救援队数量
int pre[505];
void dijkstra(){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    for(int i = 0; i < n; i++){
        dis[i] = inf;
        cnt[i] = 0;
        vis[i] = 0;
        jiuyuan[i] = 0;
        pre[i] = -1;
    }
    q.push({0,st});
    dis[st] = 0;
    cnt[st] = 1;
    jiuyuan[st] = a[st];
    while(!q.empty()){
        auto [w,u] = q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto [v,d]: e[u]){
            if(dis[v] > dis[u] + d){
                dis[v] = dis[u] + d;
                cnt[v] = cnt[u]; // 直接继承，因为是要最短路情况
                pre[v] = u;
                jiuyuan[v] = jiuyuan[u] + a[v];
                q.push({dis[v],v});
            }else if(dis[v] == dis[u] + d){
                cnt[v] += cnt[u]; // 路径累加
                if(jiuyuan[v] < jiuyuan[u] + a[v]){
                    jiuyuan[v] = jiuyuan[u] + a[v];
                    pre[v] = u;
                }
            }
        }
    }
}
void solve(){
    for(int i = 0; i < n; i++) e[i].clear();
    cin >> n >> m >> st >> ed;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++){
        int u,v,d;
        cin >> u >> v >> d;
        e[u].pb({v,d});
        e[v].pb({u,d});
    }
    dijkstra();
    vector<int> path;
    int now = ed;
    while(now != -1){
        path.pb(now);
        now = pre[now];
    }
    reverse(path.begin(),path.end());
    cout << cnt[ed] << " "<< jiuyuan[ed] << endl;
    int nn = path.size();
    for(int i = 0; i < nn; i++){
        if(i == nn-1)cout << path[i];
        else cout << path[i] << " ";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}
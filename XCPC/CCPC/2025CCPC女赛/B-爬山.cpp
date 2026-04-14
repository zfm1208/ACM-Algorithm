// 律己则安，越是执着，便是越苦;
// 安下心来，看该看的风景，做该做的事。
#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
double pi = acos(-1);
const int N = 1e5, mod = 1e9+7, inf = 1e18 + 5;
struct node{
    int now;
    int pl;
    int time;
};
vector<pii> e[N]; 
void solve() {
    int n,m,H; cin >> n >> m >> H;
    vector<int> h(n+1);
    vector<vector<int>> dis(n+1,vector<int>(H+1,inf));
    // dis[i][j]：到达节点i时疲劳值为j的最短时间
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= m; i++){
        int u,v,t; cin >> u >> v >> t;
        e[u].emplace_back(v,t);
        e[v].emplace_back(u,t);
    }
    // 按照时间从小到大排序
    auto cmp = [&](auto a,auto b) {return a.time > b.time;}; 
    priority_queue<node,vector<node>,decltype(cmp)> q(cmp);    
    dis[1][0] = 0;
    q.push({1,0,0});
    while(!q.empty()){
        auto [u,pl,time] = q.top();
        q.pop();
        if(time > dis[u][pl]) continue;
        for(auto [v,t] : e[u]){
            int op = (h[v] >= h[u] ? pl + h[v] - h[u] : 0);
            if(op > H) continue;
            if(dis[v][op] > dis[u][pl] + t){
                dis[v][op] = dis[u][pl] + t;
                q.push({v,op,dis[v][op]});
            }
        }
    }
    for(int i = 2; i <= n; i++){
        // *min_element() 左开右闭 ：[)
        int ans = *min_element(dis[i].begin(),dis[i].end());
        cout << (ans < 1e18 ? ans : -1) << " ";
    }   
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
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
const int N = 105, mod = 1e9+7, inf = 1e18 + 5;
/*
    一个图如果能把所有点分成两组 (S) 和 (T)，
    并且 所有边都只连接 (S) 与 (T)（组内没有边）那么这个图叫二分图
    等价说法：图可以用两种颜色染色（0/1），使得每条边两端颜色不同

    树一定是二分图
    树没有环，更不可能有奇环；而“图能二分”当且仅当“图里没有奇环”。所以树一定二分图。
*/
vector<int> adj[N];
int color[N];
// 经典的 DFS 染色法 将相连的节点染成 0 和 1 两种颜色。
void dfs(int u, int c){
    color[u] = c;
    for(int v: adj[u]){
        if(color[v] == 0){
            dfs(v, 3 - c); // 相邻节点染相反颜色
        }
    }
}
void solve(){
    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 1);
    vector<int> s,t;
    for(int i = 1; i <= n; i++){
        if(color[i] == 1) s.push_back(i);
        else t.push_back(i);
    }

    if(s.size() > t.size()) swap(s,t);

    vector<int> ans(n+1);
    for(int i = 0; i < s.size(); i++){
        int u = s[i];
        ans[u] = (1LL << 60) - 1;
        ans[u] ^= (1LL << 59);
        ans[u] ^= (1LL << i);
    }

    for(int i = 0; i < t.size(); i++){
        int u = t[i];
        ans[u] = (1LL << 60) - 1;
        ans[u] ^= (1LL << 58);
    }

    for(int j = 0; j < t.size(); j++){
        for(int i = 0; i < s.size(); i++){
            int u = s[i];
            bool ok = 0;
            for(int ner: adj[t[j]]){
                if(ner == u){
                    ok = 1;
                    break;
                }
            }
            if(ok == 0){ //if (s[i] 和 t[j] 之间没有边)
                // s[i] 的 第i位是0, 把t[j] 的第i位也变成0, 这一位or运算就是0
                ans[t[j]] ^= (1LL << i);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " \n"[i==n];
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
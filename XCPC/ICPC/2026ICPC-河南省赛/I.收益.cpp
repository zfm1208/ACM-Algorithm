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
void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<priority_queue<int>> cun(n+1);
    int ans = 0;
    unordered_map<int,int> mp;
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> w(n+1);
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= m; i++){
        int pos; cin >> pos;
        mp[pos]++;
    }
    auto dfs = [&](auto&self, int u, int fa) -> void {
        int big = -1;
        for(int v: adj[u]){
            if(v == fa) continue;
            self(self, v, u);
            if(big == -1 || (cun[v].size() > cun[big].size())){
                big = v;
            }
        }

        if(big != -1) swap(cun[u], cun[big]);

        for(int v: adj[u]){
            if(v == fa || v == big) continue;
            while(!cun[v].empty()){
                cun[u].push(cun[v].top());
                cun[v].pop();
            }
        }

        if(cun[u].empty()){
            cun[u].push(w[u]);
        }else{
            int mx = cun[u].top();
            cun[u].pop();
            mx += w[u];
            cun[u].push(mx);
        }

        while(mp[u] > 0 && !cun[u].empty()){
            ans += cun[u].top();
            cun[u].pop();
            mp[u]--;
        }
    };
    dfs(dfs, 1, 0);
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
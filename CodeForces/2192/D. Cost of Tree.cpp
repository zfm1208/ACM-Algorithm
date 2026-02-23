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

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<vector<int>> adj(n+1);
    for(int i = 1;i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> sum(n+1),deep(n+1);
    vector<int> dmx(n+1),son(n+1);
    vector<int> fcost(n+1);
    auto dfs = [&](auto &self, int u,int fa) -> void {
        sum[u] = a[u];
        dmx[u] = deep[u];
        for(int v: adj[u]){ 
            if(v == fa) continue;
            deep[v] = deep[u] + 1;
            self(self,v,u);
            sum[u] += sum[v];
            fcost[u] += fcost[v] + sum[v];
            if(dmx[v] > dmx[u]){
                dmx[u] = dmx[v];
            }
        }
        for(int v: adj[u]){
            if(v != fa){
                if(dmx[v] == dmx[u]){
                    son[u] = v;
                    break;
                }
            }
        }
    };
    dfs(dfs,1,0);
    vector<int> ans(n+1);
    auto dfs1 = [&] (auto &self, int u) -> void {
        vector<int> chain;
        int curr = u;
        while(curr != 0){
            chain.pb(curr);
            curr = son[curr];
        }
        int k = chain.size();
        int L = chain.back();
        int D_L = dmx[u];     
        vector<int> node_val(k, 0); 
        for(int m = 0; m < k; m++){
            int curr_node = chain[m];
            int val1_max = 0; 
            int ldep_max = -1;
            for(int v : adj[curr_node]){
                if(deep[v] > deep[curr_node] && v != son[curr_node]){
                    
                    val1_max = max(val1_max, sum[v] * (D_L - deep[v] + 1));
                    ldep_max = max(ldep_max, dmx[v]); 

                    self(self, v); 
                }
            }
            
            node_val[m] = val1_max;
            if(m + 1 < k && ldep_max != -1){
                int nxt = chain[m+1];
                int val2 = sum[nxt] * (ldep_max - deep[nxt] + 1);
                node_val[m] = max(node_val[m], val2);
            }
        }
        int smax = 0;
        for(int m = k - 1; m >= 0; m--){
            smax = max(smax, node_val[m]);
            ans[chain[m]] = fcost[chain[m]] + smax;
        }
    };
    dfs1(dfs1, 1);
    for(int i = 1;i <= n; i++){
        cout << ans[i] << " \n"[i==n];
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}
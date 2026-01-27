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
        a[i] &= 1;
    }
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> deep(n+1);
    auto dfs = [&](auto& self, int u, int fa) -> void {
        for(int v: adj[u]){
            if(v == fa) continue;
            deep[v] = deep[u] + 1;
            self(self,v,u);
        }
    };
    dfs(dfs,1,0);
    set<array<int,3>> st; // [权值，-深度，编号]
    vector<int> sum(n+1);
    for(int u = 1; u <= n; u++){
        for(auto v: adj[u]){
            sum[u] += a[v];
        }
        if(a[u] % 2 != sum[u] % 2){
            st.insert({a[u], -deep[u], u});
        }
    }
    
    vector<bool> vis(n+1, 1);
    vector<int> ans;   
    
    while(!st.empty()){
        auto [val, depth, u] = *st.begin(); 
        st.erase(st.begin());        
        ans.pb(u);
        vis[u] = 0; 
        for(int v : adj[u]){
            if(!vis[v]) continue;
            if (sum[v] % 2 != a[v] % 2) {
                st.erase({a[v], -deep[v], v});
            }
            sum[v] -= a[u]; 
            if(sum[v] < 0) sum[v] += 2; 
            if(sum[v] % 2 != a[v] % 2){
                st.insert({a[v], -deep[v], v});
            }
        }
    }

    if(ans.size() < n){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        for(int x : ans) cout << x << " ";
        cout << "\n";
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
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1;i <= n; i++){
        cin >> a[i];
    }
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int sum = 0;
    vector<int> dep(n+1);
    dep[1] = 1;
    auto dfs = [&] (auto& self, int u, int fa,int hi) -> void {
        for(auto v: adj[u]){
            if(v == fa) continue;
            dep[v] = dep[u] + 1;
            self(self,v,u,hi+1);
        }
    };
    dfs(dfs,1,0,1);
    for(int i = 1; i <= n; i++){
        if(dep[i] - 1 <= 2*k){
            sum += a[i];
        }
    }
    cout << sum;
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
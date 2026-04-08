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
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= n; i++){
        int dad; cin >> dad;
        adj[dad].pb(i);
    }
    vector<int> ans;
    int kk = 0;
    int mx = 0; 
    bool ok = 0;
    for(int i = 1; i <= n; i++){
        mx = max(mx, (int)adj[i].size());
        if(adj[i].size() != 0){
            if(kk == 0){
                kk = adj[i].size();
            }else{
                if(kk != adj[i].size()){
                    ok = 1;
                }
            }
        }
    }
    cout << mx << " ";
    if(ok == 1) cout << "no" << endl;
    else cout << "yes" << endl;
    auto dfs = [&] (auto& self, int u, int fa) -> void {
        ans.pb(u);
        for(auto v: adj[u]){
            if(v == fa) continue;
            self(self, v, u);
        }
    };
    dfs(dfs, adj[0][0], 0);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(i < ans.size() - 1) cout << " ";
    }
    cout << endl; 
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}
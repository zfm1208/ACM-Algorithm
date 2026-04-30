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
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> col(n+1);
    auto dfs = [&] (auto &self, int u, int c) -> void {
        col[u] = c;
        for(int v: adj[u]){
            if(col[v] == 0){
                self(self, v, 3 - c);
            }
        }
    };
    dfs(dfs, 1, 1);
    vector<int> s,t;
    for(int i = 1; i <= n; i++){
        if(col[i] == 1) s.pb(i);
        else t.pb(i);
    }
    if(s.size() > t.size()) swap(s,t);
    vector<int> ans(n+1);
    for(int i = 0; i < s.size();i++){
        ans[s[i]] = (1LL << 60) - 1;
        ans[s[i]] ^= (1LL << 59);
        ans[s[i]] ^= (1LL << i);
    }
    for(int i = 0; i < t.size(); i++){
        ans[t[i]] = (1LL << 60) - 1;
        ans[t[i]] ^= (1LL << 58);
    }
    for(int j = 0; j < t.size(); j++){
        for(int i = 0; i < s.size(); i++){
            bool ok = 0;
            for(int v: adj[t[j]]){
                if(v == s[i]){
                    ok = 1;
                    break;
                }
            }
            if(ok == 0){
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
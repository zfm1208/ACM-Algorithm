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
    vector<int> odd(n+1, 0);
    for(int i = 1; i <= n; i++){
        for(int v: adj[i]){
            if(a[v] == 1) odd[i]++;
        }
    }
    queue<int> q0, q1;
    vector<int> vis(n+1, 0);     
    vector<int> KO(n+1, 0); 

    auto check = [&](int u) -> bool {
        if(a[u] == 0) return (odd[u] % 2 != 0);
        else return (odd[u] % 2 == 0);         
    };

    for(int i = 1; i <= n; i++){
        if(check(i)){
            vis[i] = 1;
            if(a[i] == 0) q0.push(i);
            else q1.push(i);
        }
    }

    vector<int> ans;
    while(!q0.empty() || !q1.empty()){
        int u;
        if(!q0.empty()){
            u = q0.front(); q0.pop();
        } else {
            u = q1.front(); q1.pop();
        }
        if(!check(u)){
            vis[u] = 0; 
            continue;   
        }

        ans.pb(u);
        KO[u] = 1; 

        if(a[u] == 0) continue;

        for(int v : adj[u]){
            if(KO[v]) continue;
            odd[v]--;
            if(!vis[v] && check(v)){
                vis[v] = 1;
                if(a[v] == 0) q0.push(v);
                else q1.push(v);
            }
        }
    }

    if(ans.size() == n){
        cout << "YES" << endl;
        for(int x : ans) cout << x << " ";
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}
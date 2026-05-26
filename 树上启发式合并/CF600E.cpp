#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
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
    vector<vii> adj(n+1);
    vector<int> col(n+1);
    for(int i = 1; i <= n; i++){
        cin >> col[i];
    }
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<map<int,int>> cun(n+1);
    vii ans(n+1);
    vii mx_cnt(n+1); // 用来记录每个节点当前的“最大出现次数”
    auto dfs = [&](auto& self, int u, int fa) -> void {

        int big = -1;
        for(int v: adj[u]){
            if(v == fa) continue;
            self(self, v, u);
            if(big == -1 || cun[big].size() < cun[v].size()){
                big = v;
            }
        }        
        int res = 0;
        int mx = 0;
        if(big != -1){
            swap(cun[u], cun[big]);
            mx = mx_cnt[big];
            res = ans[big];
        }
        

        cun[u][col[u]]++;
        if(cun[u][col[u]] > mx){
            mx = cun[u][col[u]];
            res = col[u];
        }else if(mx == cun[u][col[u]]){
            res += col[u];
        }

        for(int v: adj[u]){
            if(v == fa || v == big) continue;
            for(auto [x,y]: cun[v]){
                cun[u][x] += y;
                if(cun[u][x] > mx){
                    mx = cun[u][x];
                    res = x;
                }else if(cun[u][x] == mx){
                    res += x;
                }
            }
        }
        ans[u] = res;
        mx_cnt[u] = mx;
    };

    dfs(dfs, 1, 0);
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
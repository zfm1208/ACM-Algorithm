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
    vector<vector<pii>> e(n+1);
    vector<int> du(n+1);
    for(int i = 1; i <= m; i++){
        int x,y,z; cin >> x >> y >> z;
        adj[y].pb(x);
        adj[z].pb(x);
        e[x].pb({y,z});
        du[x] += 2;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) if(du[i] == 0){
        q.push(i);
    }
    int cnt = 0;
    vector<int> arr(n+1,1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cnt++;
        for(auto [y,z]: e[u]){
            arr[u] = max(arr[u], arr[y]+arr[z]);
        }
        for(int v: adj[u]){
            du[v]--;
            if(du[v] == 0){
                q.push(v);
            }
        }
    }
    if(cnt != n){
        cout << -1 << endl;
        return;
    }
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += arr[i];
        if(sum > 1e9){
            cout << -1 << endl;
            return;
        }
    }
    cout << sum << endl;
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
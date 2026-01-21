// 律己则安，越是执着，便是越苦;
// 安下心来，看该看的风景，做该做的事。
#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
double pi = acos(-1);
const int N = 1e6+10, mod = 1e9+7, inf = 1e18 + 5;
void solve() {
    int n; cin >> n;
    vector<pii> e[n+1],ans[n+1];
    map<int,int> mp;
    for(int i = 1; i <= n; i++){
        int m; cin >> m;
        for(int j = 1; j <= m; j++){
            int w; cin >> w;
            if(!mp[w]) mp[w] = i;
            else{
                e[i].push_back({mp[w],w});
                e[mp[w]].push_back({i,w});
            }
        }
    }
    vector<int> vis(n+1);
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        auto u = q.front(); q.pop();
        for(auto &[v,w] : e[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            ans[u].push_back({v,w});
            q.push(v);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cout<<"impossible";
            return;
        }
    }
    for(int i = 1; i <= n; i++){
        for(auto &[v,w] : ans[i]){
            cout << i << " " << v << " " << w << endl;
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
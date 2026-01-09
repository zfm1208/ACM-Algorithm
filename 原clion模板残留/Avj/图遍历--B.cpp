#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
const int N = 2e5 + 10;
using namespace std;
vector<int> a[1002];
bool vis[1002];
int res;
void dfs(int v){
    vis[v] = 1;
    res = max(res,v);
    for(int i = 0; i < a[v].size(); i++){
        if(!vis[a[v][i]]){
//            cout << v << " " << a[v][i] << endl;
            dfs(a[v][i]);
        }
    }
}
void solve()
{
    int n,m; cin >> n >> m;
    int u,v;
    while(m--){
        cin >> u >> v;
        a[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        memset(vis,0,sizeof(vis));
        res = 0;
        dfs(i);
        cout << res << " ";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
//    cin >> T;
    while(T--) solve();
    return 0;
}


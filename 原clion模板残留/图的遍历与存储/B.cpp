//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 1e3 + 5;
vector<int> mp[N];
bool vis[N];
int ans;
void dfs(int x){
    vis[x] = true;
    ans = max(ans,x);
    for(auto v : mp[x]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
void solve() {
    int n,m; cin >> n >> m;
    while(m--){
        int u,v;
        cin >> u >> v;
        mp[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        memset(vis,false,sizeof(vis));
        ans = 0;
        dfs(i);
        cout << ans << " ";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}

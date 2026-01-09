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
const int N = 2e5 + 5;
int n,d;
vector<int> mp[N];
int cnt;
bool vis[N];

// 该代码超时
void dfs(int x){
    if(x == 1){
        return;
    }
    for(auto v : mp[x]){
        if(!vis[v]){
            vis[v] = 1;
            dfs(v);
        }
    }
}
void solve() {
    cin >> n >> d;
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    for(int i = 2; i <= n; i++){
        memset(vis,0,sizeof(vis));
        dfs(i);
        if(cnt > d) continue;
        else cnt++;
    }
    cout << cnt << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}

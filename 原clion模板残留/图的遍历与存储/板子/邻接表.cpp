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

void solve() {
    int n,m; cin >> n >> m;
    //邻接表 存储边的关系
    vector<int> mp[n+5];
    for(int i = 1; i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    // 邻接表 存储边的关系以及边权
    vector<pii> mp1[n+5];
    for(int i = 1; i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        mp1[u].push_back({v,w});//{v, w} 那么first = v, second = w;
        mp1[v].push_back({u,w});
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

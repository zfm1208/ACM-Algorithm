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
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> a(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    vector<int> siz(n+1);
    auto dfs = [&](auto self, int u, int fa) -> bool {
        siz[u] = 1;
        for(auto v : a[u]){
            if(v == fa) continue;
            self(self, v, u);
            siz[u] += siz[v];
        }
    };
    dfs(dfs, 1,-1);

    int ans = n;
    for(int i = 1; i <= n; i++){
 		if(siz[i] >= k) ans += n - siz[i];
		if(n - siz[i] >= k) ans += siz[i];
	}
	cout << ans << endl;
    
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
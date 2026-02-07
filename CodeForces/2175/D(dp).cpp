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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
void solve() {
    // 1 <= k <= 360, 0 <= ai <= k
    int n,k; cin >> n >> k;
    vector<int>a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<int> pos(k+1,n+2); // pos[v]: 先达到v的最早下标
    for(int i = 1; i <= n; i++){
        for(int v = a[i]; v >= 1; v--){
            if(pos[v] != n+2) break;
            pos[v] = i;
        }
    }
    vector<vector<int>> dp(k+1,vector<int> (k+1,-1));
    dp[0][0] = 0; // dp[c][u] : 消耗c张牌能获得最大值u时的最大快乐值
    int ans = 0;
    for(int c = 0; c <= k; c++){
        for(int u = 0; u <= k; u++){
            if(dp[c][u] == -1) continue;
            ans = max(ans,dp[c][u]);
            for(int v = u+1; c+v <= k; v++){ // 若更新最大值位v
                if(pos[v] > n) continue;
                int temp = (v-u) * (n - pos[v] + 1);
                // 原来花费c，又花费v，dp[c+v][v]
                if(dp[c+v][v] < dp[c][u] + temp){
                    dp[c+v][v] = dp[c][u] + temp;
                }
            }
        }
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
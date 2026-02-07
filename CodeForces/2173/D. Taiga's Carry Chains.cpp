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
    int n,k; cin >> n >> k;
    int cnt_0 = 0;
    for(int i = 0; i < 30; i++){
        if(!(n >> i & 1)) cnt_0++;
    }
    if(k > cnt_0){
        cout << k - cnt_0 + 30 - 1 << endl;
        return;
    }
    vector<int> a(31),pre(31); 
    for(int i = 1; i <= 30; i++){
        a[i] = ((n >> (i-1)) & 1);
        pre[i] = pre[i-1] + (!a[i]);
    }
    // dp[i][z] : 到第i位截至，花费了z次，得到的最大贡献
    vector<vector<int>> dp(31,vector<int>(k+1));
    int ans = 0;
    for(int i = 1; i <= 30; i++){ 
        // 若更新
        for(int j = 0; j < i; j++){ 
            for(int z = 0; z <= k; z++){ 
                int x = pre[i]-pre[j];// (j,i]
                if(z >= x+1){
                    dp[i][z] = max(dp[i][z],dp[j][z-(x+1)] + i-j);
                }
            }
        }
        // 若跳过
        for(int z = 0; z <= k; z++){
            dp[i][z] = max(dp[i][z],dp[i-1][z]);
            ans = max(ans,dp[i][z]);
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
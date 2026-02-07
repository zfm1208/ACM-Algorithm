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
/*
    思路：
    全部修改一定满足题意，现在找不需要改动的地方，让这些地方的和最大，这样sum - mx的就最小
    n<=8000,可以 O(n*n) 暴力写
    不需要改动的地方仍需要满足 不递减 ，那么就是找最长的非递减子序列的价值最大值。
*/
void solve() {
    int n; cin >> n;
    vector<int> a(n),c(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    vector<int> dp(n); // dp[i] : 以i为结尾的 最长LCA 的最大价值
    for(int i = 0; i < n; i++){
        dp[i] = c[i];
        for(int j = 0; j < i; j++){
            if(a[i] >= a[j]){
                dp[i] = max(dp[i],dp[j] + c[i]);
            }
        }
    }
    // 计算c的总和 - dp[i]的最大值
    int ans = accumulate(c.begin(),c.end(),0LL) - *max_element(dp.begin(),dp.end());
    cout << ans << '\n';
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
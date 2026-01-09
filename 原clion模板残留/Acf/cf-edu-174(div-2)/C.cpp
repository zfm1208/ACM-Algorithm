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
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> dp(n+1,0);
    int ans = 0,cnt = 0;// cnt表示当前位置出现1的数量
    for(int i = 1; i <= n; i++){
        if(a[i] == 1){
            dp[i] = dp[i - 1];
            cnt++;
        }
        if(a[i] == 2){
            dp[i] = dp[i - 1] * 2 % mod2;//所有以1开头的子序列可以选择是否包含当前2
            dp[i] += cnt;//每个1共 (cnt1个) 可以与当前2组成新的子序列
            dp[i] %= mod2;
        }
        if(a[i] == 3){
            dp[i] = dp[i - 1];
            ans += dp[i];
            ans %= mod2;
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
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
    法1： 贪心

    假设第i个箱子用好钥匙，第i+1用坏钥匙
    假设第i个箱子用坏钥匙，第i+1用好钥匙
    我们比较一下这两者差值，可以发现，先好再坏更贪心
    那么我们可以推断出来，选择方式是前面都是好的，后面都是坏钥匙
    然后枚举那个为断点即可
    然后，前面好钥匙的贡献可以前缀和处理
    至于后面的坏钥匙，我们分析一下，每次后面的都是/2的操作，一个箱子最多/2  30次
    使用，我们枚举到，min(n,i+31) 的位置即可
*/
void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = -inf;
    vector<int> pre(n+1);
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i-1] + a[i] - k;
    }
    for(int i = 0; i <= n; i++){
        int res = pre[i];
        for(int j = i+1; j <= min(n,i+31); j++){
            res += (a[j] >> (j-i));
        }
        ans = max(ans,res);
    }
    cout << ans << endl;
}
/*
    法2：dp
    dp[i][j] : 前i个箱子，使用了j把坏钥匙 的最大贡献
*/
void solve1(){
    int n,k; cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(32,-inf));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= min(i, 31LL); j++){
            int cost = a[i] >> j; 
            if(j <= i - 1 && dp[i-1][j] != -inf){
                dp[i][j] = max(dp[i][j], dp[i-1][j] + cost - k);
            }
            if(j > 0 && dp[i-1][j-1] != -inf){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + cost);
            }
            if(j == 31 && dp[i-1][31] != -inf){
                dp[i][31] = max(dp[i][31], dp[i-1][31] + cost);
            }
        }
    }
    int ans = -inf;
    for(int i = 0; i <= 31; i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve1();
    return 0;
}
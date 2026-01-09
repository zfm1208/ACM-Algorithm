#include<bits/stdc++.h>
#define int long long
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
const int inf = 1e18;
const int N = 2e5+10;
int ksm(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
void gty(){
    int n,m; cin >> n >> m;
    vector<int> a(m+1);
    rep(i,1,m) cin >> a[i];
    // 卡 N !!!
    vector<int> dp(N);
    rep(i,1,m) dp[i] = inf;
    // dp[i]表示前i行 debug的最小时间？ 前i的错误行的debug 最小时间?
    // 前i行与后面行无关
    // 两种方式: 单独运行 + debud自己 1^4  == a[i] + 1
    //         [l,r] 共 r - l + 1 行bug一起degug  == a[r] + (r-l+1)^4
    // 枚举右端点 ，左端点l如何取???
    // dp[i] = min(dp[l-1] + a[i] + (a[i]-a[j]+1)^4,dp[l-1] + a[i] + 1)
//    dp[1] = 1 + a[1];
//    for(int i=2;i<=m;i++){
//        for(int j=min(0ll,i-50);j<i;j++){
//            dp[i] = min(dp[i-1] + a[i] + 1,dp[j-1] + a[i] + ksm(a[i]-a[j]+1,4));
//        }
//    }
//  25^4 == 390625
//  设这i行代码中现存的bug数量为x，那么需要x^4 秒来debug
//  现存的bug  若 前面的bug 修复了一部分  后面的bug

// 不对  我们枚举的是bug的行数 每一行都有bug x^4  x为行数之差 不用ksm(a[i]-a[j]+1,4))  而是ksm(i-j,4)
    for(int i = 1; i <= m; i++){
        for(int j = i-1; j >= max(0ll,i-40); j--){
            dp[i]=min(dp[i],dp[j]+a[i]+ksm(i-j,4));
            // j = i-1 ksm(i-j,4) == ksm(1,4) == 1
            //为第一种情况单独运行单独debug
        }
    }
    // 40^4 == 2e6
    // n max == 2e5
    //时间复杂度 O(m^2)
    // 最大内循环40次  倒着来
    // 时间复杂度O(m*40)
    cout << dp[m] << '\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
//    cin>>t;
    while(t--){
        gty();
    }
    return 0;
}
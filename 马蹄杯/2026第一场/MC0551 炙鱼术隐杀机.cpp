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
/*
    四层暴力循环肯定超时, 我们观察到让求异或和
    对于 异或和 来讲, 常见思路是按位拆分
    异或运算在二进制得各个位之间是完全独立的
    我们可以枚举每一位(最多30次)
    然后对于每个数的这一位除了0就是1
    我们可以观察这一位产生了多少1,多少0,然后乘以相应的权重(2^p)，然后累加到答案

    在单一的二进制下a和b都是0/1
    我们想一下矩阵b的每个元素到底和a里面哪些元素发生了碰撞？
    我们稍作推导可知 b[k][l] 覆盖的其实是a中大小为(n-m+1)*(n-m+1)的固定区域
    这个矩形区域的左上角是a[k][l] ,右下角是a[k+n-m][l+n-m]
    既然b[k][l]只和这个区域里的a元素异或,那么如果当前b[k][l] = 0, 那么a的这个区域里,有多少个1，异或后就能产生多少1
    反之 亦然
     
    我们很容易会想到二位前缀和



*/
void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(n+1));
    vector<vector<int>> b(m+1,vector<int>(m+1));
    rep(i,1,n) rep(j,1,n) cin >> a[i][j];
    rep(i,1,m) rep(j,1,m) cin >> b[i][j];
    int ans = 0;
    for(int p = 0; p <= 30; p++){
        vector<vector<int>> sum(n+1,vector<int> (n+1));
        rep(i,1,n) rep(j,1,n){
            int x = (a[i][j] >> p) & 1;
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + x;
        }
        int res = 0;

        for(int k = 1; k <= m; k++)
        {
            for(int l = 1; l <= m; l++)
            {
                
                int x1 = k, y1 = l;
                int x2 = k + n - m, y2 = l + n - m;
                int cnt1 = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
                int cnt0 = (n-m+1) * (n-m+1) - cnt1;
                int bi = (b[k][l] >> p) & 1;
                if(bi == 0){
                    res = (res + cnt1) % mod;
                }else{
                    res = (res + cnt0) % mod;
                }
            }
        }
        int pp = (1LL << p) % mod;
        ans = (ans + res * pp % mod) % mod;
    }
    cout << ans << endl;

    // 暴力代码：
    // for(int i = 1; i <= n-m+1; i++){
    //     for(int j = 1; j <= n-m+1; j++){
    //         for(int k = 1; k <= m; k++){
    //             for(int l = 1; l <= m; l++){
    //                 int x = a[i+k-1][j+l-1] ^ b[k][l];
    //                 ans = (ans + x) % mod;
    //             }
    //         }
    //     }
    // }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}
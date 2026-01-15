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
const int N = 1e6, mod = 998244353, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
int C[105][105];
void init(){
    for(int i = 0; i <= 100; i++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j++){
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
}
/*
 *  这是一个求"方案数"的问题，且 n, k 范围较小 (n <= 100)。
 *  关键洞察：题目中所有灯泡也是“对称”的。我们不需要关心具体“哪一盏灯”的状态不同，
 *  只需要关心“有多少盏灯”的状态与目标 t 不同。
 *  将问题转化为：初始有 cnt 个差异，经过 k 轮操作（每轮翻转 m 个），
 *  最终让差异数变为 0 的方案数是多少。
 * 
 * 
 *  dp[i][j] : 表示进行了第 i 轮操作后，当前状态与目标状态 t 相比，
 *  恰好有 j 个位置不同（差异数为 j）的方案数。
 *  初始状态：dp[0][cnt] = 1，其余为 0
 *  目标答案：dp[k][0]
 * 
 * 
 *  假设上一轮 (i-1) 结束时,差异数为 j 
 *  本轮需要按 m 个开关, 我们将 m 次按键分配为两部分：
 *      x 次：按在 "状态不同" 的灯上。
 *      效果：这 x 盏灯从 "不同" 变为 "相同" ，差异数 -x
 * 
 *      y 次：按在"状态相同"的灯上 (其中 y = m - x)
 *      效果：这 y 盏灯从“相同”变为“不同”，差异数 +y
 * 
 *  新状态 change = j - x + y = j - x + (m - x)
 *  转移方程：
 *  dp[i][change] += dp[i-1][j] * C(j, x) * C(n - j, m - x)
 *  约束条件：
 *  0 <= x <= m
 *  x <= j       (不能按超过现有的不同灯数)
 *  m - x <= n-j (不能按超过现有的相同灯数)
 */
void solve(){
    int n,k,m; cin >> n >> k >> m;
    string s,t; cin >> s >> t;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]) cnt++;
    }
    vector<vector<int>> dp(k+1,vector<int>(n+1));
    dp[0][cnt] = 1;
    for(int i = 1; i <= k; i++){ 
        for(int j = 0; j <= n; j++){
            if(dp[i-1][j] == 0) continue;
            for(int x = 0; x <= m; x++){ 
                int y = m - x;
                if(x <= j && y <= (n-j)){
                    int change = j - x + y;
                    dp[i][change] = (dp[i][change] + dp[i-1][j] * C[j][x] % mod * C[n-j][y] % mod) % mod;
                }
            }
        }
    }
    cout << dp[k][0] << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    init();
    cin >> T;
    while(T--)
        solve();
    return 0;
}
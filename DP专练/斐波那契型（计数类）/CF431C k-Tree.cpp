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
// https://codeforces.com/problemset/problem/431/C
/*
    * 分析
    首先我们发现这是一个计数问题，
    而且这个路径张什么样子无从知晓，连长度都不知道，那这就启发我们搞 dp
    我们可以考虑设一个跟权值和有关的 dp，
    但是有需要满足至少有一条边权值大于等于 d 的限制
    所有考虑再加上一维表示当前是否满足限制，即：设 dp[i][0/1]
​
    这一题n,k范围很小。

    * 状态转移：显然满足只能往满足转移，而不满足可以向两种状态转移
    表示权值和为 i 满足或不满足限制的方案数。
    dp[i][0/1] 表示从根节点出发权值和为i的路上是否有一条权值>=d的方案数
    dp[i][0] 不存在
    dp[i][1] 存在
    具体状态转移看代码
    * 注意初始化
    dp[0][0] = 1;
    dp[0][1] = 0;
*/
void solve(){
    int n,k,d;
    cin >> n >> k >> d;
    vector<vector<int>> dp(n+1,vector<int>(2));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= min(i,k); j++){
            if(j < d) {
                dp[i][0] = (dp[i][0] + dp[i-j][0]) % mod;  
                dp[i][1] = (dp[i][1] + dp[i-j][1]) % mod;
            }else{
                dp[i][1] = (dp[i][1] + dp[i-j][0] + dp[i-j][1]) % mod;
            }
        }
    }
    cout << dp[n][1] << endl;
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
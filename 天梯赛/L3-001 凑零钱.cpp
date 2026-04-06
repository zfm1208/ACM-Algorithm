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
// 给你n个数,问你能不能挑几个数使得之和 == m,并且让挑出来的数字典和最小
// n < 1e4  m < 1e2
// 典型的01背包问题,但限制条件成为了 恰好装满容量m

/*
    这一题的难点是 要保证字典序最小
    我们先把硬币降序排序
    然后跑一边01背包,看看有没有解
    最从从第 N 个硬币开始往回倒推,因为我们是从小硬币开始倒推的，
    只要当前这个小硬币能对凑出总金额有帮助，我们优先选它，
    这就完美保证了选出来的序列一定是字典序最小的！

    dp[i][j]: 从前i个硬币中去先,是否恰好能凑出金额 j

    dp[i][j] = dp[i-1][j] 
    要么不选当前硬币 a[i]（看看前 i-1 个能不能凑出 j）
    dp[i][j] = dp[i-1][j - a[i]]
    要么选当前硬币（看看前 i-1 个能不能凑出 j - a[i]）

    回溯输出：
    倒推时，优先看 j >= a[i] 且 dp[i-1][j - a[i]] 是否为 true，
    如果是，立刻选 a[i]，并让 j 减去 a[i]
*/
void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    sort(a.begin()+1,a.end(),greater<int>());
    vector<int> ans;
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    dp[0][0] = 1;
    // dp[i][j] = 0/1
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= a[i] && dp[i-1][j-a[i]]){
                dp[i][j] = 1;
            }
        }
    }
    if(dp[n][m] == 0){
        cout << "No Solution";
        return;
    }
    for(int i = n; i >= 1; i--){
        if(m >= a[i] && dp[i-1][m-a[i]]){
            m -= a[i];
            ans.pb(a[i]);
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
}
// 暴力dfs代码 29/30
void solve1(){
    int n,m; cin >> n >> m;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    sort(a.begin()+1,a.end());
    vector<int> ans;
    bool ok = 0;
    auto dfs = [&](auto& self, int u, int sum) -> void {
        if(ok) return;
        sum += a[u];
        if(sum > m) return;
        if(sum == m){
            ok = 1;
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
            }
            return;
        }
        for(int i = u+1; i <= n; i++){
            ans.pb(a[i]);
            self(self,i,sum);
            ans.pop_back();
            if(ok) return;
        }
    };
    for(int i = 1; i <= n; i++){
        if(ok) return;
        ans.pb(a[i]);
        dfs(dfs,i,0);
        ans.pop_back();
    }
    if(ok == 0){
        cout << "No Solution";
    }
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
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
    如果我们在第 i 个位置建了基站，
    那么上一个基站建在位置 j (j < i) 需要满足什么条件呢
    对于所有完全在 i 左边（即区间右端点 r < i）的需求区间 [l, r]
    它必须被 j 覆盖
    因此，上一个基站的位置 j必须满足 j >= l
    我们可以预处理一个数组lim[i], 表示： 如果要选择第i个位置为当前基站，
    上一个基站的最左合法位置

*/
/*
    前 i-1 个元素的最大值
    就等于“前 i-2 个元素的最大值”与“第 i-2 个元素”取最大值。
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+2);
    rep(i,1,n) cin >> a[i];
    int m; cin >> m;
    vector<int> L(n+2);
    for(int i = 1; i <= m; i++){
        int l, r; cin >> l >> r;
        L[r] = max(L[r], l);
    }
    // lim[i] 表示如果当前基站在 i，上一个基站的最左合法位置
    vector<int> lim(n+2);
    lim[1] = 0;
    for(int i = 2; i <= n+1; i++){
        lim[i] = max(lim[i-1], L[i-1]);
    }
    // dp[i]: 强制在第i个位置建立基站，并且覆盖前面所有要求的最小总成本
    vector<int> dp(n+2, inf);
    dp[0] = 0;
    deque<int> q;
    for(int i = 1; i <= n+1; i++){
        while(!q.empty() && dp[q.back()] >= dp[i - 1]){
            q.pop_back();
        }
        q.push_back(i - 1);
        while(!q.empty() && q.front() < lim[i]){
            q.pop_front();
        }
        if(!q.empty()){
            dp[i] = dp[q.front()] + a[i];
        }
    }
    cout << dp[n + 1] << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}
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
    完全背包板子, 只不过要求必须装满 n 
    背包容量：丝带的总长度 n。
    物品种类：长度分别为 a, b, c 的三种切法
    物品价值：每一段丝带的“价值”都是 1
    约束条件：必须恰好装满 n。
*/
void solve(){
    int n; cin >> n;
    vector<int> a(4);
    cin >> a[1] >> a[2] >> a[3];
    // dp[i] : 表示长度为 i 的丝带最多能切成多少段
    // 初始化为 -1：这是一个很重要的技巧，表示该长度目前 无法被恰好切出
    // dp[0] = 0;
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for(int i = 1; i <= 3; i++){
        for(int j = a[i]; j <= n; j++){
            if(dp[j - a[i]] != -1){
                dp[j] = max(dp[j], dp[j-a[i]] + 1);
            }
        }
    }
    cout << dp[n] << endl;
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
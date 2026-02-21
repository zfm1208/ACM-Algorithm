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
    *题意：
    !给定一个 1-6 的序列，每次操作可以修改任意位置的数为 1-6。
    !求最少修改次数，使得序列中任意相邻的两个数 u, v 满足：
    1. u != v 
    2. u + v != 7 

    *思路：动态规划 (DP)
    1. 状态定义：
    dp[i][j] 表示考虑前 i 个数，且第 i 个数被修改为 j (1<=j<=6) 时的最小修改次数。
    
    2. 状态转移：
    !对于当前第 i 位的数值 j，枚举前一位 i-1 的数值 p (1<=p<=6)
    !如果 (p, j) 合法（即 p!=j 且 p+j!=7）,则：
    dp[i][j] = min(dp[i][j], dp[i-1][p] + cost)
    其中 cost = (a[i] == j ? 0 : 1)。
    
    3. 初始状态：
    dp[1][j] = (a[1] == j ? 0 : 1)
    
    4. 最终答案：
    min(dp[n][1] ... dp[n][6])
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<vector<int>> dp(n+1,vector<int> (7,inf));
    for(int i = 1; i <= 6; i++){
        dp[1][i] = !(i == a[1]);
    }
    for(int i = 2; i <= n; i++){
        for(int lst = 1; lst <= 6; lst++){
            for(int now = 1; now <= 6; now++){
                if(lst != now && lst + now != 7){
                    dp[i][now] = min(dp[i][now], dp[i-1][lst] + !(a[i] == now));
                }
            }
        }
    }
    int ans = inf;
    for(int i = 1; i <= 6; i++){
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
}
void solve1(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    int ans = 0;
    for(int i = 2; i <= n; i++){
        if(a[i] == a[i-1] || a[i] + a[i-1] == 7){
            i++;
            ans++;
        }
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
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

void solve(){
    int n,k; cin >> n >> k;
    vector<double> p(n+1);
    for(int i = 1; i <= n; i++) cin >> p[i];
    sort(p.begin()+1,p.end(),[](auto x, auto y){
        return x > y;
    });
    vector<double> dp(n+1);
    // dp[j]: 表示在当前挑出的这些题中，恰好答对 j 道题的概率
    dp[0] = 1.0;
    int op = -1;
    double ans = 0;
    for(int i = 1; i <= n; i++){ // 当前第i题
        for(int j = i; j >= 0; j--){
            if(j == 0) dp[j] = dp[j] * (1 - p[i]);
            else dp[j] = dp[j-1] * p[i] + dp[j] * (1 - p[i]);
        }
        if(i >= k){
            double cur = 0.0;
            for(int j = (k + i + 1) / 2; j <= i; j++){
                cur += dp[j];
            }
            ans = max(ans, cur);
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
}
void solve1(){
    int n, k;  cin >> n >> k;
    vector<double> p(n + 1);
    for(int i = 1; i <= n; i++)  cin >> p[i];
    
    sort(p.begin() + 1, p.end(), [](auto x, auto y){
        return x > y;
    });
    // dp[i][j] : 表示在前 i 道题中，恰好答对 j 道题的概率
    vector<vector<double>> dp(n + 1, vector<double>(n + 1));
    dp[0][0] = 1.0;
    double ans = 0;
    for(int i = 1; i <= n; i++){ // 枚举当前做了前 i 题
        dp[i][0] = dp[i-1][0] * (1 - p[i]);
        for(int j = 1; j <= i; j++){
            dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1 - p[i]);
        }
        
        if(i >= k){
            double cur = 0.0;
            for(int j = (k + i + 1) / 2; j <= i; j++){
                cur += dp[i][j];
            }
            ans = max(ans, cur);
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve1();
    return 0;
}
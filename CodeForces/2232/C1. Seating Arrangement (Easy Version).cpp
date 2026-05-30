#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
// I 空
// E 有人
// A 任意
void solve(){
    int n,x,s; cin >> n >> x >> s;
    string S; cin >> S; S = " " + S; 
    vector<vector<vii>> dp(n + 1, vector<vii>(x + 1, vii(2, -1)));    
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            // 第i个人不选
            if(dp[i-1][j][0] != -1){
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0]);
            }
            if(dp[i-1][j][1] != -1){
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][1]);
            } 
            // 第i个人选了，并且s[i] = I / A，选空桌子
            if((S[i] == 'I' || S[i] == 'A') && j > 0){
                if(dp[i-1][j-1][0] != -1){
                    dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][0] + 1);
                }
                if(dp[i-1][j-1][1] != -1){
                    dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][1] + 1);
                }
            }
            // 第i个人选了，并且s[i] = E / A, 选空座位
            if(S[i] == 'E' || S[i] == 'A'){
                if(dp[i-1][j][0] != -1 && dp[i-1][j][0] < j * s){
                    dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][0] + 1);
                }
                if(dp[i-1][j][1] != -1 && dp[i-1][j][1] < j * s){
                    dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1] + 1);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= x; i++){
        ans = max(ans, max(dp[n][i][0], dp[n][i][1]));
    }
    cout << ans << endl;
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
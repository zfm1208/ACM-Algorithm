#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
//vector<pii> yz(int n){
//    vector<pii> ans;
//    for(int i = 2; i * i <= n; i++){
//        if(n % i == 0){
//            int cnt = 0;
//            while(n % i == 0){
//                n/=i;
//                cnt++;
//            }
//            ans.push_back({i,cnt});
//        }
//    }
//    if(n > 2){
//        ans.push_back({n,1});
//    }
//    return ans;
//}
//
//int f1(int x){
//    auto factors = yz(x);
//    int ans = 1;
//    for(auto & [_,y] : factors){
//        ans *= (y + 1);
//    }
//    return ans;
//}
//void solve() {
//    int n,m; cin >> n >> m;
//    int dp[55][55] = {0};
//    for(int i = 0; i <= n; i++){
//        for(int j = 0; j <= i ; j++){
//            if(j==0) dp[i][j] = 1;
//            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//        }
//    }
//    int temp = dp[n][m];
//    int ans = f1(temp);
//    cout << temp << " " << ans << endl;
//}

// N= P1^x1 * P2^x2* …… * Pn^xn;
// 因子M=（x1+1） * （x2+1） * …… *（xn+1）;
int f(int n){
    int ans = 1;
    int cnt;
    for(int i = 2; i * i <= n; i++){
        cnt = 0;
        while(n % i == 0){
            cnt++;
            n/=i;
        }
        ans *= (cnt + 1);
    }
    if(n > 2){
        ans *= 2;
    }
    return ans;
}
void solve() {
    int n,m; cin >> n >> m;
    int dp[55][55] = {0};
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    cout << dp[n][m] << " ";
    int temp = dp[n][m];
    int ans = f(temp);
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}

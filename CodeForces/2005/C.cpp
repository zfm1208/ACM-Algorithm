#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
double pi = acos(-1);
const int N = 1e5+10, mod = 998244353, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

void solve(){
    int n,m; cin >>n >> m;
    vector<string> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    string s = "narek";
    vector<int> dp(5,-inf);
    dp[0] = 0;
    // dp[i] : 经过了一些字符串后，当前"narek",进度在s[j]时获得的最大分数
    for(int i = 0; i < n; i++){
        auto ndp = dp;
        for(int j = 0;j < 5; j++){
            int x = j;
            int ans = dp[j];
            for(auto c: v[i]){
                if(c == s[x]){
                    x++;
                    if(x == 5){
                        ans+=5;
                        x = 0;
                    }
                }else if(s.find(c) != string::npos){
                    ans--;
                }
            }
            ndp[x] = max(ndp[x],ans);
        }
        dp = ndp;
    }
    int ans = 0;
    for(int i = 0; i < 5; i++){
        ans = max(ans, dp[i] - i);
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
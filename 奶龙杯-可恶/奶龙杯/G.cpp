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
void solve() {
    int n,x; cin >> n >> x;
    vector<int> a(n+1),b(n+1);
    int sum = 0;
    rep(i,1,n) cin >> a[i] >> b[i],sum += a[i] * b[i];
    vector<vector<int>> dp(n+1,vector<int> (x+1));
    // dp[i][j]: 前i的物品，能否凑出价值j
    dp[0][0] = 1;
    if(sum < x) {cout << "No" << endl; return;}
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            for(int k = 0; k <= b[i]; k++){
                if(dp[i-1][j] && j + k * a[i] <= x){
                    dp[i][j + k * a[i]] = 1;
                }
                if(dp[i][x]){
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
}
void gty(){
    int n,x; cin >> n >> x;
    vector<int> cun;
    for(int i = 1; i <= n; i++){
        int a,b; cin >> a >> b;
        int cnt = 1;
        while(b){
            int tp = min(cnt,b);
            cun.pb(a*tp);
            b -= tp;
            cnt *= 2;
        }
    }
    vector<int> dp(x+1);
    dp[0]=1;
    for(auto &val : cun){
        for(int j = x; j >= val; j--){
            if(dp[j - val]){
                dp[j] = 1;
            }
        }
    }
    cout << (dp[x] ? "Yes" : "No") << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--)
        gty();
    return 0;
}
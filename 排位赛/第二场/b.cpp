#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define fi first
#define se second
#define pii pair<int,int>
#define sort(a) sort(a.begin()+1,a.end())
#define endl '\n'
const int N = 1e6+5, mod = 998244353;
int ksm(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        b/=2;
        a = a * a % mod;
    }
    return res;
}
int jc[200];
int inv_jc[200];
void init(){
    jc[0] = 1;
    for(int i = 1; i <= 101; i++){
        jc[i] = jc[i-1] * i % mod;
    }
    inv_jc[101] = ksm(jc[101],mod-2) % mod;
    for(int i = 100; i >= 0; i--){
        inv_jc[i] = (inv_jc[i+1] * (i+1) % mod) % mod;
    }
}
int C(int n, int m){
    if(n < 0 || m > n) return 0;
    int ans = jc[n] % mod * inv_jc[m] % mod * inv_jc[n-m] % mod;
    return ans;
}
void fff(){
    int n,k,m; cin >> n >> k >> m;
    string s,t; cin >> s >> t;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == t[i]){
            cnt++;
        }
    }
    vector<vector<int>> dp(k+1,vector<int>(n+1));
    dp[0][cnt] = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= n; j++){
            for(int w = 0; w <= j; w++){ 
                int x = j-w; 
                if(x <= m && ((m - x )% 2 == 0)){
                    int cs = (m - x)/2;
                    dp[i][j] = (dp[i][j] + (dp[i-1][w] * C(n-w+cs,x) % mod * C(n,cs) % mod) % mod) % mod;
                }
            }
            for(int w = j; w <= n; w++){
                int x = w-j;
                if(x <= m && ((m - x) % 2 == 0)){
                    int cs = (m-x)/2;
                    dp[i][j] = (dp[i][j] + (dp[i-1][w] * C(n-w+cs,x) % mod * C(n,cs) % mod) % mod) % mod;
                }
            }
        }
    }
    cout << dp[k][n] << endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    init();
    cin >> T;
    while(T--){
        fff();
    }
    return 0;
}
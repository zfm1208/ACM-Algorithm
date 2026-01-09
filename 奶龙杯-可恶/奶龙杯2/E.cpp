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
    区间   hash(x_i * B^(n-i)) % P  != 0
    转化为 pre_R - pre_(L-1) * (B ^ len) != 0
    设 T_i = pre_i / B^i
    => T_R != T_(L-1)

    => 涂色游戏
*/
void solve(){
    int p, b, n, m;
	cin >> p >> b >> n >> m;
    vector<int> dp(1 << (n+1)),vis(1 << (n+1));
    // dp [mask] : 集合 mask 至少需要多少颜色
    // vis[mask] : 集合 mask 是否为独立集
    vector<vector<int>> mp(20,vector<int>(20));
    int mx = (1 << (n + 1)) - 1;
	if(p > n) {cout << "Yes";return;}
	for(int i = 1, u, v; i <= m; i++){
        cin >> u >> v; u--;
        mp[u][v] = 1;
    } 
	for(int mask = 0; mask <= mx; ++mask){
		dp[mask] = inf, vis[mask] = 1;
		for(int i = 0; i < n; i++) {
            if(mask & (1 << i)){
                for(int j = i + 1; j <= n; j++){
                    if(mask & (1 << j)) {
                        // i,j在集合里面，并且有边，不能同色
                        if(mp[i][j]) vis[mask] = 0; 
                    }                      
                } 
            }
        }
	}
	dp[0] = 0;
	for(int S = 1; S <= mx; S++){
	    for(int T = S; T; T = (T - 1) & S) {
		    if(vis[T]){
                dp[S] = min(dp[S], dp[S ^ T] + 1);  
            }               
        }
    }
	cout << (dp[mx] <= p ? "Yes" : "No");
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}
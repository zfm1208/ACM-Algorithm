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
const int N = 2e5, mod = 1e9+7, inf = 1e18 + 5;
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
    int n,k; cin >> n >> k;
    vector<int> a(n+1),b(n+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    sort(a.begin()+1,a.end(),greater<int>());
    sort(b.begin()+1,b.end(),greater<int>());
    vector<vector<vector<int>>> dp(2*n+1,vector<vector<int>>(k+1,vector<int>(k+1,-inf)));
    // dp[u][i][j]:第i回合,A选了i个,B选了j个时的daan(sumA-sumB)
    auto dfs = [&] (auto&self, int u, int i, int j) -> int {
        if(i == k && j == k) return 0;
        if(u == 2 * n) return 0;
        if(dp[u][i][j] != -inf) return dp[u][i][j];
        int used_A = i + (u/2 - j);
        int used_B = j + ((u+1)/2 - i);
        int res;
        if(u%2 == 0){ // A回合
            res = -inf;
            if(i < k && used_A < n){
                res  = max(res, self(self,u+1,i+1,j) + a[used_A + 1]);
            }
            res = max(res,self(self,u+1,i,j));
        }else{
            res = inf;
            if(j < k && used_B < n){
                res = min(res, self(self, u + 1, i, j + 1) - b[used_B + 1]); 
            }
            res = min(res, self(self, u + 1, i, j));
        }
        return dp[u][i][j] = res;
    };

    int ans = dfs(dfs,0,0,0);
    cout << ans << endl;
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
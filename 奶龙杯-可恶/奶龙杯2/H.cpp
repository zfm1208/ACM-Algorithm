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

void solve(){   
    int n; cin >> n; 
    vector<vector<int>> ans(n+1,vector<int>(n+1));
    rep(i,1,n) ans[i][i] = 1e8;
    for(int i = 1; i <= (n*(n-1))>>1; i++){
        int u,v; cin >> u >> v;
        ans[u][v] = n*(n-1)/2 - i + 1; // 保证i,j不同
    }
    rep(i,1,n)rep(j,1,n)
    cout << ans[i][j] << " \n"[j==n];
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
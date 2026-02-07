#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r)for(int i = l; i <= r; i++)
#define pii pair<int, int>
#define pb push_back
#define se second
#define fi first
#define endl '\n'
int l, n, m;
short dp[310][310][310]; 
int a[310];
int b[310][310];
vector<pii> v[90010]; 
bool dfs(int x, int y, int k){
    if(dp[x][y][k] != -1)return dp[x][y][k];
    if(k == l)return true;
    bool ok = 1; 
    for(auto [nx, ny] : v[a[k + 1]]){
        if(nx > x && ny > y){
            if(dfs(nx, ny, k + 1)){
                ok = 0;
                break; 
            }
        }
    }
    dp[x][y][k] = ok;
    return ok;
}

void solve(){
    cin >> l >> n >> m;
    rep(i, 1, n * m + 5)v[i].clear(); 
    rep(i, 1, l)cin >> a[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x; cin >> x;
            b[i][j] = x;
            while(v[x].size()&& v[x].back().se < j)v[x].pop_back();
            v[x].pb({i, j});
        }
    }
    rep(i, 1, n)rep(j, 1, m){
        for(int k = 0; k <= l; k++)dp[i][j][k] = -1;
    }
    for(auto [x, y] : v[a[1]]){
        if(dfs(x, y, 1)){
            cout << "T" << endl;
            return;
        }
    }
    cout << "N" << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)solve();
    return 0;
}
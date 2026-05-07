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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }

    int ans = k; 

    auto dfs = [&](auto&& self, int rem) -> void {
        ans = min(ans, rem);
        
        if(ans == 1) return;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(g[i][j] == 1){
                    // 1. 向上跳 
                    if(i >= 3 && g[i - 1][j] == 1 && g[i - 2][j] == 0){
                        g[i][j] = 0; g[i - 1][j] = 0; g[i - 2][j] = 1; 
                        self(self, rem - 1);                            
                        g[i][j] = 1; g[i - 1][j] = 1; g[i - 2][j] = 0; 
                    }
                    
                    // 2. 向下跳
                    if(i <= n - 2 && g[i + 1][j] == 1 && g[i + 2][j] == 0){
                        g[i][j] = 0; g[i + 1][j] = 0; g[i + 2][j] = 1;
                        self(self, rem - 1);
                        g[i][j] = 1; g[i + 1][j] = 1; g[i + 2][j] = 0;
                    }
                    
                    // 3. 向左跳
                    if(j >= 3 && g[i][j - 1] == 1 && g[i][j - 2] == 0){
                        g[i][j] = 0; g[i][j - 1] = 0; g[i][j - 2] = 1;
                        self(self, rem - 1);
                        g[i][j] = 1; g[i][j - 1] = 1; g[i][j - 2] = 0;
                    }
                    
                    // 4. 向右跳
                    if(j <= m - 2 && g[i][j + 1] == 1 && g[i][j + 2] == 0){
                        g[i][j] = 0; g[i][j + 1] = 0; g[i][j + 2] = 1;
                        self(self, rem - 1);
                        g[i][j] = 1; g[i][j + 1] = 1; g[i][j + 2] = 0;
                    }
                }
            }
        }
    };

    dfs(dfs, k);
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
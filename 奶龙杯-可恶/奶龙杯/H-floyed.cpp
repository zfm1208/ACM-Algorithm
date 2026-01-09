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
const int N = 2e5 + 7, mod = 1e9+7, inf = 1e18 + 5;
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
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<vector<int>> dis(n+1,vector<int>(n+1,inf));
    vector<vector<int>> w(n+1,vector<int>(n+1));
    string s[n+1];
    rep(i,1,n) cin >> s[i];
    for(int i = 1; i <= n; i++){
        s[i] = " " + s[i];
        dis[i][i] = 0; w[i][i] = a[i];
        for(int j = 1; j <= n; j++){
            if(s[i][j] == 'Y'){
                dis[i][j] = 1;
                w[i][j] = a[i] + a[j];
            }
        }
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    w[i][j] = w[i][k] + w[k][j] - a[k];
                }else if(dis[i][k] + dis[k][j] == dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j]; 
                    w[i][j] = max(w[i][k] + w[k][j] - a[k],w[i][j]);
                }
            }
        }
    }

    int q; cin >> q;
    while(q--){
        int u,v; cin  >> u >> v;
        if(dis[u][v] == inf){
            cout << "Impossible" << endl;
        }else{
            cout << dis[u][v] << " " << w[u][v] << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
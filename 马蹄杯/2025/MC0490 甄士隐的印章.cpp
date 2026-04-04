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
    int n,m,q; cin >> n >> m >> q;
    vector<vector<char>> a(m+1,vector<char>(m+1));
    vector<vector<int>> ans(n+1,vector<int>(n+1));
    rep(i,1,m) rep(j,1,m) cin >> a[i][j];
    while(q--){
        int op; cin >> op;
        if(op == 1){
            vector<vector<char>> b(m+1,vector<char>(m+1));
            for(int i = 1; i <= m; i++)
                for(int j = 1; j <= m; j++){
                    b[i][j] = a[m-j+1][i];
                }
            a = b;
        }else{
            int x,y; cin >> x >> y;
            for(int i = 1; i <= m; i++){
                for(int j = 1; j <= m; j++){
                    if(i+x-1 > n || j+y-1 > n) continue;
                    ans[i+x-1][j+y-1] += (a[i][j] == '#');
                }
            }
        }
    }
    rep(i,1,n) {
        rep(j,1,n) cout << ans[i][j] << " ";
        if(i < n) cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}
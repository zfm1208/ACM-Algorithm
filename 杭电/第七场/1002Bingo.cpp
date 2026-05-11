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
    int n; cin >> n;
    vector<vector<int>> a(n+1, vector<int>(n+1));
    vector<vector<int>> vis(n+1, vector<int>(n*n+1)),vis1(n+1, vector<int>(n*n+1)); 
    rep(i,1,n) rep(j,1,n){
        cin >> a[i][j];
        vis[i][a[i][j]]++;
        vis1[j][a[i][j]]++;
    }
    vector<int> ans;
    for(int  p= 1; p <=  n*n; p++){
        bool ok = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i][p] == 0) ok = 1;
        }
        for(int i = 1; i <= n; i++){
            if(vis1[i][p] == 0) ok = 1;
        }
        if(ok == 0) ans.pb(p);
    }
    cout << ans.size() << endl;
    for(int x: ans) cout << x << " ";
    cout << endl;
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
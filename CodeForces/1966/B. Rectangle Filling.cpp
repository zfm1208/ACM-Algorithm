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
    int n,m; cin >> n >> m;
    vector<vector<char>> a(n+1,vector<char>(m+1));
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    if(a[1][1] == a[n][m] || a[1][m] == a[n][1]){
        cout << "YES" << endl;
        return;
    }
    if(a[1][m] == a[1][1]){
        for(int i = 1; i <= m; i++){
            if(a[n][i] == a[1][1]){
                cout << "YES" << endl;
                return;
            }
        }
    }
    if(a[1][1] == a[n][1]){
        for(int i = 1; i <= n; i++){
            if(a[i][m] == a[1][1]){
                cout << "YES" << endl;
                return;
            }
        }
    }
    if(a[n][m] == a[1][m]){
        for(int i = 1; i <= n; i++){
            if(a[i][1] == a[n][m]){
                cout << "YES" << endl;
                return;
            }
        }
    }
    if(a[n][m] == a[n][1]){
        for(int i = 1;i <= m; i++){
            if(a[1][i] == a[n][m]){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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
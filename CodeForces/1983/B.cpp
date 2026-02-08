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
    一对对角 + 1 (mod 3)
    一对对角 + 2 (mod 3) => 一对对角 - 1 (mod 3)
    观察发现每行每列的和 mod 3 不变
*/
void solve(){
    int n,m; cin >> n >> m;
    vector<string> a(n);
    rep(i,0,n-1) cin >> a[i];
    vector<string> b(n);
    rep(i,0,n-1) cin >> b[i];
    for(int i = 0; i < n; i++){
        int sum1 = 0,sum2 = 0;
        for(int j = 0; j < m; j++){
            sum1 = (sum1 + a[i][j] - '0') % 3;
            sum2 = (sum2 + b[i][j] - '0') % 3;
        }
        if(sum1 != sum2){
            cout << "NO" << endl;
            return;
        }    
    }
    for(int j = 0; j < m; j++){
        int sum1 = 0,sum2 = 0;
        for(int i = 0; i < n; i++){
            sum1 = (sum1 + a[i][j] - '0') % 3;
            sum2 = (sum2 + b[i][j] - '0') % 3;
        }
        if(sum1 != sum2){
            cout << "NO" << endl;
            return;
        }    
    }
    cout << "YES" << endl;
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
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
    vector<int> a(n+1);
    vector<int> du(n+1);
    for(int i = 1; i < n; i++){
        int u,v ; cin >> u >> v;
        du[u]++;
        du[v]++;
    }
    for(int i = 1; i <= n; i++){
        if(du[i] > 3){
            cout << 0 << endl;
            return;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(du[i] <= 2) ans++;
    }
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
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
const int N = 1e18, mod = 1e9+7, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
map<int,int> mp;
void init(){
    for(int k = 2; k <= N; k++){ 
        int ans = 1;
        // cout << "K： " << k << endl;
        int tp = 1;
        for(int x = 1; ; x++){
            tp*=k;
            ans += tp;
            // cout << ans << " ";
            if(x > 1) mp[ans] = 1;
            if(ans > N) break;
        }
        // cout << endl;
    }    
}
void solve(){
    int n; cin >> n;
    if(mp[n]) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    init();
    while(T--)
        solve();
    return 0;
}
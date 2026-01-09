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
    rep(i,1,n) cin >> a[i];
    auto check = [&] (int l, int r, int i) -> bool {
        return (a[l] - a[i]) *  (a[r] - a[i]) > 0; // 同号否
    };
    for(int i = 1,l,r; i <= n; i++){
        l = r = i;
        int len = 3, ok = 0;
        while(l >= 1 || r <= n){
            if(l > 1 && r < n && (check(l-1,r+1,i))){
                // cout << i << " " << l-1 << " " << r+1 << endl;
                ok = 1;
                break;
            }
            if(l > 2 && check(l - 1, l - 2, i)){
                // cout << i << " " << l-1 << " " << l-2 << endl;
                ok = 1;
                break;
            }
            if(r <= n - 2 && check(r + 1, r + 2, i)){
                // cout << i << " " << r+1 << " " << r+2 << endl;
                ok = 1;
                break;
            }
            if(i > 1 && r < n && check(r, r + 1, i)){
                // cout << i << " " << r << " " << r+1 << endl;
                ok = 1;
                break;
            }
            if(i < n && l > 1 && check(l, l - 1, i)){
                // cout << i << " " << l << " " << l-1 << endl;
                ok = 1;
                break;
            }
            len += 2;
            l -= 2,r += 2;
        }
        cout << (ok == 1 ? len : -1) << " ";
    }
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
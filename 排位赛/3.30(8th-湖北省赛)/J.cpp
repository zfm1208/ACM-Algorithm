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
int ksm(int a, int b) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
// 考察逆元+ksm+取模
void solve(){
    int m; cin >> m;
    vector<int> a(10);
    for(int i = 0; i < 10; i++){
        cin >> a[i];
    }
    if(m == 1){
        for(int i = 0; i < 10; i++){
            if(a[i]) {
                cout << i << endl;
                return;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= 9; i++){
        if(a[i]){
            ans = i;
            a[i] --;
            m--;
            break;
        }
    }

    for(int i = 0; i <= 9; i++){
        if(m == 0) break;
        int k = min(m, a[i]);
        m -= k;
        if(k == 0) continue;
        int p = ksm(10,k);
        int cnt1 = (p - 1 + mod) % mod * ksm(9,mod-2) % mod;
        int x = cnt1 * i % mod;
        ans = (ans * p % mod + x) % mod;
    }
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
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
// 区间异或和 - 前缀异或
void solve() {
    // pre[j] = a[1] ^ a[2] ^ a[3] ^ .... ^ a[j];
    // pre[i] = a[1] ^ a[2] ^ ..... ^ a[i];
    // pre[j] ^ pre[i-1] =  a[i] ^ a[i+1] ^ ... ^ a[j]
    // 所以 pre[r] ^ pre[l-1] = 0; -> a[r] == a[l-1];
    // 倒推可以得出：a[i] = pre[i] ^ pre[i-1]
    int n,l,r; cin >> n >> l >> r;
    vector<int> pre(n+1);
    for(int i = 1; i <= n; i++){
        pre[i] = (i == r ? l-1 : i);
        cout << (pre[i] ^ pre[i-1]) << " \n"[i==n];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
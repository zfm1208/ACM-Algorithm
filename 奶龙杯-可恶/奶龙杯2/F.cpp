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
const int N = 2e5+10, mod = 998244353, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
int inv[N];
int jc[N];
void init(){
    jc[0] = 1;
    for(int i = 1; i < N; i++){
        jc[i] = jc[i-1] * i % mod;
    }
    inv[N-1] = fpow(jc[N-1],mod-2);
    for(int i = N-2; i >= 0; i--){
        inv[i] = inv[i+1] * (i+1) % mod;
    }
}
int C(int n,int m){
    if(m < 0 || m > n) return 0;
    return jc[n] * inv[m] % mod * inv[n-m] % mod;
}
void solve(){
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    if(m&1 || m <= 2){
        cout << 0 << endl;return;
    }
    auto calc = [&] (int n, int m, int x) -> int {
        int sum = 0;
        for(int i = 0; i < m; i++){
            int sx = m - i - 1;
            // -1是因为x这个位置被一组白棋占据
            int l = C(x-1-i,i);
            int r = C(n-(x+1)-sx,sx);
            // 从右边跨越白棋回到起点x
            if(sx > 0){ 
                int way = l * r % mod * sx % mod * jc[m-2] % mod;
                sum = (sum + way) % mod;
            }
            int ll = C(x-i-2,i);
            int rr = C(n-x-sx,sx);
            // 从左边跨越白棋回到起点x
            if(i > 0){
                int way = ll * rr % mod * i % mod * jc[m-2] % mod;
                sum = (sum + way) % mod;
            }
        }
        return sum;
    };
    int hang = calc(n,m >> 1, a);
    int lie = calc(n,m >> 1, b);
    cout << hang * lie % mod * 2 % mod << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    init();
    //cin >> T;
    while(T--)
        solve();
    return 0;
}
//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
int f[N],g[N];
int ksm(int a,int b){
    int res = 0;
    while(b){
        if(b & 1) res = res * a % mod1;
        b >>= 1;
        a = a * a % mod1;
    }
    return res;
}
int comb(int n,int m){
    return f[n] * g[m] % mod1 * g[n - m] % mod1;
}
void init(){
    f[0] = 1;g[0] = 1;
    for(int i = 1; i <= N; i++){
        f[i] = f[i - 1] * i % mod1;
        g[i] = g[i - 1] * ksm(i,mod1 - 2) % mod1;
    }
}
void solve() {
    int n,k; cin >> n >> k;
    cout << comb(n,k) % 2 << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    init();
    cin >> T;
    while (T--) solve();
    return 0;
}

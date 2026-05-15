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
const int N = 1e6, mod = 998244353, inf = 1e18 + 5;
/*
    2 4 8 12 16
    删 2 4 剩下的数都要是4倍数(8, 12, 16)
    3 6 9 12 15
    删 3  剩下的数都要是3倍数(6, 9, 12, 15)
    2 4 8 16 24 36 48
    删 2 4 8 剩下的数都要是8倍数(16, 24, 36, 48)

    若一个大小为n的集合连续删除了k个元素, 从小到大依次为,x1,x2,x3...,xk
    那么会形成一个整除链 x1 | x2 | x3 | ... | xk
    链的最后一个数xk,必须整除 集合里面剩下未被删除的所有元素
    并且剩下的 n - k 个元素必须严格大于 xk

    把题目转化一下: ans = C(m,n)*n  - 删去的总数

    tot = 删去的总个数 = 所有合法整除链在所有子集出现的次数
    对于一条长度为k, 以v结尾的整除链(xk = v) , 大于v且是v的倍数的个数 cnt = (m / v) - 1
    所以这条链的贡献为 C(n-m, cnt)

    我们要求出所有长度为k,且结尾为v的整除链的条数
    dp[k][v] : 表示长度为k, 且以数字 v 结尾的整除链的数量
    边界 dp[1][v] = 1;
    dp[k][v] = sum (u | v && u < v) dp[k-1][u]

*/
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
int fact[N], inv[N];
void init() {
    fact[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % mod;
    inv[N - 1] = ksm(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}

int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fact[n] * inv[m] % mod * inv[n - m] % mod;
}

void solve(){
    int m,n; cin >> m >> n;
    vector<vector<int>> dp(20, vector<int>(m+1));
    for(int i = 1; i <= m; i++){
        dp[1][i] = 1;
    }
    // dp[k][v] : 表示长度为k, 且以数字 v 结尾的整除链的数量
    for(int k = 2; k <= min(18LL, n); k++){
        for(int u = 1; u <= m; u++){
            if(!dp[k-1][u]) continue;
            for(int v = 2 * u; v <= m; v += u){
                dp[k][v] = (dp[k][v] + dp[k-1][u]) % mod;
            }
        }
    }
    int sum = 0;
    for(int k = 1; k <= min(18LL, n); k++){
        for(int v = 1; v <= m; v++){
            if(!dp[k][v]) continue;
            int cnt = m / v - 1;
            if(cnt >= n - k){
                sum = (sum + dp[k][v] * C(cnt, n - k) % mod) % mod;
            }
        }
    }
    int ans = n * C(m,n) % mod;
    ans = (ans - sum + mod) % mod;
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    init();
    // cin >> T;
    while(T--)
        solve();
    return 0;
}
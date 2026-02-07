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
int C[60][60];
void init(){
    rep(i,0,60) C[i][0] = 1;
    for(int i = 1; i < 60; i++){
        for(int j = 1; j <= i; j++){
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}
// int cnt = __builtin_ctz(n); // 后尾0的个数
// int cnt = __builtin_clz(n);// 前导0的个数
// int cnt = __builtin_popcount(n); // 1的个数
void solve(){
    int n,k; cin >> n >> k;
    int mx = 0;

    // 100000
    while(n > 1){
        n >>= 1;
        mx++;
    }
    
    int ans = 0;
    for(int i = 0; i < mx; i++){
        int mn = max(k-i,0LL);
        for(int j = mn; j <= i; j++){
            ans += C[i][j];
        }
    }
    if(mx + 1 > k) ans++;
    cout << ans << endl;
}
// n = 2^d (d >= 0)
// bob从1-n选一个数x  (alice知道奇偶)
// alice进行操作之一
// 1.x = x >> 1 (x偶) -> 右移
// 2.x = x - 1  (x奇) -> 末尾变0
// 每操作一次bob会给予反馈
// 若x==0 , 回答-1 (alice-win)
// 否则 回答一个数 a 
// (a满足 : 2^a % x == 0 && 2^(a+1) % x != 0) 
// 也就是说 x 恰好包含了 a 个因子2。
// 游戏进行k次，bob不想alice-win,问1-n有多少数可以满足他
// (20):10100 -> 1010 -> 101  5*(2^2)
// 1110001000000 -> a = 6
// ==> 一个数x变为0的次数>k即可

/*
    7 (111) -> 110 -> 11 -> 10 -> 1 -> 0
    1. 7 -> 6
    2. 6 -> 3
    3. 3 -> 2
    4. 2 -> 1
    5. 1 -> 0
    ans = 5
    
    6 (110) 
    1. 6 -> 3
    2. 3 -> 2
    3. 2 -> 1
    4. 1 -> 0
    ans = 4

    56 (111000)
    111000 -> 11100 -> 1110 -> (111 -> 110) -> (11 -> 10) -> (1 -> 0)
    ans = 5 + 3 = 8
    
    cnt = 最位数(x) + 1个数(y)

    x [1 ~ 1000000]
    x [1 ~  111111] + [1000000]
      [1 ~  1111]
    // 1001001
    x cnt = i + 1 + 剩下1的个数(j) > k
    cnt = i + 1 + j > k
    j > k-i-1
    i >= j >= k-i

    100110
    101001
*/
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
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
/*
    在读完题目之后我是没有思路的
    但我们要去思考该怎么去做
    这一题的数据范围支持我们O(n^2)去实现
    在仅包含0和1的字符串中，只能交换相邻字符
    要把字符串S 变成 字符串T, 有一个很重要的性质
    ! 相同字符之间的相对顺序在优先交换的策略中是不会改变的
    也就是说 S 里面第 i 个1 最终一定会移动到 T 里面的第 i 个位置 

    假设 S 中所有 1 的位置构成的数组位P(p1,p2,...pc), T 中1 构成数组为Q(q1,..qc)
    so: 将S -> T 要操作 sum of |pi - qi| (range i : 1 to c)

    当然穷举所有T 是行不通的, 那我们需要把求和顺序换一下
    与其先固定T 再算S 中每个1 的贡献, 不如, 先固定S 中 第i个1 ，去算它可能T的移动贡献

    那么在C(n,c)中的T串中，有多少种可以让第 i 个恰好落到位置 x 呢？
    我们发现:
    <1>:  在 x 左边的 x-1个空位里面, 我们必须恰好放下前i-1个1, C(x-1,i-1)
    
    <2>:  在 x 右边的 n-x个空位里面, 我们必须恰好放下后c-i个1, C(n-x,c-i)
    
    那么总共满足第i个1 落在位置 X 的T字符串有 C(x-1,i-1) * C(n-x,c-i)个

    ! 做法：

    先吧S中1个位置下标存起来
    然后外层循环枚举 第i个1 的位置
    内层循环 枚举 这个 1 落点在 X 的情况
    最后累加答案即可

*/
void solve() {
    int n;  cin >> n;
    string s; cin >> s;
    s = " " + s;
    vector<int> p;
    for(int i = 1; i <= n; i++){
        if(s[i] == '1') {
            p.pb(i); 
        }
    }
    int ans = 0;    
    for(int i = 1; i <= p.size(); i++){
        for(int x = 1; x <= n; x++){
            int tp = C(x - 1, i - 1) * C(n - x, p.size() - i) % mod * abs(p[i - 1] - x) % mod;
            ans = (ans + tp) % mod;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init(); 
    int T = 1; 
    // cin >> T; 
    while (T--) {
        solve();
    }
    return 0;
}
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
// https://qoj.ac/contest/1071/problem/5301
/*
    * 题意：
    有一个整数序列 a1,a2,a3....an
    她觉得序列里的元素太大了，所以决定给序列加上一个等差数列。
    她可以选择两个非负整数 s 和 d
    并对每个 k of (1 ~ n)，将 a[k] 加上 s + k * d
    请告诉她操作后所有元素之和对 m 取模的最小值。
    注意，你应该最小化取模后的元素总和（注：题意指先求和，再对 m 取模）

    * 分析:
    T = S + n * s + n * (n + 1) / 2 * d
    最终需要找到 s, d 使得 T % m 的值最小
    不妨 令 C = n * (n + 1)
    求 (S + n * s + C * d) % m 的最小值

    T = (sum + n * s + C * d) % m 
      = sum + n * s + C * d + k * m
      = sum + n * s + k1 * g1
      = sum + k2 * G
      = sum % G

    * 看到 A * x + B * y (mod m) 的式子, 我们要想到 裴蜀定理和 GCD


*/
int ex_gcd(int a, int b, int &x, int& y) {
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = ex_gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}
void solve() {
    int n, m, sum = 0; 
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        sum = (sum + x) % m;
    }
    
    // 第一次裴蜀定理：求能改变的最小步长 g
    int A = n;
    int B = n * (n + 1) / 2;
    int g = __gcd(A, B);
    
    // 第二次裴蜀定理：求最终取模后的最小值 ans
    int gg = __gcd(g, m);
    int ans = sum % gg; 
    cout << ans << "\n";  

    int t = -(sum / gg);        // 为了达到 ans，我们需要减去多少个 gg？（注意这里带负号）
    
    // 反推过程 1：找出凑出 t * gg 需要的中间变量 x
    int x, y;
    ex_gcd(g, m, x, y);         // 此时 g*x + m*y = gg
    x *= t;                     // 等式两边同乘 t，得到 g*(x*t) + m*(y*t) = t*gg
    x = (x % m + m) % m;        // 防止负数溢出
    
    // 反推过程 2：找出真正的答案 s 和 d
    int s, d;
    ex_gcd(A, B, s, d);         // 此时 A*s + B*d = g
    s *= x;                     // 等式两边同乘 x
    d *= x; 
    s = (s % m + m) % m;      
    d = (d % m + m) % m;
    
    cout << s << " " << d << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}
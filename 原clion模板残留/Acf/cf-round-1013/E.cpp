//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 1e7 + 500;
//给定n (2<=n<=1e7), 有a和b ： 1 <= a < b <= n
// 让求序对(a,b)满足式子的个数
// : lcm(a,b) / gcd(a,b) == 质数
// 假设gcd(a,b) == k ,则a -> x * k, b -> y * k
// 则lcm(a,b) / gcd(a,b) = x * y * k / k  ==>  x*y
// x*y必须是素数 且 a < b      (a -> x * k, b -> y * k)
// 故: 所以x==1 y==素数
// 所以 lcm(a,b) / gcd(a,b) = x*y == y == b/a
// b == y * a (y是素数)
// 对于i (i属于1~n) ,i == y * a ，合法的个数si
// sum = sum(si)(i属于1~n)
// 就是求pre[i]的因子的个数
// 枚举素数
int vis[N], val[N], pre[N];
void shai(){
    vis[0] = vis[1] = 1;
    for (int i = 2; i < N; i++) {
        if(!vis[i]){
            val[i]++;
            for (int j = i + i; j < N; j += i) {
                vis[j] = 1;
                val[j]++;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        pre[i] = pre[i - 1] + val[i];
    }
}
void solve() {
    int n; cin >> n;
    cout << pre[n] << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    shai();
    cin >> T;
    while (T--) solve();
    return 0;
}

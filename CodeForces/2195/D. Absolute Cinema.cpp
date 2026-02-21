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

/*
    切入点一： 绝对值 |i-x| 的几何意义
    1：这是数轴上，x点到其他点i的加权距离之和
    2：这是关于一个x的函数

    切入点二：变量x的递增性质
    题目给了f[1], f[2], f[3]....f[n]
    x是连续变化的
    在数学中这种变量+1递增的，要联想到相邻两项做差：(f[x+1] - f[x])
    在离散数学叫 差分， 在连续函数 叫 求导

    为什么想做差？
    因为绝对值很难处理， 但你从x移到x+1时，绝大多数点的相对位置是不变的
    在x左边的点，依旧在x+1的左边
    在x右边的点，依旧在x+1的右边
    只有x和x+1之间发生了变化
    
    <1>: 拆绝对值
    在x的移动过程中，我们将求和分为两部分，左边i <= x，和右边i > x

    <2>: 尝试计算f[x+1] - f[x]

    得到f[x+1] - f[x] = 左边的权重和 - 右边的权重和

    然后预处理一下前缀和，化简式子即可(O(1)求出)
    我们发现求的有pre,但我们要求a[i], 我们再做一次差分
    pre[i] - pre[i-1] = a[i]
    
    <3>: 最后会得到a[x] 和 三个相邻f[x] 的关系

    f[x+1] - 2*f[x] + f[x-1] = a[x]

    最后注意下边界即可
*/


/*
    f[x] = sum of (a[i] * |i - x|)
    遇到这种式子，常见的是拆开绝对值，然后利用f[x] 和 f[x+1] 的递推关系(差分)
    这一题：拆开绝对值发现是线性求和，立刻尝试f[x] - f[x+1]，尝试消掉求和符号，然后求项
*/


/*
    f[x] = sum of (a[i] * |i - x|)
    i <= x : f[x] = sum of (a[i] * |x - i|)
    i >  x : f[x] = sum of (a[i] * |i - x|)

                    (i: 1~x)                (i: i+1~n)
    f[x] = sum of (a[i] * (x - i)) + sum of (a[i] * |i - x|)

    f[x+1], f[x]
    i <= x : (x - i) -> (x + 1 - i)  add +1  =>  + sum of a[i]
    i >  x : (i - x) -> (i - x - 1)  add -1  =>  - sum of a[i]
    f[x+1] - f[x] = sum of a[i] (1~x) - sum of a[i] (x+1~n)

    pre[i] : pre sum of a[i]

    f[x+1] - f[x] = pre[x] - (pre[n] - pre[x])
                  = 2 * pre[x] - pre[n]
    
    a[x] = pre[x] - pre[x-1]
    记S[x] = f[x+1] - f[x] = 2*pre[x]-pre[n]
    S[x-1] = f[x] - f[x-1] = 2*pre[x-1]-pre[n]
    S[x] - S[x-1] = 2 * a[i]

    a[i] = (f[x+1] - 2* f[x] + f[x-1]) >> 1

*/
void solve(){
    int n; cin >> n;
    vector<int> f(n+1);
    rep(i,1,n) cin >> f[i];
    vector<int> a(n+1);
    for(int i = 2; i < n; i++){
        a[i] = (f[i+1] - 2*f[i] + f[i-1]) / 2;
    }
    int pre = 0;
    for(int i = 1; i <= n; i++){
        pre += a[i] * (i-1);
    }
    // cout << "pre: " << pre << endl;
    a[n] = (f[1] - pre) / (n-1); 
    pre = 0;
    for(int i = 1; i <= n; i++){
        pre += a[i] * (n-i);
    }
    // cout << "pre: " << pre << endl;
    a[1] = (f[n] - pre) / (n-1);
    rep(i,1,n) cout << a[i] << " \n"[i==n];
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
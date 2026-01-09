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
const int N = 2e5 + 5;
// y/x == k^n
// y,x <= 1e9
// O(1)
void solve() {
    int k,l1,r1,l2,r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    int ans = 0,kk = 1;
    // x == y/(k^n)
    // 枚举 n
    // n最小为0，最大估计为r2
    // x == y/(k^n)  当k，n的确定时，x能取到的范围就和y的范围有关，最终得到的范围就是x能取到的范围，加入ans就行
    while(kk <= r2){
        //为了防止所算的范围是负的 与0LL取最大值
        //min(r1,r2/kk) 将计算的范围最大值(向下取整)于x的最大值取最小
        //max((int)ceil(double(l2)/kk),l1)  将计算的范围最小值(向上取整)于x的最小值取最大
        //向上取证是ceil结果是double类型 要转换成->int ceil里面是double类型,要将答案转换成double类型
        ans += max(0ll,min(r1,r2/kk) - max((int)ceil(double(l2)/kk),l1) + 1);
        kk *= k;
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}

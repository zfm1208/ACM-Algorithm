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
    主要考虑 Bob 如何获胜,在 Alice 选择最优策略的情况下,她一定是将 p / q 尽可能远离2 / 3,
    因此 Bob 就只能执行与 Alice 相反的操作,即如果 Alice 选择减小 p ,那 Bob 就一定是选择减少 q,反之亦然.

    因此,我们只需确定对任意合法的 x, (p-x) / (q-x) 是否有可能等于 2 / 3.
    稍微推导一下就会发现这等价于  3(p-x) = 2*(q-x) 
    x = 3p-2q
    由 p > 0 && q > 1可知
    必须 p-x > 0  且 q-x > 1
    x < p && x < q-1
    综上可得  x < min(p,q-1)
    0 <= x <= min(p,q-1)
    判断一下 x 的范围即可
*/
void solve(){
    int p,q; cin >> p >> q;
    int x = 3*p - 2*q;
    if(0 <= x && x <= min(p,q-1)){
        cout << "Bob" << endl;
    }else{
        cout << "Alice" << endl;
    }
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
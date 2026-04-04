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
/*
    给你两个整数x,y, 去构造一棵包含 x+y 个节点的树, 且以1为根

    有x个节点的子树大小为偶数
    有y个节点的子树大小为奇数

    不存在输出 NO

    一个节点子树大小的奇偶性，完全取决于它有几个“奇数子树大小”的孩子节点
    <1> : n 奇数 
    那么除了根节点之外，奇数节点个数是 y-1, 这些剩下的奇数节点要分配给x个偶数节点,
    即 y-1 >= x

    <2> : n 偶数
    根节点本身就是偶数节点。所有的奇数节点都在它下面
    所以奇数节点的数量 y 必须大于等于偶数节点的数量 x。即 y >= x
    此外，既然 n 是偶数，根节点是偶数节点，那偶数节点的数量 x 绝不能是 0
    即 x >= 1


    既然是构造，我们就要找最简单，最容易实现的方法 --- 构造链

*/
void solve(){
    int x,y; cin >> x >> y;
    int n = x + y;
    if(n & 1){
        if(y <= x) {
            cout << "NO" << endl;
            return;
        }
    }else{
        if(x <= 0 || y < x){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    if(n&1){
        int cnt = 2 * x + 1;
        rep(i,1,cnt-1) cout << i << " " << i+1 << endl;
        rep(i,cnt+1,n) cout << 1 << " " << i << endl;
    }else{
        int cnt = 2 * x;
        rep(i,1,cnt-1) cout << i << " " << i+1 << endl;
        rep(i,cnt+1,n) cout << 1 << " " << i << endl;
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
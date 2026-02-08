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
【解题思路与核心切入点】

1. 切入点：寻找操作的"不变量"
   题目要求在 A 和 B 中同时进行交换，且交换距离相等。
   这个距离限制其实是一个"烟雾弹"，重要的是关注"交换"本身的性质。
   我们在代数中知道一个重要结论：
   任意一次交换（无论相邻还是远距离），都会改变排列逆序对数量的奇偶性（即改变排列的奇偶性）。

2. 核心逻辑：相对奇偶性守恒
   因为我们必须同时在 A 和 B 中各执行一次交换，所以：
   - A 的奇偶性翻转一次（0->1 或 1->0）。
   - B 的奇偶性也翻转一次。
   这意味着 A 和 B 的 "相对奇偶性" 永远保持不变。
   如果初始状态下 A 和 B 的奇偶性相同，无论操作多少次它们依然相同；反之则永远无法达成一致。

3. 算法实现：
   (1) 集合一致性检查：首先对 A 和 B 分别排序，如果元素构成不同，直接判 NO。
   (2) 计算置换奇偶性：利用 置换环 的思想。
       - 将数组中的数值离散化（或映射）到它们排序后应该在的目标位置。
       - 构建置换图，找出图中所有的环。
       - 还原数组所需的最小交换次数 = 节点数 N - 环的个数。
   (3) 结论：比较 A 和 B 的最小交换次数的奇偶性。
       如果相同 (ansA % 2 == ansB % 2)，则输出 YES，否则 NO。
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    vector<int> aa = a, bb = b;
    sort(aa.begin()+1,aa.end());
    sort(bb.begin()+1,bb.end());
    if(aa != bb){
        cout << "NO" << endl;
        return;
    }
    auto get = [&] (const vector<int>& arr) -> int {
        vector<pii> b(n+1);
        for(int i = 1; i <= n; i++){
            b[i] = {arr[i],i};
        }
        sort(b.begin()+1, b.end());
        vector<int> p(n+1);
        for(int i = 1; i <= n; i++){
            p[b[i].se] = i;
        }
        vector<int> vis(n+1);
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i]) continue;
            cnt++;
            int u = i;
            while(!vis[u]){
                vis[u] = 1;
                u = p[u];
            }
        }
        int ans = n - cnt;
        return (ans & 1) ? 1 : 0;
    }; 
    cout << (get(a) == get(b) ? "YES" : "NO") << endl;
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
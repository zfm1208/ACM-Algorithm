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
struct Seg{
    int l,r,c,id;
};
struct SegTree {
    struct Node {
        int l, r;
        int sum;
        int lz; 
    };
    vector<Node> tr;
    SegTree(int n){
        tr.resize((n + 5) * 4);
    }
    void pushup(int u){
        tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % mod;
    }
    void pushdown(int u){
        if(tr[u].lz != 1){
            int lz = tr[u].lz;
            int left = u << 1, right = u << 1 | 1;

            tr[left].sum = (tr[left].sum * lz) % mod;
            tr[left].lz = (tr[left].lz * lz) % mod;

            tr[right].sum = (tr[right].sum * lz) % mod;
            tr[right].lz = (tr[right].lz * lz) % mod;

            tr[u].lz = 1;
        }
    }
    void build(int u, int l, int r) {
        tr[u] = {l, r, 0, 1};
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    void change(int u, int pos, int val){
        if(tr[u].l == tr[u].r){
            tr[u].sum = (tr[u].sum + val) % mod;
            return;
        }
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (pos <= mid) change(u << 1, pos, val);
        else change(u << 1 | 1, pos, val);
        pushup(u);
    }

    void update(int u, int l, int r,int val){
        if(l > r) return;
        if(l <= tr[u].l && tr[u].r <= r){
            tr[u].sum = (tr[u].sum * val) % mod;
            tr[u].lz = (tr[u].lz * val) % mod;
            return;
        }
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if(l <= mid) update(u << 1, l, r,val);
        if(r > mid) update(u << 1 | 1, l, r,val);
        pushup(u);
    }

    int query(int u, int l, int r){
        if(l > r) return 0; 
        if(l <= tr[u].l && tr[u].r <= r){
            return tr[u].sum;
        }
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        int res = 0;
        if (l <= mid) res = (res + query(u << 1, l, r)) % mod;
        if (r > mid) res = (res + query(u << 1 | 1, l, r)) % mod;
        return res;
    }
};
/*
    1.题目给你一堆带颜色的线段，让你选一些出来。 
    限制条件只有一个核心矛盾：如果两个线段重叠，它们的颜色必须相同。 
    反过来说就是：不同颜色的线段，绝对不能重叠
    线性规划问题！
    既然是选子集，且后面的选择受前面限制，我们首先想到的通常是 DP

    2.先对线段进行按右端点R排序
    (这样当处理第i条线段时，它前面的线段1~i-1结束时间不会晚于第i条，
    这样就有了一个从左到右的时间轴，可以进行DP)

    3.构思DP
    假设我们要决定第i条线段（比如红色）选还是不选
    如果我选了i,我要保证它和前面已经选的蓝色线段不能重叠
    至于前面的红色线段，倒是无所谓
    so,dp状态必须包含，当前结尾的线段颜色是什么
    dp[红][i]:从前i条里选，且必须选择第i条（红）的方案数
    dp[蓝][i]:从前i条里选，且必须选择第i条（蓝）的方案数

    4.状态转移
    假设当前线段i是红色，左端点Li,我想算出dp[红][i],我可以接在谁的后面？
        A:接在红色后面
        所有 j < i 的红色方案 dp[红][j] 都可以接上 i 吗？
        题目问的是“选择线段的方案数”
        如果我们仅仅是把i接在j后面，那j和i之间的那些线段怎么办？
        会漏情况!
    
    与其纠结上一个是谁，不如维护两个树，
    1.红树：所有以红色线段结尾的合法方案
    2.蓝树：所有以蓝色线段结尾的合法方案

    对于第i条线段（假设红色），范围[Li,Ri]
    它对历史的影响
    1.对于红树里的方案（同色）
    之前的任何一个红色方案，面对线段i，，可以选择 选i和不选i

    2.对于蓝树里的方案（异色）
    我们在所有蓝树的方案中，分成两部分
    * 安全区：结束位置R < Li 的方案，和i不重叠
        我们可以由蓝 -> 红，在方案后面接上i
        dp[红][i] += sum(安全区) 
        也可以无视i，保持原来的蓝色结尾，但对于未来的线段来说，这个蓝色方案权重翻倍了
        因为可以选择 选i和不选i
        sum(安全区) *= 2
    * 冲突区：结束位置R >= Li的方案，和i重叠
        选不了i，至于这一种选择

    1.
    线段树的下标是什么？是线段的坐标吗？
    不是。坐标范围 1e9，开不了这么大的树。
    我们既然已经按 R 排序了，线段树的下标直接用排序后的线段序号 1-N 即可。
    下标k代表：以“排序后第k条线段”结尾的方案数。

    2。
    初始化，空集

    3.循环处理每一条i，先二分，再处理异色/同色树，累加答案即可
*/
void solve(){
    int n; cin >> n;
    vector<Seg> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].l >> a[i].r >> a[i].c;
        a[i].id = i;
    }
    sort(a.begin()+1,a.end(),[](const Seg&x, const Seg&y){
        return x.r < y.r;
    });
    // tree[0]:存红色结尾的方案
    // tree[1]:存蓝色结尾的方案
    SegTree tree0(n+1),tree1(n+1);
    tree0.build(1,0,n);
    tree1.build(1,0,n);
    tree0.change(1, 0, 1);
    tree1.change(1, 0, 1);
    int ans = 1; 
    for(int i = 1; i <= n; i++){
        int l = 0, r = i - 1, pos = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(mid == 0 || a[mid].r < a[i].l){
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        int val;
        if(a[i].c == 0){
            val = tree1.query(1, 0, pos);
            tree0.change(1, i, val);    
            tree1.update(1, 0, pos,2);   
        }else{      
            val = tree0.query(1, 0, pos);
            tree1.change(1, i, val);    
            tree0.update(1, 0, pos,2);   
        }
        ans = (ans + val) % mod;
    }
    cout << ans << endl;
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
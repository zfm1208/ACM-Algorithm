#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
/*
    n,m的网格(初始为A)
    每次把(1,1)到(row,col)的区域涂成c
    问全部操作完之后的网格

    sol:
    倒序处理q： 对于每一个q：
    如果当前格子还没被确定颜色，那就是当前操作的c
    若当前格子被确定了，那它被更晚的操作覆盖过，不用改

    对于每一行，被染色过的肯定是一段前缀
    nxt[i]: 当前行最左边没有确定颜色的列

    若存在 nxt[i] <= col，那 nxt[i] ~ col 都要填c，然后 nxt[i] = col + 1

    为了快速找 1-row 行中有没有 nxt[i] <= col 的行，
    用线段树来维护区间最小值
*/
struct node {
    int row, col;
    char c;
};

// 线段树维护每一行 nxt[i] 的最小值
struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n = 0) { init(n); }
    void init(int _n) {
        n = _n;
        tree.assign(4 * n + 5, 1);
    }
    // 初始时，每一行最左边没有确定颜色的位置都是第 1 列
    void build(int id, int l, int r){
        if(l == r){
            tree[id] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        tree[id] = min(tree[id << 1], tree[id << 1 | 1]);
    }

    // 把第 pos 行的 nxt[pos] 修改为 val
    void update(int id, int l, int r, int pos, int val){
        if(l == r){
            tree[id] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) update(id << 1, l, mid, pos, val);
        else update(id << 1 | 1, mid + 1, r, pos, val);
        tree[id] = min(tree[id << 1], tree[id << 1 | 1]);
    }

    // 在 [ql, qr] 这些行里面，找一个满足 nxt[row] <= val 的 row
    // val 就是当前操作的 col
    int query(int ql, int qr, int val, int id, int l, int r){
        if(qr < l || r < ql) return -1;
        // 当前区间的最小 nxt 都 > val
        // 说明这一整段行都没有可以被当前操作填的格子
        if(tree[id] > val) return -1;
        // 找到具体某一行
        if(l == r) return l;

        int mid = (l + r) >> 1;
        // 先找左边再找右边
        int res = query(ql, qr, val, id << 1, l, mid);
        if(res != -1) return res;

        return query(ql, qr, val, id << 1 | 1, mid + 1, r);
    }
};

void solve(){
    int n, m, q; 
    cin >> n >> m >> q;
    vector<node> a(q + 1);
    for(int i = 1; i <= q; i++){
        cin >> a[i].row >> a[i].col >> a[i].c;
    }
    vector<string> ans(n + 1, string(m + 1, 'A'));
    vii nxt(n + 1, 1);
    SegTree seg(n);
    seg.build(1, 1, n);
    for(int i = q; i >= 1; i--){
        while(1){
            // 找 1 ~ a[i].row 这些行里面，
            // 有没有某一行还存在 nxt[row] <= a[i].col
            int pr = seg.query(1, a[i].row, a[i].col, 1, 1, n);
            if(pr == -1) break;
            // 第 pr 行，从 nxt[pr] 到 a[i].col 都可以确定成当前颜色
            for(int j = nxt[pr]; j <= a[i].col; j++){
                ans[pr][j] = a[i].c;
            }
            nxt[pr] = a[i].col + 1;
            // 更新线段树中第 pr 行的 nxt 值
            seg.update(1, 1, n, pr, nxt[pr]);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
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
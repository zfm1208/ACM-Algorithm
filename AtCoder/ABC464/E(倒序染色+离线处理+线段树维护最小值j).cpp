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
    题目大意：
    给定一个 n * m 的网格，初始所有格子都是字符 'A'。
    有 q 次操作，每次给出 row, col, c，表示把左上角 (1,1)
    到右下角 (row,col) 的矩形全部染成字符 c。
    要求输出所有操作完成后的最终网格。

    *思路：
    如果正序模拟每次染色，会反复覆盖大量格子，复杂度太高。
    注意一个格子的最终颜色只由“最后一次覆盖它的操作”决定，
    所以可以倒序处理所有操作。

    *倒序处理时：
    如果一个格子还没有被确定颜色，那么当前操作就是它最后一次
    覆盖该格子的操作，可以直接赋值；
    如果一个格子已经被确定颜色，说明它被更晚的操作覆盖过，
    当前操作不能再修改它。

    由于每次操作的矩形都是从 (1,1) 开始的前缀矩形，
    对于每一行来说，倒序过程中已经确定颜色的格子一定是一段前缀。
    因此维护 nxt[i]：
    ! nxt[i] 表示第 i 行最左边还没有确定颜色的列。

    对于当前操作 (row, col, c)，只需要在第 1 到 row 行中寻找
    是否存在某一行 i 满足 nxt[i] <= col。
    如果存在，说明这一行从 nxt[i] 到 col 的格子可以被当前操作确定颜色，
    填色后令 nxt[i] = col + 1。
    如果不存在，说明当前操作没有新的格子可以确定。

    ! 为了快速寻找区间 [1,row] 中是否存在 nxt[i] <= col 的行，使用线段树维护 nxt[i] 的区间最小值。
    线段树节点 tree[id] 表示该节点对应行区间内的最小 nxt 值。
    若 tree[id] > col，说明这个区间内所有行的 nxt 都大于 col
    当前操作无法在这些行中填色，可以直接跳过。
    否则继续递归查找一行满足条件的行
    复杂度：
    每个格子最多被填色一次，总填色次数为 n * m
    每次找到一行并更新线段树需要 O(log n)
    总复杂度约为 O(n * m + (n * m + q) log n)
    在 n * m <= 1e6, q <= 2e5 的限制下可以通过
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
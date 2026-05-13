#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 998244353;
const int N = 200005;

// 你的线段树板子（适配了乘法懒标记和单点修改）
struct SegTree {
    struct Node {
        int sum;
        int mul; // 改为乘法标记
    };
    int n;
    vector<Node> tree;

    SegTree() {}
    
    void init(int _n) {
        n = _n;
        tree.assign((n + 1) * 4, {0, 1}); // 初始 sum=0, mul=1
    }

    void push_up(int u) {
        tree[u].sum = (tree[u << 1].sum + tree[u << 1 | 1].sum) % mod;
    }

    void push_down(int u) {
        if (tree[u].mul != 1) { 
            int tag = tree[u].mul;
            
            tree[u << 1].sum = (tree[u << 1].sum * tag) % mod;
            tree[u << 1].mul = (tree[u << 1].mul * tag) % mod;

            tree[u << 1 | 1].sum = (tree[u << 1 | 1].sum * tag) % mod;
            tree[u << 1 | 1].mul = (tree[u << 1 | 1].mul * tag) % mod;

            tree[u].mul = 1; 
        }
    }

    // 完美复刻 AC 代码的“全局乘法”（只改根节点，依靠 push_down 下传）
    void multiply_all(int k) {
        tree[1].sum = (tree[1].sum * k) % mod;
        tree[1].mul = (tree[1].mul * k) % mod;
    }

    // 单点加法
    void modify_add(int u, int l, int r, int pos, int k) {
        if(l == r) {
            tree[u].sum = (tree[u].sum + k) % mod;
            return;
        }
        push_down(u);
        int mid = (l + r) >> 1;
        if (pos <= mid) modify_add(u << 1, l, mid, pos, k);
        else modify_add(u << 1 | 1, mid + 1, r, pos, k);
        push_up(u);
    }

    // 单点查询
    int query_point(int u, int l, int r, int pos) {
        if(l == r) return tree[u].sum;
        push_down(u);
        int mid = (l + r) >> 1;
        if (pos <= mid) return query_point(u << 1, l, mid, pos);
        else return query_point(u << 1 | 1, mid + 1, r, pos);
    }

    // 区间查询（最后用来统计答案）
    int query_sum(int u, int l, int r, int ql, int qr) {
        if (ql > qr) return 0;
        if(l >= ql && qr <= r) return tree[u].sum;
        push_down(u); 
        int mid = (l + r) >> 1;
        int res = 0;
        if (ql <= mid) res = (res + query_sum(u << 1, l, mid, ql, qr)) % mod;
        if (qr > mid) res = (res + query_sum(u << 1 | 1, mid + 1, r, ql, qr)) % mod;
        return res;
    }
};

SegTree T[2]; // T[0] 和 T[1] 两棵树

void solve() {
    int n; cin >> n;
    vector<int> D(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> D[i];
    }

    if (D[n - 1] != 1) {
        cout << 0 << '\n';
        return;
    }

    T[0].init(n);
    T[1].init(n);

    // 初始状态
    T[0].modify_add(1, 1, n, n, 1);
    T[1].modify_add(1, 1, n, n - 1, 1);

    // 完全对照 AC 代码的逻辑和变量名映射
    for (int i = n - 1; i >= 2; i--) {
        int ij = D[i - 1] + (i - 1);
        int d1 = 0;
        if (ij <= n) {
            d1 = (d1 + T[0].query_point(1, 1, n, ij)) % mod;
            d1 = (d1 + T[1].query_point(1, 1, n, ij)) % mod;
        }

        int ij2 = i - 1 + D[i - 1];
        int d2 = 0;
        if (ij2 <= n) {
            d2 = T[0].query_point(1, 1, n, ij2);
        }

        int ij3 = i - 1 + D[i - 1];
        int d3 = 0;
        if (ij3 <= n) {
            d3 = T[1].query_point(1, 1, n, ij3);
        }

        // 全局乘法处理
        if (D[i] == D[i - 1]) {
            T[0].multiply_all(n - i);
            T[1].multiply_all(n - i);
        } else {
            T[0].multiply_all(0);
            T[1].multiply_all(0);
        }

        // 单点累加更新
        if (ij <= n) {
            T[0].modify_add(1, 1, n, ij, d1);
        }
        if (ij2 <= n) {
            T[1].modify_add(1, 1, n, i - 1, d2);
        }
        if (ij3 <= n) {
            T[1].modify_add(1, 1, n, i - 1, d3);
        }
    }

    // 统计总答案
    int ans = 0;
    ans = (ans + T[0].query_sum(1, 1, n, 1, n)) % mod;
    ans = (ans + T[1].query_sum(1, 1, n, 1, n)) % mod;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T_case = 1;
    // cin >> T_case;
    while (T_case--)
        solve();
    return 0;
}
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#define int long long
#define pii pair<int, int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 1e5 + 5;
// 定义线段树节点结构体
struct node {
    int l, r;  // 节点表示的区间 [l, r]
    int val;   // 节点表示的区间的值（区间和）
    int lz;    // 懒标记，用于延迟更新
} tree[N * 4];  // 线段树数组，大小为 N * 4
vector<int> p(N + 5);  // 存储输入的数组
// 构建线段树
void build(int l, int r, int i) {
    tree[i].l = l, tree[i].r = r;  // 设置当前节点的区间
    if (l == r) {  // 如果是叶子节点
        tree[i].val = p[l];  // 节点的值等于数组中的值
        tree[i].lz = 0;  // 懒标记初始化为 0
        return;
    }
    int mid = (l + r) / 2;  // 计算区间的中点
    build(l, mid, i * 2);  // 递归构建左子树
    build(mid + 1, r, i * 2 + 1);  // 递归构建右子树
    tree[i].val = tree[i * 2].val + tree[i * 2 + 1].val;  // 当前节点的值等于左右子树的值之和
}
// 下推懒标记
void push_down(int i) {
    if (tree[i].lz != 0) {  // 如果当前节点有懒标记
        tree[i * 2].lz += tree[i].lz;  // 将懒标记下推到左孩子
        tree[i * 2 + 1].lz += tree[i].lz;  // 将懒标记下推到右孩子
        int mid = (tree[i].l + tree[i].r) / 2;  // 计算区间的中点
        tree[i * 2].val += tree[i].lz * (mid - tree[i * 2].l + 1);  // 更新左孩子的值
        tree[i * 2 + 1].val += tree[i].lz * (tree[i * 2 + 1].r - mid);  // 更新右孩子的值
        tree[i].lz = 0;  // 清空当前节点的懒标记
    }
}
// 区间更新操作
void add(int i, int l, int r, int k) {
    if (l <= tree[i].l && tree[i].r <= r) {  // 如果当前节点区间完全包含在目标区间内
        tree[i].val += k * (tree[i].r - tree[i].l + 1);  // 更新当前节点的值
        tree[i].lz += k;  // 更新懒标记
        return;
    }
    push_down(i);  // 下推懒标记
    if (tree[i * 2].r >= l)  // 如果左孩子与目标区间有交集
        add(i * 2, l, r, k);  // 递归更新左孩子
    if (tree[i * 2 + 1].l <= r)  // 如果右孩子与目标区间有交集
        add(i * 2 + 1, l, r, k);  // 递归更新右孩子
    tree[i].val = tree[i * 2].val + tree[i * 2 + 1].val;  // 更新当前节点的值
    return;
}
// 区间查询操作
int search(int i, int l, int r) {
    if (l <= tree[i].l && tree[i].r <= r) {  // 如果当前节点区间完全包含在目标区间内
        return tree[i].val;  // 返回当前节点的值
    }
    if (tree[i].r < l || tree[i].l > r)  // 如果当前节点区间与目标区间无交集
        return 0;  // 返回 0
    push_down(i);  // 下推懒标记
    int ans = 0;
    if (l <= tree[i * 2].r)  // 如果左孩子与目标区间有交集
        ans += search(i * 2, l, r);  // 递归查询左孩子
    if (r >= tree[i * 2 + 1].l)  // 如果右孩子与目标区间有交集
        ans += search(i * 2 + 1, l, r);  // 递归查询右孩子
    return ans;  // 返回查询结果
}
// 主逻辑函数
void solve() {
    int n, q;
    cin >> n >> q;  // 输入数组大小 n 和操作数量 q
    for (int i = 1; i <= n; i++) cin >> p[i];  // 输入数组元素
    build(1, n, 1);  // 构建线段树
    while (q--) {
        char c;
        cin >> c;  // 输入操作类型
        if (c == 'C') {  // 如果是区间更新操作
            int l, r, x;
            cin >> l >> r >> x;  // 输入区间 [l, r] 和要加的值 x
            add(1, l, r, x);  // 调用区间更新函数
        } else if (c == 'Q') {  // 如果是区间查询操作
            int l, r;
            cin >> l >> r;  // 输入区间 [l, r]
            cout << search(1, l, r) << endl;  // 调用区间查询函数并输出结果
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);  // 关闭同步流，提高输入输出效率
    cin.tie(0), cout.tie(0);  // 解除 cin 和 cout 的绑定
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#define int long long  // 定义 int 为 long long 类型，方便处理大整数
#define pii pair<int, int>  // 定义 pii 为 pair<int, int>
#define endl '\n'  // 定义 endl 为换行符
using namespace std;

const int mod1 = 1e9 + 7;  // 定义模数 1
const int mod2 = 998244353;  // 定义模数 2
const int inf = 1e18;  // 定义无穷大
const int N = 1e5 + 5;  // 定义数组最大大小

// 定义线段树节点结构体
struct node {
    int l, r;  // 节点表示的区间 [l, r]
    int val;   // 节点表示的区间的值（区间乘积）
} tree[N * 4];  // 线段树数组，大小为 N * 4

int Q, MOD;  // Q 表示操作次数，MOD 表示模数

// 构建线段树
void build(int l, int r, int i) {
    tree[i].l = l, tree[i].r = r;  // 设置当前节点的区间
    if (l == r) {  // 如果是叶子节点
        tree[i].val = 1;  // 初始值为 1
        return;
    }
    int mid = (l + r) / 2;  // 计算区间的中点
    build(l, mid, i * 2);  // 递归构建左子树
    build(mid + 1, r, i * 2 + 1);  // 递归构建右子树
    tree[i].val = (tree[i * 2].val * tree[i * 2 + 1].val) % MOD;  // 当前节点的值等于左右子树的值之积
}

// 更新线段树中的某个位置的值
void debate(int i, int l, int r, int k) {
    if (l <= tree[i].l && r >= tree[i].r) {  // 如果当前节点区间完全包含在目标区间内
        tree[i].val = k;  // 更新当前节点的值
    } else if (tree[i].l > r || l > tree[i].r) {  // 如果当前节点区间与目标区间无交集
        return;  // 直接返回
    } else {  // 如果当前节点区间与目标区间部分重叠
        debate(i * 2, l, r, k);  // 递归更新左孩子
        debate(i * 2 + 1, l, r, k);  // 递归更新右孩子
        tree[i].val = (tree[i * 2].val * tree[i * 2 + 1].val) % MOD;  // 更新当前节点的值
    }
}

// 主逻辑函数
void solve() {
    cin >> Q >> MOD;  // 输入操作次数 Q 和模数 MOD
    build(1, Q, 1);  // 构建线段树，初始值为 1
    for (int i = 1; i <= Q; i++) {  // 处理每个操作
        int op, m;
        cin >> op;  // 输入操作类型
        if (op == 1) {  // 如果是操作类型 1
            cin >> m;  // 输入要乘的数 m
            debate(1, i, i, m);  // 更新第 i 个位置的值为 m
            cout << tree[1].val << endl;  // 输出当前全局乘积的值
        } else {  // 如果是操作类型 2
            cin >> m;  // 输入要撤销的操作位置 m
            debate(1, m, m, 1);  // 将第 m 个位置的值重置为 1
            cout << tree[1].val << endl;  // 输出当前全局乘积的值
        }
    }
}

// 主函数
signed main() {
    ios::sync_with_stdio(false);  // 关闭同步流，提高输入输出效率
    cin.tie(0), cout.tie(0);  // 解除 cin 和 cout 的绑定
    int T = 1;
    cin >> T;  // 输入测试用例数量
    while (T--) solve();  // 处理每个测试用例
    return 0;
}
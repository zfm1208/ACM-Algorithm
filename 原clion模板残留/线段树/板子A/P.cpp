#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#define int long long
#define pii pair<int, int>
#define endl '\n'
using namespace std;
const int N = 1e5 + 5;
struct node {
    int l, r;
    int val;
    int lz_1;// +
    int lz_2;// *
} tree[N * 4];
vector<int> p(N + 5);
int mod;
//建树
void build(int l, int r, int i){
    tree[i].l = l,tree[i].r = r;
    tree[i].lz_1 = 0,tree[i].lz_2 = 1;
    if(l == r){
        tree[i].val = p[l] % mod;
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, i * 2);
    build(mid + 1, r, i * 2 + 1);
    tree[i].val = (tree[i * 2].val + tree[i * 2 + 1].val) % mod;
}
//下传
void push_down(int i){
    int l = i * 2, r = i * 2 + 1;
    // 先乘除再加减
    if(tree[i].lz_2 != 1){
        tree[l].val = (tree[l].val * tree[i].lz_2) % mod;
        tree[r].val = (tree[r].val * tree[i].lz_2) % mod;
        tree[l].lz_2 = (tree[l].lz_2 * tree[i].lz_2) % mod;
        tree[r].lz_2 = (tree[r].lz_2 * tree[i].lz_2) % mod;
        tree[l].lz_1 = (tree[l].lz_1 * tree[i].lz_2) % mod;
        tree[r].lz_1 = (tree[r].lz_1 * tree[i].lz_2) % mod;
        tree[i].lz_2 = 1;
    }
    if(tree[i].lz_1 != 0){
        tree[l].val = (tree[l].val + tree[i].lz_1 * (tree[l].r - tree[l].l + 1)) % mod;
        tree[r].val = (tree[r].val + tree[i].lz_1 * (tree[r].r - tree[r].l + 1)) % mod;
        tree[l].lz_1 = (tree[l].lz_1 + tree[i].lz_1) % mod;
        tree[r].lz_1 = (tree[r].lz_1 + tree[i].lz_1) % mod;
        tree[i].lz_1 = 0;
    }

}
//加法
void add(int i, int l, int r, int k){
    if(l <= tree[i].l && tree[i].r <= r){
//        tree[i].val += k * (tree[i].r - tree[i].l + 1) % mod;
        tree[i].val = (tree[i].val + k * (tree[i].r - tree[i].l + 1)) % mod;
//        tree[i].lz_1 += k % mod;
        tree[i].lz_1 = (tree[i].lz_1 + k) % mod;
        return;
    }
    push_down(i);
    if(tree[i * 2].r >= l) add(i * 2, l, r, k);
    if(tree[i * 2 + 1].l <= r) add(i * 2 + 1, l, r, k);
    tree[i].val = (tree[i * 2].val + tree[i * 2 + 1].val) % mod;
}

//乘法
void add1(int i, int l, int r, int k){
    if(l <= tree[i].l && tree[i].r <= r) {
        tree[i].val = (tree[i].val * k) % mod;
        tree[i].lz_2 = (tree[i].lz_2 * k) % mod;
        tree[i].lz_1 = (tree[i].lz_1 * k) % mod;
        return;
    }
    push_down(i);
    if(tree[i * 2].r >= l) add1(i * 2, l, r, k);
    if(tree[i * 2 + 1].l <= r) add1(i * 2 + 1, l, r, k);
    tree[i].val = (tree[i * 2].val + tree[i * 2 + 1].val) % mod;
}
//查询
int search(int i, int l, int r){
    if(l <= tree[i].l && tree[i].r <= r){
        return tree[i].val;
    }
    if(tree[i].r < l || tree[i].l > r) {
        return 0;
    }
    push_down(i);
    int ans = 0;
    if(tree[i * 2].r >= l)
        ans = (ans + search(i * 2, l, r)) % mod;
    if(tree[i * 2 + 1].l <= r)
        ans = (ans + search(i * 2 + 1, l, r)) % mod;
    return ans;
}
void solve(){
    int n, q;cin >> n >> q >> mod;
    for (int i = 1; i <= n; i++) cin >> p[i];
    build(1, n, 1);
    while (q--){
        int op;
        cin >> op;
        if(op == 1){
            int l, r, k;
            cin >> l >> r >> k;
            add1(1, l, r, k);
        }else if(op == 2){
            int l, r, k;
            cin >> l >> r >> k;
            add(1, l, r, k);
        }else if (op == 3){
            int l, r;
            cin >> l >> r;
            cout << search(1, l, r) << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--) solve();
    return 0;
}
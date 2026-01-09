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
struct node {
    int l, r, val, lz;
} tree[N * 4];
vector<int> p(N+5);
// 构建线段树
void build(int l, int r, int i){
    tree[i].l = l, tree[i].r = r;
    if(l == r){
        tree[i].val = p[l];
        tree[i].lz = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, i * 2);
    build(mid + 1, r, i * 2 + 1);
    tree[i].val = tree[i * 2].val + tree[i * 2 + 1].val;
}
void push_down(int i){
    if(tree[i].lz != 0){
        tree[i * 2].lz += tree[i].lz;
        tree[i * 2 + 1].lz += tree[i].lz;
        int mid = (tree[i].l + tree[i].r) / 2;
        tree[i * 2].val += tree[i].lz * (mid - tree[i * 2].l + 1);
        tree[i * 2 + 1].val += tree[i].lz * (tree[i * 2 + 1].r - mid);
        tree[i].lz = 0;
    }
}
void add(int i, int l, int r, int k){
    if(l <= tree[i].l && tree[i].r <= r){
        tree[i].val += k * (tree[i].r - tree[i].l + 1);
        tree[i].lz += k;
        return;
    }
    push_down(i);
    if(tree[i * 2].r >= l)
        add(i * 2, l, r, k);
    if(tree[i * 2 + 1].l <= r)
        add(i * 2 + 1, l, r, k);
    tree[i].val = tree[i * 2].val + tree[i * 2 + 1].val;
    return;
}
int search(int i, int l, int r){
    if(l <= tree[i].l && tree[i].r <= r){
        return tree[i].val;
    }
    if(tree[i].r < l || tree[i].l > r) return 0;
    push_down(i);
    int ans = 0;
    if(l <= tree[i * 2].r) ans += search(i * 2, l, r);
    if(r >= tree[i * 2 + 1].l) ans += search(i * 2 + 1, l, r);
    return ans;
}
void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> p[i];
    build(1, n, 1);
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int l, r, x;
            cin >> l >> r >> x;
            add(1, l, r, x);
        }else if(op == 2){
            int l, r; cin >> l >> r;
            cout << search(1, l, r) << endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //    cin >> T;
    while (T--) solve();
    return 0;
}
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
const int N = 5e4 + 5;
struct node{
    int l, r, val;
} tree[N*4];
vector<int> p(N);
// 区间查询
int query(int l, int r, int i){
    if(l <= tree[i].l && tree[i].r <= r){
        return tree[i].val;
    }
    int res = 0;
    int mid = (tree[i].l + tree[i].r) / 2;
    if(l <= mid){
        res += query(l, r, i * 2);
    }
    if(r > mid) {
        res += query(l, r, i * 2 + 1);
    }
    return res;
}
// 单点修改
void update(int i, int ar, int k) {
    if (tree[i].l == tree[i].r) {
        tree[i].val += k;
        return;
    }
    int mid = (tree[i].l + tree[i].r) / 2;
    if(ar <= mid){
        update(i * 2, ar, k);
    } else {
        update(i * 2 + 1, ar, k);
    }
    tree[i].val = tree[i * 2].val + tree[i * 2 + 1].val;
}
// 构建线段树
void build(int l, int r, int id){
    tree[id].l = l;
    tree[id].r = r;
    if (l == r) {
        tree[id].val = p[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, id * 2);
    build(mid + 1, r, id * 2 + 1);
    tree[id].val = tree[id * 2].val + tree[id * 2 + 1].val;
}
int cnt = 1;
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    build(1, n, 1);
    string s;
    cout << "Case " << cnt << ":" << endl;
    while(cin >> s){
        if (s == "End") break;
        int i, j;
        cin >> i >> j;
        if(s == "Sub"){
            update(1, i, -j);
        }if(s == "Add"){
            update(1, i, j);
        }if(s == "Query"){
            cout << query(i, j, 1) << endl;
        }
    }
    cnt++;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
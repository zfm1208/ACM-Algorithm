#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define fi first
#define se second
const int N = 2e5+10,mod = 1e9+7;
int n,q;
int a[N],s[N];
struct SegTree {
    struct node{
        int l,r;
        int sum;
        int cnt;
        int lz; // 多次区间修改，懒标记
    };
    vector<node> tree;
    SegTree (int n){
        tree.resize(N << 2 | 1);
    }
    void push_down(int i){
        if(tree[i].lz > 0){
            tree[i << 1].lz += tree[i].lz;
            tree[i << 1 | 1].lz += tree[i].lz;
            tree[i << 1].sum += tree[i << 1].cnt * tree[i].lz;
            tree[i << 1 | 1].sum += tree[i << 1 | 1].cnt * tree[i].lz;
            tree[i].lz = 0;
        }
    }
    void build(int i, int l, int r){
        tree[i].l = l,tree[i].r = r;
        tree[i].sum = tree[i].cnt = tree[i].lz = 0;
        if(l == r){
            tree[i].sum = a[l];
            tree[i].cnt = s[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
        tree[i].sum = tree[i << 1].sum + tree[i << 1 | 1].sum;
        tree[i].cnt = tree[i << 1].cnt + tree[i << 1 | 1].cnt;
    }
    void update1(int i, int pos){
        if(tree[i].l == tree[i].r){
            tree[i].cnt = 0;
            return;
        }
        int mid = (tree[i].l + tree[i].r) >> 1;
        push_down(i);
        if(pos <= mid) update1(i << 1,pos);
        else update1(i << 1 | 1, pos);
        tree[i].sum = tree[i << 1].sum + tree[i << 1 | 1].sum;
        tree[i].cnt = tree[i << 1].cnt + tree[i << 1 | 1].cnt;
    }
    void update2(int i, int pos){
        if(tree[i].l == tree[i].r){
            tree[i].cnt = 1;
            return;
        }
        int mid = (tree[i].l + tree[i].r) >> 1;
        push_down(i);
        if(pos <= mid) update2(i << 1,pos);
        else update2(i << 1 | 1, pos);
        tree[i].sum = tree[i << 1].sum + tree[i << 1 | 1].sum;
        tree[i].cnt = tree[i << 1].cnt + tree[i << 1 | 1].cnt;
    }
    void update(int i, int l, int r, int val){
        if(l <= tree[i].l && tree[i].r <= r){
            tree[i].sum += tree[i].cnt * val;
            tree[i].lz += val;
            return;
        }
        push_down(i);
        int mid = (tree[i].l + tree[i].r) >> 1;
        if(l <= mid){ // 往左边找
            update(i << 1, l, r, val);
        }
        if(r > mid){
            update(i << 1 | 1, l, r, val);
        }
        tree[i].sum = tree[i << 1].sum + tree[i << 1 | 1].sum;
        tree[i].cnt = tree[i << 1].cnt + tree[i << 1 | 1].cnt;        
    }
    int query(int i, int l, int r){
        if(l <= tree[i].l && tree[i].r <= r){
            return tree[i].sum;
        }
        int ans = 0;
        int mid = (tree[i].l + tree[i].r) >> 1;
        push_down(i);
        if(l <= mid){ // 往左边找
            ans += query(i << 1, l, r);
        }
        if(r > mid){
            ans += query(i << 1 | 1, l, r);
        }
        return ans;
    }
};

void solve(){
    cin >> n >> q;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> s[i];
    SegTree st(n);
    st.build(1,1,n);
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int x; cin >> x;
            st.update1(1,x);
        }else if(op == 2){
            int x; cin >> x;
            st.update2(1,x);
        }else if(op == 3){
            int l,r,x; cin >> l >> r >> x;
            st.update(1,l,r,x);
        }else{
            int l,r; cin >> l >> r;
            cout << st.query(1,l,r) << endl;;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
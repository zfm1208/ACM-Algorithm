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
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
/*
    有题意可知这是一个满二叉树，还有区间异或和，单点修改 -> 线段树
    我们要考虑这一个叶子节点到根节点的那条路径
    他的比较对象是兄弟节点，看情况是否累加对方的"栈大小"
    记得修改完值查询后再改回去
*/
struct SegTree {
    vector<int> tree;
    SegTree(int n){
        tree.resize(n << 2 | 1);
    }
    void build(int i, int l, int r, const vector<int>&a){
        if(l == r) {
            tree[i] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(i << 1, l, mid, a);
        build(i << 1 | 1, mid + 1, r, a);
        tree[i] = tree[i << 1] ^ tree[i << 1 | 1];
    }
    void update(int i, int l, int r, int pos, int val){
        if(l == r){
            tree[i] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid){
            update(i << 1, l, mid, pos, val);
        }else update(i << 1 | 1, mid + 1, r, pos, val);
        tree[i] = tree[i << 1] ^ tree[i << 1 | 1];
    }
    int query(int i, int l, int r, int pos){
        if(l == r) return 0;
        int mid = (l + r) >> 1;
        // x 是左子树
        if(pos <= mid){ 
            if(tree[i << 1 | 1] > tree[i << 1]){
                return query(i << 1, l, mid, pos) + (r - mid);
            }else{
                return query(i << 1, l, mid, pos);
            }
        }else{ // x是右子树
            if(tree[i << 1] >= tree[i << 1 | 1]){
                return query(i << 1 | 1, mid + 1, r, pos) + (mid - l + 1);
            }else{
                return query(i << 1 | 1, mid + 1, r, pos);
            }
        }
    }
};
void solve(){
    int n,q; cin >> n >> q;
    int N = 1 << n;
    vector<int> a(N + 1);
    rep(i,1,N) cin >> a[i];
    SegTree st(N);
    st.build(1,1,N,a);
    while(q--){
        int b,c; cin >> b >> c;
        int temp = a[b];
        st.update(1,1,N,b,c);
        cout << st.query(1,1,N,b) << endl;
        st.update(1,1,N,b,temp);
    }
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
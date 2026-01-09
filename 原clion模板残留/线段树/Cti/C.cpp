#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
int p[N];
struct node{
    int l,r,val;
}tree[N*4];
void build(int l ,int r, int i){
    tree[i].l = l;
    tree[i].r = r;
    if(l == r){
        tree[i].val = p[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(l,mid,i * 2);
    build(mid + 1,r,i * 2 + 1);
    tree[i].val = max(tree[i * 2].val , tree[i * 2 + 1].val);
}
void update(int i,int x,int k){
    if(tree[i].l == tree[i].r){
        tree[i].val = k;
        return ;
    }
    int mid = (tree[i].l + tree[i].r) >> 1;
    if(x <= mid){
        update(i * 2,x,k);
    }else{
        update(i * 2 + 1,x,k);
    }
    tree[i].val = max(tree[i * 2].val , tree[i * 2 + 1].val);
}
int query(int i,int l ,int r){
    if(l <= tree[i].l && tree[i].r <= r){
        return tree[i].val;
    }
    int mid = (tree[i].l + tree[i].r) >> 1;
    int ans = -inf;
    if(l <= mid)  ans = max(ans,query(i * 2,l,r));
    if(r > mid)  ans = max(ans,query(i * 2 + 1,l,r));
    return ans;
}
void solve() {
    int n,m;
    while(cin >> n >> m){
        for(int i = 1; i <= n; i++){
            cin >> p[i];
        }
        build(1,n,1);
        while(m--){
            char c;cin >> c;
            if(c == 'Q'){
                int l,r; cin >> l >> r;
                cout << query(1,l,r) << endl;
            }else{
                int x,k; cin >> x >> k;
                update(1,x,k);
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--) solve();
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 1e5 + 5;
struct node{
    int l,r,val;
}tree[N*4];
vector<int> p(N);
void build(int l,int r, int i){
    tree[i].l = l;
    tree[i].r = r;
    if(l == r){
        tree[i].val = p[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,i * 2);
    build(mid + 1,r,i * 2 + 1);
    tree[i].val = tree[i * 2].val + tree[i * 2 + 1].val;
}
void update(int i,int pos,int k){
    if(tree[i].l == tree[i].r){
        tree[i].val += k;
        return;
    }
    int mid = (tree[i].l + tree[i].r) >> 1;
    if(pos <= mid){
        update(i * 2,pos,k);
    }else{
        update(i * 2 + 1,pos,k);
    }
    tree[i].val = tree[i * 2].val + tree[i * 2 + 1].val;
}
int query(int i,int l ,int r){
    if(l <= tree[i].l && tree[i].r <= r){
        return tree[i].val;
    }
    int ans = 0;
    int mid = (tree[i].l + tree[i].r) >> 1;
    if(l <= mid){
        ans += query(i * 2,l,r);
    }if(r > mid){
        ans += query(i * 2 + 1,l,r);
    }
    return ans;
}

void solve() {
    int n,m; cin >> n >> m;
    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b;

    }
    while(m--){
        int x,y,z; cin >> x >> y >> z;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}

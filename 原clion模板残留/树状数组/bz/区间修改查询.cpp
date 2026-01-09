#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
int n,a[N],b1[N],b2[N];
int lowbit(int x){
    return x & -x;
}
void add(int x,int k){
    int i = x;
    while(x <= n){
        b1[x] += k;
        b2[x] += k * i;
        x += lowbit(x);
    }
}
int query(int x){
    int ans1 = 0,ans2 = 0,m = x;
    while(x){
        ans1 += b1[x] * (m + 1);
        ans2 += b2[x];
        x -= lowbit(x);
    }
    return ans1 - ans2;
}
void solve() {
    int q; cin >> n >> q;
    for(int x = 1; x <= n; x++){
        cin >> a[x];
        add(x,a[x] - a[x-1]); // 用a[x] 的差分数组来建树
    }
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int l,r,x; cin >> l >> r >> x;
            add(l,x);
            add(r + 1, -x); //区间修改
        }else{
            int l,r; cin >> l >> r;
            cout << query(r) - query(l - 1) << endl;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}

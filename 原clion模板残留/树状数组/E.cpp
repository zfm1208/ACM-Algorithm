#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
int n,q;
int a[N],b1[N],b2[N];
void add(int x,int k){
    int i = x;
    while(x <= n){
        b1[x] += k;
        b2[x] += k * i;
        x += x & (-x);
    }
}
int query(int x){
    int ans1 = 0,ans2 = 0;
    int i = x;
    while(x){
        ans1 += (i+1) * b1[x];
        ans2 += b2[x];
        x -= x & (-x);
    }
    return ans1 - ans2;
}
void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        add(i, a[i] - a[i-1]);
    }
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int l,r,x;cin >> l >> r >> x;
            add(l, x);
            add(r + 1, -x);
        }else if(op == 2){
            int k;cin >> k;
            add(1, k);
            add(2, -k);
        }else if (op == 3){
            int k; cin >> k;
            add(1, -k);
            add(2, k);
        }else if (op == 4){
            int l,r; cin >> l >> r;
            cout << query(r) - query(l - 1) << endl;
        }else if (op == 5){
            cout << query(1) - query(0) << endl;
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

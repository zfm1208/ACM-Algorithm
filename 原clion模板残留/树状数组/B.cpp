#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 5e5 + 5;
int n,m;
int a[N],b[N],t[N];
int lowbit(int x){
    return x & (-x);
}
void add(int x,int k){
    while(x <= n){t[x] += k;x += lowbit(x);}
}
int query(int x){
    int sum = 0;
    while(x){
        sum += t[x];
        x -= lowbit(x);
    }
    return sum;
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i] - a[i-1];
        add(i,b[i]);
    }
    while(m--){
        int op; cin >> op;
        if(op == 1){
            int l,r,k; cin >> l >> r >> k;
            add(l,k), add(r + 1,-k);
        }else{
            int x; cin >> x;
            cout << query(x) << endl;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}

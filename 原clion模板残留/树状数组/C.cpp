#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 1e7 + 5;
int n,q,a[N];
void add(int x,int k){
    for(; x <= n; x += x & -x){
        a[x] += k;
    }
}
int query(int x){
    int ans = 0;
    for(; x; x -= x & -x){
        ans += a[x];
    }
    return ans;
}
void solve() {
    cin >> n >> q;
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int x; cin >> x;
            cout << query(x) << endl;
        }else{
            int l,r; cin >> l >> r;
            add(l,1);
            add(r + 1, -1);
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}

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
int t[N];
void add(int x,int k){
    for(;x <= n; x += x & -x){
        t[x] += k;
    }
}
int query(int x){
    int ans = 0;
    for(;x;x -= x & -x){
        ans += t[x];
    }
    return ans;
}
void solve() {
    cin >> n >> q;
    vector<int> a(n+5,0);
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int l,r;cin >> l >> r;
            add(l,1);
            add(r+1,1);
        }else{
            int x; cin >> x;
            cout << query(x)%2 << endl;
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

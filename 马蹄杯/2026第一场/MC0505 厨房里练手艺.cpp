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

void solve(){
    int n,q; cin >> n >> q;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int l,r,x; cin >> l >> r >> x;
            for(int i = l; i <= r; i++) a[i] += x;
        }else if(op == 2){
            int l,r,x; cin >> l >> r >> x;
            rep(i,l,r) if(a[i] > x) a[i] = x;
        }else{
            int l,r; cin >> l >> r;
            int sum = 0;
            rep(i,l,r) sum += a[i];
            cout << sum << endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}
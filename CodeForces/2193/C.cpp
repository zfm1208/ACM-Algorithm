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

void solve(){
    int n,q; cin >> n >> q;
    vector<int> a(n+1),b(n+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    vector<int> ans(n+1);
    rep(i,1,n) ans[i] = max(a[i],b[i]);
    vector<int> suf(n+2);
    for(int i = n; i >= 1; i--){
        suf[i] = max(suf[i+1],ans[i]);
    }
    vector<int> pre(n+1);
    rep(i,1,n) pre[i] = pre[i-1] + suf[i];
    while(q--){
        int l,r; cin >> l >> r;
        cout << pre[r] - pre[l-1] << " ";
    }
    cout << endl;
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
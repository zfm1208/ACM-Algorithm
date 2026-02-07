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
    int n; cin >> n;
    vector<int> a(n+1),b(n+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    int ans = 0;
    sort(a.begin()+1,a.end(),[](int x, int y){
        return x > y;
    });
    vector<int> pre(n+1);
    rep(i,1,n) pre[i] = pre[i-1] + b[i];
    for(int i = 1; i <= n; i++){
        int id = upper_bound(pre.begin()+1,pre.end(),i) - pre.begin();
        ans = max(ans, --id * a[i]);
    }
    cout << ans << endl;
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
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
//  时限 6s
void solve(){
    int n,q; cin >> n >> q;
    vector<int> a(n+1),pre(n+1),cnt(n+1),b(n+1);
    map<int,vector<int>> mmp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        int x = b[i] = a[i];
        int cn = 0;
        while(x){
            cn++;
            x /= 2;
        }
        cnt[i] = cn;
        pre[i] = pre[i-1] + cn;
        if(a[i]) a[i] = 1 << (cn - 1);
        if(b[i] > a[i]) mmp[cn - 1].push_back(b[i]);
        // cout << a[i] << " ";
    }
    while(q--){
        int l,r,k; cin >> l >> r >> k;
        int sum = pre[r] - pre[l-1];
        if(sum <= k){
            cout << 0 << endl;
        }else{

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

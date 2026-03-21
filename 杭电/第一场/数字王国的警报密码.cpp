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
struct DSU {
    vector<int> fa;
    DSU(int n) {
        fa.resize(n+1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x){
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    
    void link(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx != fy){
            fa[fx] = fy;
        }
    }
};

void solve(){
    int n,k; cin >> n >> k;
    if(k == 1 || n >= k) {
        cout << -1 << endl;
        return;
    }
    int l = 1, r = n;
    int pos = 1;
    // cout << "debug: !!!!!" << endl;
    // return;
    while(l <= r){
        int mid = (l + r) / 2;
        if(mid * (mid + 1) / 2 < k){
            pos = mid;
            l = mid + 1;
        }else r = mid - 1;
    }  
    // cout << pos << endl;
    // return;
    if(n <= pos){
        // cout << "n<=pos" << endl;
        for(int i = 1; i <= n; i++){
            cout << i << " \n"[i==n];
        }
    }else{
        DSU dsu(k);
        vector<int> ans(n+1),pre(n+1);
        // (pre[i-1] + x - pre[j]) % k == 0
        // (pre[i-1] + x) % k == pre[j] % k
        dsu.fa[0] = 1;
        for(int i = 1; i <= n; i++){
            int x = ans[i] = ans[i-1] + 1;
            int op = (pre[i-1] + x) % k;
            // cout << "op: " << op << endl;
            int res = dsu.find(op);
            // cout << "res: " << res << endl;
            ans[i] += (res - op + k) % k;
            pre[i] = (pre[i-1] + ans[i]) % k;
            dsu.fa[res] = dsu.find((res+1) % k);
            // for(int j = 0; j < k; j++){
            //     cout << j << ": " << dsu.fa[j] << "  ";
            // }
            // cout << endl;
        }
        rep(i,1,n) cout << ans[i] << " \n"[i==n];
    }
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
/*
    5 7
    1 2 3 5 8 11


*/
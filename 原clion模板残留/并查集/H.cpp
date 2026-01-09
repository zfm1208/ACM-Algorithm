#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 1e5 + 5;
int pre[N], ans[N], a[N];
int find(int x){
    if(pre[x] == x) return x;
    else return pre[x] = find(pre[x]);
}
void unite(int x, int y){
    int rootx = find(x);
    int rooty = find(y);
    if (rootx == rooty) return;
    pre[rooty] = rootx;
    ans[rootx] += ans[rooty];
}
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        pre[i] = i;
        ans[i] = a[i];
    }
    while(m--){
        int pos;cin >> pos;
        if(pos == 1){
            int u, v;
            cin >> u >> v;
            unite(u, v);
        }else if(pos == 2){
            int u;
            cin >> u;
            cout << ans[find(u)] << endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
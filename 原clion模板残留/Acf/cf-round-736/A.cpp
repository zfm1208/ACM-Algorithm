//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
void solve() {
    // 没有朋友时 不会死
    // 权值比直接朋友都大时 不会死
    // 朋友团体最后只能活一个 权值最大的
    int n,m; cin >> n >> m;
    vector<int> frind(n+1); // frind[i] 代表 i 的朋友数目
    int ans = n;
    while(m--){
        int u,v; cin >> u >> v;
        if(u>v)swap(u,v);
        if(frind[u] == 0) ans--; // 1. u和v结盟，权值小的人必死
        frind[u]++;// 2. u的朋友++
    }
    int q; cin >> q;
    while(q--){
        int op,u,v;cin >> op;
        if(op == 1){
            cin >> u >> v;
            if(u>v) swap(u,v);
            if(frind[u] == 0) ans--;
            frind[u]++;
        }
        if(op == 2){
            cin >> u >> v;
            if(u>v) swap(u,v);
            frind[u]--;
            if(frind[u] == 0) ans++;
        }
        if(op == 3){
            cout << ans << endl;
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
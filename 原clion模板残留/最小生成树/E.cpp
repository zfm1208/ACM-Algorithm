//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 350 * 350;
struct node {
    int u,v,w;
}a[N];
int pre[350];
int find(int x){
    if(pre[x] == x) return x;
    else return pre[x] = find(pre[x]);
}
void solve() {
    int n,m; cin >> n >> m;
    for(int i = 1; i <= n; i++) pre[i] = i;
    for(int i = 1; i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        a[i] = {u,v,w};
    }
    sort(a + 1, a + 1 + m,[](node x,node y){
        return x.w < y.w;
    });
    int mx = -inf;
    for(int i = 1; i <= m; i++){
        if(find(a[i].u) != find(a[i].v)){
            pre[find(a[i].u)] = find(a[i].v);
            mx = max(mx,a[i].w);
        }
    }
    cout << n-1 << " " << mx << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}

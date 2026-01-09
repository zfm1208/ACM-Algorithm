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
const int N = 2e5 + 5;
struct node{
    int u,v,w;
}a[N];
int n,m;
int pre[N];
int find(int x){
    if(x == pre[x]) return x;
    return pre[x] = find(pre[x]);
}
bool cmp(node x,node y){
    return x.w < y.w;
}
void solve() {
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        a[i] = {u,v,w};
    }
    sort(a + 1, a + 1 + m, cmp);
    for(int i = 1;i <= n;i++) pre[i] = i;
    int ans = 0;
    int cnt = 0;
    bool p = false;
    for(int i = 1;i <= m;i++){
        int u = find(a[i].u), v = find(a[i].v);
        if(u != v){
            pre[u] = v;
            ans += a[i].w;
            cnt++;
            if(cnt == n - 1) {
                p = true;
                break;
            }
        }
    }
    if(p) cout << ans << endl;
    else cout << "orz" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}

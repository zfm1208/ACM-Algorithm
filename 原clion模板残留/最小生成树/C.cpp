#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
int pre[N], mp[505][505];
struct node {
    int u, v, w;
}a[N];
int find(int x) {
    if(pre[x] == x) return x;
    return pre[x] = find(pre[x]);
}
void unions(int x, int y){
    if(find(x) != find(y))
        pre[find(x)] = find(y);
}
bool cmp(node x, node y) {
    return x.w < y.w;
}
void solve() {
    int x,n; cin >> x >> n;
    for(int i = 1; i <= n; i++){
        pre[i] = i;
        for(int j = 1; j <= n; j++){
            cin >> mp[i][j];
        }
    }
    int cnt = 0;
    // 将优惠价格存储为边
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++)
        {
            if(mp[i][j] != 0){
                cnt++;
                a[cnt] = {i,j,mp[i][j]};
            }
        }
    }
    // 将初始价格存储为边（从虚拟节点 0 到每个节点）
    for(int i = 1; i <= n; i++){
        cnt++;
        a[cnt] = {0,i,x};
    }
    sort(a + 1, a + cnt + 1, cmp);
    int ans = 0;
    int k = 0;
    for(int i = 1; i <= cnt; i++){
        int x = a[i].u, y = a[i].v, w = a[i].w;
        if(k >= n) break;
        if(find(x) != find(y)){
            k++;
            ans += w;
            unions(x, y);
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}

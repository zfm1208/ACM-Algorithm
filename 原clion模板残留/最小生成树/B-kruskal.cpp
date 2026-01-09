#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
int n, m, pre[N];
struct node {
    int u, v, w;
}a[N];
int find(int x) {
    if(pre[x] == x) return x;
    return pre[x] = find(pre[x]);
}
bool unions(int x, int y){
    if(find(x) == find(y)) return false;
    pre[find(x)] = find(y);
    return true;
}
bool cmp(node x, node y) {
    return x.w < y.w;
}
void init(){
    for(int i = 1; i <= n; i++) pre[i] = i;
}
void solve() {
    cin >> n >> m;
    init();
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
    }
    priority_queue<int> pq;
    sort(a + 1, a + m + 1, cmp);
    int cnt = 0;
    for(int i = 1; i <= m; i++){
        int x = find(a[i].u), y = find(a[i].v);
        if(unions(x, y)){
            pq.push(a[i].w);
            pre[x] = y;
            cnt++;
            if(cnt == n - 1) break;
        }
    }
    cout << pq.top() << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}

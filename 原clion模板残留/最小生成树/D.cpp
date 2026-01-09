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
struct node{
    int u,v,w;
}a[N];
int cnt = 0;
int pre[400];
int find(int x){
    if(x == pre[x]) return x;
    return pre[x] = find(pre[x]);
}
void solve() {
    int n,x; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        cnt++;
        a[cnt]={0,i,x};
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> x;
            cnt++;
            a[cnt]={i,j,x};
        }
    }
    sort(a + 1,a+cnt+1,[](node x,node y){
        return x.w < y.w;
    });
    for(int i = 1; i <= n; i++) pre[i] = i;
    int ans = 0;
    for(int i = 1; i <= cnt; i++){
        if(find(a[i].u) != find(a[i].v)){
            ans += a[i].w;
            pre[find(a[i].u)] = find(a[i].v);
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}

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
/*
    经过操作后仅存在一对(i,i+1) 使得
    a[i] = i+1
    a[i+1] = i

    交换环内的两个元素，会使得环变成两个环 环cnt++
    交换环外的两个元素，会使得两个环合并成一个环 环cnt--
    最终我们需要的环数为 n (i <==> a[i])

    操作次数 = n - 初始环数
    <置换环的概念>
    1. 求出初始环数 cnt
    2. 判断是否存在一对 (i,i+1) 使得 i 和 i+1 在同一个环内
        存在则 ans = n - cnt - 1
        不存在则 ans = n - cnt + 1
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    int cnt = 0;
    vector<int> vis(n+1,0);
    for(int i = 1; i <= n; i++){
        if(!vis[i])
        {
            cnt++;
            int u = i;
            while(!vis[u]){
                vis[u] = cnt;
                u = a[u];
            }
        }
    }
    int ans = n - cnt;
    for(int i = 1; i < n; i++){
        if(vis[i] == vis[i+1]){
            cout << ans - 1 << endl;
            return;
        }
    }
    cout << ans + 1 << endl;
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
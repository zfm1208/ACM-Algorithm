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
const int N = 1e6, mod = 676767677, inf = 1e18 + 5;
/*
    一个人i想要在时刻t(t>0)坐下, 必须满足下面两个条件
    <1>: 左边或右边的邻居, 必须至少有一个人在t-1时刻或之前就已经左下了
    <2>: 在t-1时刻或之前，已经坐下的人数必须 >= a[i]

    b[]数组是每个人入座的时间, 我们在任意时刻t, 全场坐下的人数就已经知道了

    C[t]: 恰好在时间t坐下的人数
    P[t]:在时刻t及之前坐下的总人数

    我们要思考一个问题：为什么i在b[i](b[i] > 0)时刻坐下而不是b[i]-1呢？
    我们记t_min = min(b[i-1], b[i+1]) 为他邻居最早坐下的时刻
    <1>: t_min >= b[i], 这是非法状态 

    <2>: t_min < b[i] - 1, 邻居早就坐下了, 既然i还没坐下,就只有 时间状态不满足了
        在 b[i] - 1 时刻没有坐下， 意味着 a[i] > p[b[i] - 2]
        在 b[i] 时刻坐下了, 意味着人数足够了 a[i] <= p[b[i] -1]

        那么a[i] 有效范围是( p[b[i] - 2] , p[b[i] - 1] ]
    <3>: 邻居刚刚坐下 (t_min == b[i] - 1)
        说明是因为邻居i还没有坐下，说明邻居不社恐
        a[i] : P[b[i] - 1]
*/
void solve(){
    int n,m; cin >> n >> m;
    vector<int> b(n+1);
    map<int,int> mp;
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        mp[b[i]]++;
    }
    vector<int> pre(m+1);
    pre[0] = mp[0];
    for(int i = 1; i < m; i++){
        pre[i] = pre[i-1] + mp[i];
    }
    int ans = 1;
    for(int i = 1; i <= n; i++){
        if(b[i] == 0) continue;
        int t_min = inf;
        if(i > 1) t_min = min(t_min, b[i-1]);
        if(i < n) t_min = min(t_min, b[i+1]);
        if(t_min >= b[i]) {
            cout << 0 << endl;
            return;
        }
        if(t_min == b[i] - 1){
            ans = (ans * pre[b[i] - 1]) % mod;
        }else{
            ans = (ans * mp[b[i] - 1]) % mod;
        }
    }
    cout << ans << endl;
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
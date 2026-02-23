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
    题目说不会出现m的倍数，在取模的运算下，等价于s[n] % m 的结果不为0
    因为一切运算都和m的倍数有关，显然可以在递推时直接加上取模
    s[n] = (A*s[n-1] + B*s[n-2]) % m;

    不可能是无限的序列，去找循环
    决定序列下一项(s[n])的值是多少，取决于前面连续两项(s[n-2], s[n-1])
    所以，我们可以把相邻的两项 看作一个 状态
    因为所有数都对m 取模, 所以(u,v) 最多只有m * m种情况
    O(n*n) = 1e6 

    状态(u,v)  ->  (v, (A*v + B*u) % m)

    可以看作一个图，从一个点向另一个点走，最后必然会陷入一个环(死循环)

    在图上的任意节点(u,v), 只要u = 0 || v = 0, 那么这个节点就是不合法的，即这个环里面任何点都不合法
    反之,那么这个环里面的起点都合法

    我们要记录一个状态dp[u][v]; 在枚举起点(u,v)时，如果该状态走过，那么就不用走了
    /
        dp[u][v]:
        0: 没走过
        1：当前起点正在走的
        2：死路
        3：活路
    /

*/
void solve(){
    int m,a,b; cin >> m >> a >> b;
    vector<vector<int>>dp(m+1,vector<int>(m+1));
    // (u,v)有一个是0,那就不合法
    for(int i = 0; i < m; i++){
        for(int j = 0;j < m; j++){
            if(i == 0 || j == 0) dp[i][j] = 2;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0;j < m; j++){
            if(dp[i][j] != 0) continue;
            int u = i,v = j;
            vector<pii> path; // 记录环那个路径
            while(dp[u][v] == 0){ // 一直走，直到撞到已知节点或者当前正在走的路径
                dp[u][v] = 1;
                path.pb({u,v});
                int temp = (a*v + b*u) % m;
                u = v;
                v = temp;
            }
            //循环结束时，我们停在dp[u][v] = 1,2,3 的节点上
            // 1和3合法,2不合法
            int fn = (dp[u][v] == 1) ? 3 : dp[u][v];
            for(auto [u,v]: path){
                dp[u][v] = fn;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0;j < m; j++){
            ans = (ans + (dp[i][j] == 3));
        }
    }    
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}
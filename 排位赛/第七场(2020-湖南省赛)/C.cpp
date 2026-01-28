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
    给你一个由01组成的序列a,定义一次f(a) 会产生一个新序列
    bi = |bi - bi+1|
    重复n-1次操作，最后只剩下1个数字
    目标: 给你一个0，1，？的串，求多少种方案可以使得最后数字是1

    Think: 绝对值减法 = XOR
    操作变为相邻元素异或

    a1              a2              a3            a4      
           a1^a2           a2^a3          a3^a4     
               a1^a2^a2^a3      a2^a3^a3^a4
                 a1^a2^a2^a3^a2^a3^a3^a4
                    = a1^a2^a3^a4

        n = 1:      1
        n = 2:    1   1
        n = 3:  1   2   1
        n = 4: 1  3   3   1
        .....
        杨辉三角
    ans = (C(n-1,0) * a1) ^ (C(n-1,1) * a2) ^ (C(n-1,2) * a3) ^ (C(n-1,3) * a4)
    可见若ai为0就不用管
    可见若C(n-1,i-1)是偶数也是没有贡献的
    怎么判断C(n,m)是不是奇数？
    -> 如果 n&m == m, 那么C(n,m)是奇数


*/
void solve(){
    string s;
    while(cin >> s){
        int n = s.size();
        s =  " " + s;
        vector<int> dp(2,0);
        // 当前填完的方案里，最终异或和是 0/1 的方案有多少种
        dp[0] = 1; // 空集
        for(int i = 1; i <= n; i++){
            vector<int> ndp(2,0);
            if(s[i] == '0' || s[i] == '?'){
                ndp[0] = (ndp[0] + dp[0]) % mod;
                ndp[1] = (ndp[1] + dp[1]) % mod;
            }
            if(s[i] == '1' || s[i] == '?'){
                int op = (((n-1) & (i - 1)) == (i - 1));
                ndp[0 ^ op] = (ndp[0 ^ op] + dp[0]) % mod;
                ndp[1 ^ op] = (ndp[1 ^ op] + dp[1]) % mod;
            }
            dp = ndp;
        }
        cout << dp[1] << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}
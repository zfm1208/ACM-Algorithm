#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N = 1e5+6,mod = 998244353;
#define rep(i,l,r) for(int i = l; i <= r; i++)
int ksm(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        b = b / 2;
        a = a * a % mod;
    }
    return res;
}
/*
    仙人掌图:
        1.连通图
        2.任何一条边，最多属于一个简单环(两个环可以共点，但不能共边)
    平行边: 两个点之间可以有多条边 (可以构成环)
    fn:有n个不同顶点的仙人掌图的数量
    1+fi - fi*fj  /  fi-fj

    零长度序列和为0，积是1
    n = 1，ans = 1 (内积没有数，积为1)
    n = 2, ans = 1 (f1 = 1,f2 = 2)
        
        (i == 1) fi = 1,fj = 2
            sum = 0/-1 = 0
        (i == 2) fi = 2,fj = 1
            sum = 1 / 1 = 1
        ans = 0+1 = 1
    n = 3, ans = 2 (f1 = 1,f2 = 2,f3 = 13)
        (i == 1) 
        fi = 1,fj = 2
            sum = 0
        fi = 1,fj = 13
            sum = 11/12
        ans + 0

        (i == 2)
        fi = 2,fj = 1
            sum = 1
        fi = 2,fj = 13
            sum = 23/11
        ans + 23/11

        (i == 13)
        fi = 13,fj = 2
            sum = -12/11
        fi = 13,fj = 1
            sum = 1/12
        ans - 1/11

        ans = 22/11 = 2

    n = 4, (f1 = 1,f2 = 2,f3 = 13,f4 = )
    ans = 
*/

/*
    n = 1 ans = 1
    n = 2 ans = 1
    n = 3 ans = 2
    n = 4 

*/
void zfm(){
    int n; cin >> n;
    if(n == 1){cout << 1 << endl;}
    else {
        vector<int> dp(n+1);
        dp[1] = 1,dp[2] = 1;
        for(int i = 3; i <= n; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }
        cout << dp[n] << endl;
    }
}
void bl(){
    int n = 2;
    int sum = 0;
    int p = 998244351;
    for(int i = 1; i <= n; i++){
        int x = 1;
        int y = 1;
        for(int j = 1; j <= n && i != j; j++){
            x = x * (1 + i - i * j) % mod;
            y = y * (i-j) % mod;
        }
        sum = (sum + ksm(y,p) % mod * x % mod) % mod;
    }
    cout << sum << endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        // bl();
        zfm();
    }
    return 0;
}
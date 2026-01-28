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
    A = B ^ C =>  B = A ^ C
    A: 10010  A: 10010
    B: 01011  C: 11001
    C: 11001  B: 01011
    题目核心公式：
    对于每个位置i(1 <= i < n),一定要在它后面(j >= i)找到一个数p_j，
    使得：P_i = P_j ^ i   即： P_i ^ i = P_j

    Think:
    任何数异或1，只改变最后一位(奇变偶，偶变奇)
    若我们构造一种，使得p_i ^ i == 1
    那么P_i = i ^ 1
    则让P_n = 1;

    Try:
    对于i (1 <= i < n) P_i = i^1 , P_n = 1;

    n 偶数：n^1 = n+1 > n越界
    不能简单的把n放在某个产生n^1的位置
    需要调整把n放在一个其他位置，用二进制最低位1来互换调整
*/
void solve(){
    int n; cin >> n;
    // 奇数
    if(n&1){
        // n = 7:
        // ! 6 3 2 5 4 7 1
        cout << n-1 << " ";
        for(int i = 2; i <= n-1; i++){
            cout << (i ^ 1LL) << " ";
        }
        cout << 1 << endl;
        return;
    }
    // 2的次幂
    int p = log2(n&-n);
    if(n == (1LL << p)){
        cout << -1 << endl;
        return;
    }
    // 偶数
    vector<int> ans(n+1);
    ans[n] = 1;
    ans[1] = n;
    for(int i = 2; i < n; i++){
        ans[i] = i ^ 1LL;
    }
    swap(ans[1],ans[1 << p]);
    rep(i,1,n) cout << ans[i] << " \n"[i==n];
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
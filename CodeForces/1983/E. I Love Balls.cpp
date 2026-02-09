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
int ksm(int a,int b){
    int res = 1;
    a %= mod;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
/*
    经典数学期望
    考察组合数+逆元
    总期望 = 每个球的分值 * 该球落入玩家手中的概率
    球分为两类：
    1. 普通球：共 m (n-k)个
    2. 特殊球：共 k 个

    ! <1> 普通球的概率：
        游戏的回合转换由普通球决定(特殊球不会交换球手，只会延续当前玩家的回合)
        考虑所有普通球的相对顺序：
        第1个被抽到的普通球：Alice
        第2个被抽到的普通球：Bob
        第3个被抽到的普通球：Alice
        第4个被抽到的普通球：Bob
        ...
        对于任意一个普通球,在所有普通球的随机排列中，出现在奇数位置的概率就是Alice的概率
        设普通球总数为m：
        * Alice拿到概率P_A = (m+1/2) / m
        * Bob拿到概率P_B = (m / 2) / m
    ! <2> 特殊球的概率：
    特殊球归谁，取决于它被抽到时是谁的回合-> 取决于在这个特殊球之前，已经抽走了多少普通球
        如果之前抽走偶数个普通球，当前是Alice回合
        如果之前抽走奇数个普通球，当前是Bob回合

        简化为：将1个特殊球插入m个普通球的随机排列中,一个有m+1个插入位置
        位置0，1，2，m (表示前面有几个普通球)
        * Alice拿到概率P_A: 插入位置是偶数的概率 = 偶数位置的个数 / (m+1)
        * Bob拿到概率P_B: 插入位置是奇数的概率 = 奇数位置的个数 / (m+1)
*/
void solve(){
    int n,k; cin >> n >> k;
    int sum_pt = 0, sum_ts = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(i <= k){
            sum_ts = (sum_ts + x) % mod;
        }else sum_pt = (sum_pt + x) % mod;
    }
    int m = n - k; 
    if(m == 0){
        cout << sum_ts << " " << 0 << endl;
        return;
    }
    // 普通球概率：
    int P_pt_A = ((m + 1) / 2) * ksm(m, mod-2) % mod;
    int P_pt_B = (m / 2) * ksm(m, mod-2) % mod;
    // 特殊球个数：
    int P_ts_A = (m / 2 + 1) * ksm(m+1, mod-2) % mod;
    int P_ts_B = ((m + 1) / 2) * ksm(m+1, mod-2) % mod;
    
    int P_A = (sum_pt * P_pt_A % mod + sum_ts * P_ts_A % mod) % mod;
    int P_B = (sum_pt * P_pt_B % mod + sum_ts * P_ts_B % mod) % mod;
    cout << P_A << " " << P_B << endl;
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
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
/*
    * 题目:
    题目要求我们把数组切成若干段，要求每段长度都是奇数，并且每段的中位数都必须相同
    但这一题n<=5000,说明最后是用n^2的方法实现, 双层枚举或者dp

    * 分析：
    假设中位数是mid, 在任何一个长度为奇数的合法子数组里，根据中位数的定义
    我们可知:
        大于等于mid 的数字, 数量一定 严格大于一半
        小于等于mid 的数字, 数量一定 严格大于一半
    既然每一块碎片都满足这个性质，那么当我们会看整个数组时，
    整个原数组里大于等于 mid 和小于等于 mid 的数字，也必然都严格大于一半

    那么其实整个mid就是确定的,等于 原数组的中位数 mid

    确认了中位数 mid 后，怎么快速判断任意一个区间 [j, i] 的中位数是不是 mid 呢？
    我们观察到,这是个区间问题,我们要快速判断一个区间是否合法,我们要想到前缀和
    <1> : 里面 >= mid 的数字个数 > len/2
    <2> : 里面 <= mid 的数字个数 > len/2

    很经典的 01替换
    我们把>= mid的数当成1, < m的数当作-1, 当一个区间的和>0, 就说明 >= mid 的个数大于 区间的一半
    我们把<= mid的数当成1, > m的数当作-1, 当一个区间的和>0, 就说明 <= mid 的个数大于 区间的一半

    我们只用维护两个pre1,pre2数组即可 
    pre1[r] - pre1[l-1] > 0 && pre2[r] - pre2[l-1] > 0
    则区间合法, 他是从前l-1的数推过来的,dp[r] = dp[l-1] + 1

    * 设dp[i] : 前i个元素最多能分出多少个合法子数组
    从dp[j-1] 后面接着划分[j,i] , dp[i] = dp[j-1] + 1

    当然要保证前面的dp[j-1]合法,所以我们先初始化-1表示不可达

    注意dp[0] = 0;
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1),tp(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        tp[i] = a[i];
    }
    sort(tp.begin()+1,tp.end());
    int mid = tp[n/2+1];
    vector<int> pre1(n+1),pre2(n+1);
    // pre1[i] > 0 : 区间[1,i] >= mid 的数超过了一半
    // pre2[i] > 0 : 区间[1,i] >= mid 的数超过了一半
    for(int i = 1; i <= n; i++){
        if(a[i] >= mid){
            pre1[i] = pre1[i-1] + 1;
        }else{
            pre1[i] = pre1[i-1] - 1;
        }
        if(a[i] <= mid){
            pre2[i] = pre2[i-1] + 1;
        }else{
            pre2[i] = pre2[i-1] - 1;
        }
    }

    vector<int> dp(n+1,-inf); // 前i个元素最多能分出多少个合法子数组
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            int len = (i-j+1);
            if(len & 1){
                if(pre1[i] - pre1[j-1] > 0 && pre2[i] - pre2[j-1] > 0){
                    if(dp[j-1] != inf) dp[i] = max(dp[i], dp[j-1] + 1);
                }
            }
        }
    }

    cout << dp[n] << endl;
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
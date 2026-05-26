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
// https://codeforces.com/problemset/problem/607/A
/*
    * 分析题目
    ! <1> 转化目标：正难则反
    题目要求 "最少被摧毁的信标数量"
    在原题的连锁反应中，被摧毁的数量很难直接统计，因为一次爆炸可能会引起一连串的摧毁
    思维转换：信标总数 n 是固定的，最少被摧毁 = 最多被保留
    我们把目标改为：寻找一种放置新信标的方式，使得最终留下来的信标最多

    ! <2>: 分析新信标的作用
    在最右侧（所有信标的右边）放置一个新信标
    这个新信标往左爆炸，它的本质作用是什么？
    它的作用就是 "无代价地抹除" 原数组最右边的一段连续信标（也就是摧毁原数组的一个后缀）
    假设 新信标刚好把第 i+1 到第 n 个信标全炸了，那么第 i 个信标就会成为原数组中第一个被触发的信标

    ! <3> 发现子问题（无后效性）
    一旦确定了第 i 个信标被触发，它左边能保留下来多少个信标，是一个定值. 无后效性

    * DP 状态和转移
    <1> : 状态定义
    dp[i] 表示如果第 i 个信标作为最右侧的信标被触发，它及其左边的所有信标中，最多能保留多少个
    <2> : 状态转移
    当第i个信标爆炸时, 摧毁范围是[ai - bi, ai-1]
    我们需要在它左边找到第一个位置严格小于ai-bi的信标(最靠右),假设为j
    dp[i]= dp[j] + 1 (保留了第 i个信标本身,再加上第 j个信标及其左边能保留的数量 dp[j])

    * ans
    ans = n - max(dp[i]) (i of [1,n])


    ! 怎么找最左边的那个下标j?
    (1) : 二分查找 (基于下标dp)
    (2) : 值域dp (基于坐标dp)
*/
void solve(){
    int n; cin >>n;
    vector<pii> a(n+1);
    for(int i = 1;i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a.begin()+1, a.end(),[](pii x, pii y){
        return x.fi < y.fi;
    });
    vector<int> dp(n+1);
    // dp[i] : 以第i个信标作为起点,往左最多还能保留多少个
    for(int i = 1; i <= n; i++){
        int len = a[i].fi - a[i].se;
        auto pos = lower_bound(a.begin()+1,a.end(),make_pair(len, 0LL),[](pii x, pii y){
            return x.fi < y.fi;
        });
        int j = (pos - a.begin()) - 1;
        dp[i] = dp[j] + 1;
    }
    int mx = 0;
    for(int i = 1; i <= n; i++){
        mx = max(dp[i], mx);
    }
    cout << n - mx << endl;
}

void solve1(){
    int n; cin >> n;
    int mx = 0;
    unordered_map<int,int> mp;
    for(int i = 1; i <= n; i++){
        int p, x; cin >> p >> x;
        mp[p] = x;
        mx = max(mx, p);
    }
    int ans = 0;
    vector<int> dp(mx+1);
    for(int i = 0; i <= mx; i++){
        if(mp[i] == 0){
            if(i > 0) dp[i] = dp[i-1];
            else dp[i] = 0;
        }else{
            int p = i - mp[i] - 1;
            if(p < 0) dp[i] = 1;
            else dp[i] = dp[p] + 1;
        }
        ans = max(ans, dp[i]);
    }
    cout << n - ans << endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve1();
    return 0;
}
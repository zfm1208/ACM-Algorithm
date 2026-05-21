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
    *1. 整体偏移
    假设我们原本的前缀和是p[i],若在位置k花费c[k],修改了a[k], 增加 x
    那么这个操作对前缀和的影响是：
    对于i < k的前缀和, 不受影响
    对于i >=k 的前缀和, 所有的p[i] 都整体加上了 x
    因此，每一次修改，就相当于把序列切分出了一个新的块。
    这个块从修改的位置 L 开始，一直延伸到下一个修改的位置之前。
    在这个块内，所有前缀和都加上了同一个任意的偏移量 x
    *2.  合法 块
    我们的终极目标是：所有修改后的前缀和模 r 都不为 0
    对于从 L 开始的一块，原来的前缀和集合是{p[L], p[L+1], ... , p[i]}
    如果这个集合在模 r 意义下，包含了所有 0,1,..,r-1 这 r 种余数, 这个 块 总是不合法的
    反之，只要这块内前缀和的余数种类严格小于 r, 总是能让其合法
    *3. 动态规划状态转移
    令dp[i]: 表示处理完前 i 个位置的最小代价
    若最后一次修改发生在位置 L (L <= i)，则状态转移方程为
    dp[i] = min(dp[L-1] + c[L]) (L[i] < L <= i);
    L[i] : 是满足区间 [L[i], i] 恰好包含 r 种不同余数的最靠右的左端点
    ! 特殊情况（第一块）：
    第一块是从位置 1 开始的，它没有偏移量
    第一块合法的条件仅仅是：这一块内原本的 p[k] 都不能是 0
    如果在前 i 个位置中，原前缀和没有出现过 0
    那么 dp[i] 可以直接是 0

    * 算法:
    如果暴力寻找l, 超时
    <1.双指针 / 滑动窗口维护 L[i]
    随着右端点 i 的增加，左端点 L[i] 也是单调不减的,
    当余数种类达到 r 时，不断右移 L 直到种类再次小于 r

    <2.单调队列维护 dp[L-1] + c[l] 的最小值
    对于滑动窗口 [L+1, i]内的最小值查询,单调队列是完美的解决方案。
    每次 i 增加，我们将新的候选值压入队列；
    每次 L 增加，我们将失效的左端点从队列头弹出

*/

/*
    r = 5
    cnt = 4
    前缀和 0 3 2 4
    0 3 2 4
    1 4 3 0
    2 0 4 1
    3 1 0 2
    4 2 1 3
*/
void solve(){
    int n, r; cin >> n >> r;
    vector<int> a(n+1), c(n+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> c[i];
    vector<int> pre(n+1);
    for(int i = 1; i <= n; i++){
        pre[i] = (pre[i-1] + a[i]) % r;
    }
    map<int, int> mp; 
    // 当前窗口内不同余数的数量
    int cnt = 0; 
    // 左边界: 使得[L+1, i] 是合法区间的最小 L
    int L = 0;
    // dp[i]: 前i个位置的最小代价
    vector<int> dp(n+1); 
    // 单调队列，存储下标 l, 维护 dp[l-1] + c[l] 的最小值
    // dq.front()是合法最小价值
    deque<int> dq;
    int pos = n+1;
    for(int i = 1; i <= n; i++){
        if(pre[i] == 0){
            pos = i;
            break;
        }
    }
    for(int i = 1; i <= n; i++){
        if(mp[pre[i]] == 0) cnt++;
        mp[pre[i]]++;
        while(cnt == r){
            L++;
            mp[pre[L]]--;
            if(mp[pre[L]] == 0) cnt--;
        }
        // 踢除 过时的 位置(实际是价值)
        while(!dq.empty() && dq.front() <= L) {
            dq.pop_front();
        }
        // 踢除 价值不优的 位置(实际是价值)
        int val = dp[i-1] + c[i];
        while(!dq.empty() && (dp[dq.back() - 1] + c[dq.back()]) >= val) {
            dq.pop_back();
        }
        dq.push_back(i);

        int mn = dp[dq.front() - 1] + c[dq.front()];
        if(i < pos) {
            dp[i] = min(0LL, mn); 
        }else{
            dp[i] = mn;
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
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
    问题：找出有多少个子数组，满足任意两数的差的绝对值 >= k

    题目转换为 一个子数组最小的差值是否>=k,
    如果是，那么这个子数组对于所有 <= 最小差值的 k 都合法
    -> 对于每个相邻差值 d[i]，去算它能作为多少个子数组的最小值

    假设我们有一个差值数组 d，其中 d[i] 是第i个位置的差值。
    如果我们可以算出：d[i] 在 cnt 个子区间里是最小值。
    那么意味着：
    这 cnt 个子区间，对于 k=1, 2, ..., d[i] 都是合法的(因为它们的最小值都至少是 d[i])

    问题转化->:  对于数组中的每个数，求它是最小值的区间范围有多大？ -- 单调栈

    在范围(L[i], R[i])内，d[i]是最小值
    起点可以在 (L[i]+1) 到 i 之间选，终点可以在 i 到 (R[i]-1) 之间选
    乘积就是以 d[i] 为最小值的子区间个数
    综上所述：
    以 d[i] 为最小值的子区间个数 cnt = (i - L[i]) * (R[i] - i)

    差分数组：对于每个 d[i]，我们都要把答案的区间[1, d[i]]都 + cnt
    差分数组的好处是，我们不需要每次都去更新整个区间，只需要更新两个位置

    解法：使用单调栈 + 差分数组
    1. 计算相邻元素的差的绝对值 d[i]
    2. 使用单调栈求每个d[i]的左右边界
    3. 差分统计贡献
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> d(n); 
    for(int i = 1; i < n; i++){
        d[i] = abs(a[i] - a[i+1]);
    }

    // 单调栈求左右边界
    // 求左边界：左边第一个 < d[i] 的位置
    vector<int> L(n, 0); // 默认边界是 0
    stack<int> st1;
    for(int i = 1; i < n; i++){
        // 如果栈顶元素 >= 当前元素，说明栈顶不是我们要找的“更小值”，弹出
        while(!st1.empty() && d[i] <= d[st1.top()]) st1.pop();
        
        // 栈空了说明左边没有比我小的，否则栈顶就是左边第一个比我小的
        if(!st1.empty()) L[i] = st1.top();
        
        st1.push(i);
    }

    // 求右边界：右边第一个 <= d[i] 的位置
    // 注意：为了避免有相同数值时重复计算，一边用 <，一边用 <=
    // 这里求的是第一个 < d[i] 的位置
    vector<int> R(n, n); // 默认边界是 n
    stack<int> st2;
    for(int i = n-1; i >= 1; i--){
        while(!st2.empty() && d[i] < d[st2.top()]) st2.pop();
        if(!st2.empty()) R[i] = st2.top();
        st2.push(i);
    }
    // 差分统计贡献
    vector<int> diff(n + 2, 0); 
    for(int i = 1; i < n; i++){
        // 核心公式：左边可选起点数 * 右边可选终点数
        // L[i] 是左边界，R[i] 是右边界（都不包含）
        // 所以左边长度 i - L[i]，右边长度 R[i] - i
        int cnt = (i - L[i]) * (R[i] - i); 
        // 差分更新：区间 [1, d[i]] 的答案都需要 +cnt
        diff[1] += cnt;
        diff[d[i] + 1] -= cnt;
    }
    // 前缀和计算答案
    int ans = 0;
    for(int k = 1; k <= n-1; k++){
        ans += diff[k];
        cout << ans << " ";
    }
    cout << endl;
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

/*  
    为什么一边用 <,一边用 <= 
    d:[3,2,5,2,6]
    对于左边的2
    左边界是3，右边界是5
    范围[3,2,5] 
    子数组有：(3,2), (3,2,5), (2), (2,5)

    对于右边的2
    左边界是3，右边界是6
    范围[3,2,5,2,6]
    子数组有：(3,2,5,2), (2,5,2), (5,2), (2), (2,6), (5,2,6), (2,5,2,6), (3,2,5,2,6)
*/
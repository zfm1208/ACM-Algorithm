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
const int N = 4e6+2, mod = 1e9+7, inf = 1e18 + 5;
// https://qoj.ac/problem/6433
/*
    问题: 给你一个数组，你可以将一段区间[l,r] (1 <= l <= r <= n)的数+=k
    通过最优地选择区间(可不选)，使得操作后整个序列的众数的出现次数最大化。
    输出这个最大的出现次数

    思路:
    假设我们最终希望数字 x 成为序列的众数，并且我们对区间 [l,r] 加上了k
    那么最终序列中 x 的总数量等于： 原序列x的数量 + 区间[l,r]对x产生的新增数量

        1.如果区间内原来的元素是 x-k，加上 k 后变成了 x，对目标 x 的增益为 +1。
        2.如果区间内原来的元素是 x，加上 k 后变成了x+k，对目标 x 的增益为 -1
        3.如果是其他元素，变化后也变不成 x，增益为0。

    在遍历原数组 a 的过程中，对于当前元素 v = a[i]，它其实只对两个目标值有影响：
    作为 v，它加上 k 以后变成了 v + k，这使得目标值 x = v + k 获得了一个 +1 的增益。
    作为 v，它加上 k 以后失去了原本的数值，这使得目标值 x = v 获得了一个 -1 的增益。

    我们可以用一个数组 dp[x] 来维护 "以当前位置结尾、目标值为 x 的最大增益"

    dp[v + k] = max(0LL, dp[v + k]) + 1;
    dp[v] = dp[v] - 1;

    同时用mx[x] 记录 dp[x] 出现的历史最大值

    由于a[i],k 范围是[-1e6,1e6], x 范围是[-2e6,2e6]
    我们可以给所有数值加上一个数值2e6

    特判一下0就行
*/

/*
    为什么想到一维dp，我们可以想一下
    无论那个区间，本质上就是在做+1，-1的权衡，
    用一个一维的 dp[X] 数组，同时记录所有可能的x的最大子段和状态，
    当遍历完一遍数组后，所有x的历史最大收益也就自然而然地全部算出来了。

    还是类似 最大子段和 的问题
*/
const int OF = 2e6;
int cnt[N];
int a[N],dp[N],mx[N];
void solve(){
    int n,k; cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i] + OF]++;
    }
    if(k == 0){
        int ans = 0;
        rep(i,1,n) ans = max(ans, cnt[a[i] + OF]);
        cout << ans << endl;
        return;
    }
    vector<int> dp(N),mx(N);
    for(int i = 1; i <= n; i++){
        int v = a[i];
        dp[v + k + OF] = max(dp[v + k + OF], 0LL) + 1;
        mx[v + k + OF] = max(mx[v + k + OF], dp[v + k + OF]);
        dp[v + OF] = dp[v + OF] - 1;
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(cnt[i] || mx[i]) ans = max(ans, cnt[i] + mx[i]);
    }
    cout << ans << endl;
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
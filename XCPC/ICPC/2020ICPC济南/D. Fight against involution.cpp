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
 * 题目：Fight against involution (反内卷)
 
 * * 【核心思路】
 * 1. 明确原规则：原计划大家都会写到上限 R。
 *      如果 R_A > R_B，A 就会对 B 产生压制（导致 B 被扣分）。
 *      R 相同的人同属一个梯队，互相不压制。
 * 2. 成绩不降的条件：为了保证每个人的成绩不比原来低，必须维持原有的“压制阶级”。
 *      也就是说：原本 R 较小的梯队，重新分配的字数绝对不能反超原本 R 较大的梯队。
 * 
 * * 【贪心 & 排序策略】
 * 1. 排序建梯队：将所有人按 R 从小到大排序。R 相同的人视为同一个“梯队”，统一进行结算。
 * 2. 从底向上推平：维护一个水位线变量 `cur`（初始为 0），记录前一个梯队分配的字数。
 * 3. 逐层结算：遍历每个梯队，找出该梯队中最大的下限 `mx`。
 * - 为了满足本梯队所有人的最低字数要求，统一字数至少得是 `mx`。
 * - 为了不反超上一个梯队（防止破坏成绩），统一字数不能低于上一梯队的 `cur`。
 * - 因此，当前梯队所有人的最佳分配字数就是：cur = max(cur, mx)。
 * 4. 累加答案：将更新后的 `cur` 乘以当前梯队的人数 `(r - l)`，累加到总花费 `ans` 中。
 *
 * 复杂度：
 * - 时间复杂度：O(N log N) -> 瓶颈在于按照 R 排序。
 * - 空间复杂度：O(N) -> 需要一个 vector 存储结构体。
 */
struct node {
    int l,r;
};
void solve(){
    int n; cin >> n;
    vector<node> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
    }
    sort(a.begin()+1,a.end(),[](auto x, auto y){
        return x.r < y.r;
    });
    int ans = 0;
    int cur = 0;
    int l = 1;
    while(l <= n){
        int r = l;
        int mx = 0;
        while(r <= n && a[r].r == a[l].r){
            mx = max(mx, a[r].l);
            r++;
        }
        cur = max(cur, mx);
        ans += (r - l) * cur;
        l = r;
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
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
 * 题目：F. It Just Keeps Going Sideways
 * 
 * 【题意简述】
 * n 列方块，第 i 列高 a[i]。重力向右，所有方块向右滑动到底。
 * 操作：最多移除 1 个方块（使某个 a[i] 减 1）。
 * 目标：求所有方块“总移动距离（|最终列 - 初始列|）”的最大值。
 * 
 * 【核心思路：宏观坐标求和 + 排序等价】
 * 1. 最终形态的本质：
 *    重力向右挤压后，整体轮廓必然是单调递增的。
 *    因此，最终状态每列的高度分布，等价于把原数组 a【升序排序】后的结果，记为数组 s。
 * 
 * 2. 宏观计算移动距离：
 *    所有方块都是向右移动，总距离 = 最终横坐标之和 - 初始横坐标之和。
 *    - 初始横坐标之和 Sum_init = Σ (i * a[i])
 *    - 最终横坐标之和 Sum_final = Σ (i * s[i])
 *    - 基础总距离 Base = Sum_final - Sum_init
 * 
 * 3. 移除 1 个方块的绝妙影响（神之手收益）：
 *    假设我们移除原数组第 k 列的一个方块（高度值为 v = a[k]）：
 *    - 初始坐标和会减少 k。
 *    - 为了让排序数组 s 依然保持升序，我们必须把 s 中值为 v 的【最左边（第一次出现）】的元素减 1，记它的索引为 p。最终坐标和会减少 p。
 *    - 新的总距离 = (Sum_final - p) - (Sum_init - k) = Base + (k - p)。
 *    - 额外收益就是：k - p。
 * 
 * 4. 贪心策略：
 *    我们要让收益 (k - p) 最大化。
 *    对于存在的每一个高度值 v：
 *    找它在原数组 a 中的最大索引（最靠右的位置）k，
 *    找它在排序数组 s 中的最小索引（最靠左的位置）p。
 *    记录最大的 (k - p)，如果最大值 < 0 则不操作（收益记为 0）。
 *    最终答案 = Base + max(0, k - p)。
 *    
 * 复杂度：O(N log N)，瓶颈在于对数组排序。
 */
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    vector<int> suf(n+1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        suf[a[i]] = i;
        sum += i * a[i];
    }
    vector<int> b = a;
    sort(b.begin()+1,b.end());
    vector<int> pre(n+1);
    int sum1 = 0;
    for(int i = 1; i <= n; i++){
        sum1 += i* b[i];
        if(pre[b[i]] == 0){
            pre[b[i]] = i;
        }
    }
    int ans = sum1 - sum;
    int mx = 0;
    for(int i = 1; i <= n; i++){
        if(suf[i] != 0){
            mx = max(mx, suf[i] - pre[i]);
        }
    }
    cout << ans + mx << endl;
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
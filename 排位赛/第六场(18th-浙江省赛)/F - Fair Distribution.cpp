#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define rep(i,l,r) for(int i = l; i <= r; i++)
const int N = 2e5+10, mod = 1e9+7, inf = 1e18;
#define pb push_back
/*
 * ==================================================================================
 * 题目名称: F. Fair Distribution (第18届浙江省大学生程序设计竞赛)
 * 题目来源: Codeforces Gym / 浙江省赛
 *
 * 【题目描述】
 * 给定 n 个机器人和 m 个能量棒。
 * 你拥有两种操作，每次操作花费 1 金币：
 * 1. 销毁一个机器人 (n -> n-1)
 * 2. 制造一个能量棒 (m -> m+1)
 *
 * 目标：
 * 通过上述操作，使得最终的能量棒数量是机器人数量的整数倍。
 * 求达成该目标所需的最小花费。
 *
 * 输入: T 组数据 (T <= 1000)，每组包含 n, m (1 <= n, m <= 10^8)。
 * 输出: 每组数据的最小花费。
 *
 * ==================================================================================
 *
 * 【解题思路：数学建模 + 根号分治】
 *
 * 1. 代价公式：
 * 假设最终保留 i 个机器人 (1 <= i <= n)，每个机器人分得 k 个能量棒。
 * 则最终能量棒总数为 i * k (必须满足 i * k >= m)。
 * 总花费 Cost = (减少的机器人) + (增加的能量棒)
 * = (n - i) + (i * k - m)
 * 我们的目标是找到一对 (i, k)，使得 Cost 最小。
 *
 * 2. 为什么需要分治？
 * 数据范围 n, m 可达 10^8，直接枚举最终机器人数 i (1 到 n) 会导致 O(n) 超时。
 * 观察约束 i * k >= m，可知 i 和 k 近似成反比关系 (i * k ≈ m)。
 * 这提示我们可以利用“根号分治”思想，以 sqrt(m) 为界限进行分类讨论。
 *
 * 3. 算法步骤 (令 limit = sqrt(m))：
 *
 * <情况 A>: 枚举较小的机器人数量 i
 * - 范围: 1 <= i <= limit 且 i <= n
 * - 计算: 对于固定的 i，最优倍数 k = ceil(m / i)。
 * - 代价: Calculate(i, k) 更新最小值。
 *
 * <情况 B>: 枚举较小的倍数 k (对应较大的机器人数量 i)
 * - 当机器人数量 i > limit 时，倍数 k 一定 < m / limit ≈ sqrt(m)。
 * - 范围: 枚举 k 从 1 到 limit + 2。
 * - 计算: 对于固定的倍数 k，满足条件 (i * k >= m) 的最小 i = ceil(m / k)。
 * - 约束: 必须保证计算出的 i <= n (否则机器人不够删)。
 * - 代价: Calculate(i, k) 更新最小值。
 *
 * 4. 时间复杂度：
 * O(sqrt(m)) + O(sqrt(m)) = O(sqrt(m))。
 * 对于 10^8 的数据，计算量约为 2 * 10^4，完全满足 1秒 的时限要求。
 *
 * ==================================================================================
 */

 /*
    这叫根号分治(数论分块)
    这里的分治不是归并排序里面的那种'分而治之'，
    而是根据数据规模大小，采用2种策略处理，分界线通常是根号

    对于这一题，直接遍历n枚举肯定超时(1e8)
    观察到 i * k >= m 
    可知 i 和 k是成反比的
    当i很小时，k很大
    当i很大时，k很小
    切入点，以sqrt(m)为界限，把i分为两部分 ： Limit = sqrt(m)

    1. 当i很小时(1 <= i <= Limit)
    直接暴力枚举更新最小答案

    2. 当i很大时(Limit <= i <= n)
    也就是i > sqrt(m) ,由i * k >= m 可知，k很小
    直接遍历k (1 ~ sqrt(m))


 */
void solve(){
    int n,m; cin >> n >> m;
    if(m%n == 0){
        cout << 0 << endl;
        return;
    }
    if(n > m){
        cout << n - m << endl;
        return;
    }
    // cost = (n - i) + (i * k - m)
    // i * k >= m
    int ans = inf;
    int limit = sqrt(m);
    for(int i = 1; i <= min(limit,n); i++){
        int k = (m + i - 1) / i;
        ans = min(ans, (n - i) + (k * i - m));
    }
    for(int k = 1; k <= limit + 2; k++){
        int i = (m + k - 1) / k;
        if(i > n) continue;
        ans = min(ans, (n - i) + (k * i - m));
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
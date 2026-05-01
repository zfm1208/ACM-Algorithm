#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
// #define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
/*
 * =================================================================================
 * 题目：L. LCMs
 * 
 * 【题意简述】
 * 在一个只有正整数的数轴上，从点 u 走到点 v 的代价是 lcm(u, v)。
 * 规定不能走到 <= 1 的点（即最小只能走到 2）。
 * 给定起点 a 和终点 b (a, b <= 10^7)，求 a 到 b 的最小代价。
 * 
 * 【核心思路：贪心建图 + 分类讨论】
 * 要想总 lcm 代价最小，核心思想是：尽可能借助“较小的数字”作为中转站。
 * 我们可以将走法分为以下三种绝对最优的策略来进行打擂台（求 min）：
 * 
 * 1. 直达策略 (零次中转)
 *    直接走，代价为 lcm(a, b)。
 *    特别地：如果 a 是 b 的约数 (b % a == 0)，那么 lcm(a, b) = b，这是理论下限。
 * 
 * 2. 公共因子中转 (一次中转)
 *    如果 a 和 b 不互质，即 gcd(a, b) = g >= 2。
 *    我们可以走：a -> g -> b。
 *    代价为：lcm(a, g) + lcm(g, b) = a + b。
 *    所以在 gcd(a, b) >= 2 时，答案就是 min(lcm(a, b), a + b)。
 * 
 * 3. 互质情况下的“降级”中转 (复杂中转)
 *    如果 gcd(a, b) == 1，说明无法白嫖 a+b 的代价。
 *    对于任意合数 x，走到它自己的【最小质因数 p_x】是最划算的，因为 lcm(x, p_x) = x。
 *    这就相当于付出了 x 的代价，把自身“降级”到了一个非常小的质数枢纽上。
 * 
 *    因此，我们构建候选集合：
 *    - 起点集合 Sa: 包含 {直接从a出发(代价0)} 和 {降级到 p_a (代价a)}
 *    - 终点集合 Sb: 包含 {直接到达b(代价0)} 和 {从 p_b 升上来(代价b)}
 *    
 *    然后我们在 Sa 和 Sb 中各挑一个点 u 和 v，怎么连通它们？
 *    方案 A: 直接连通，代价 lcm(u, v)。
 *    方案 B: 通过全局最小合法点【2】进行中转，代价 lcm(u, 2) + lcm(2, v)。
 *            (因为经过 3 的代价至少是 3u+3v，而 2 只要 2u+2v，2 永远是最优第三方桥梁)
 * 
 * 【复杂度分析】
 * 由于 T <= 1000，a, b <= 10^7。
 * 直接 O(sqrt(N)) 暴力求最小质因数，单次最多循环 3162 次。
 * 总计算量约 3*10^6 次，远低于 1 秒时限。因此不需要写 O(N) 埃氏筛预处理，省时间省空间！
 * =================================================================================
 */
void solve(){
    int a,b; cin >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    if(b % a == 0){
        cout << b << endl;
        return;
    }
    if(gcd(a,b) >= 2){
        // a -> g -> b
        // gcd(a,b) = g
        // lcm(a,g) = a
        // lcm(g,b) = b
        cout << min(lcm(a,b), a+b) << endl;
    }else{
        int pa = a;
        for(int i = 2; i*i <= a; i++){
            if(a % i == 0){
                pa = i;
                break;
            }
        }
        int pb = b;
        for(int i = 2; i*i <= b; i++){
            if(b % i == 0){
                pb = i;
                break;
            }
        }

        int ans = lcm(a, b);

        vector<pii> Sa;
        Sa.push_back({a, 0});
        if(pa < a) Sa.push_back({pa, a}); // 如果 a 是合数，付出 a 的代价降级到最小质因数 pa
        vector<pii> Sb;
        Sb.push_back({b, 0});
        if (pb < b) Sb.push_back({pb, b}); // 如果 b 是合数，需要付出 b 的代价从 pb 升上来

        auto dist = [&] (int u, int v) -> int {
            if (u == v) return 0;
            return min(lcm(u, v), lcm(u, 2LL) + lcm(2LL, v));
        };

        for (auto [u, cost_u] : Sa) {
            for (auto [v, cost_v] : Sb) {
                ans = min(ans, cost_u + cost_v + dist(u, v));
            }
        }
        cout << ans << endl;        
    }
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
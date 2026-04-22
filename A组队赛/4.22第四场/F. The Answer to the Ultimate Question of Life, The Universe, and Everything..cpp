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
// https://qoj.ac/contest/1834/problem/9706

/*
 * 题目：The Answer to the Ultimate Question of Life, The Universe, and Everything (QOJ 9706)
 * 题意：给定 x (0 <= x <= 200)，求 a, b, c ∈ [-5000, 5000] 满足 a^3 + b^3 + c^3 = x。多组询问。
 * * 核心思路：离线打表预处理 + 双指针降维优化
 * * 1. 发现瓶颈：
 * 直接枚举 a 和 b，再二分查找 c 的复杂度为 O(N^2 log N)。
 * 即 10000 * 10000 * 14 ≈ 1.4*10^9 次运算，在多组询问下极大可能会 TLE。
 * * 2. 逆向思维（离线打表）：
 * 既然查询的 x 范围极小 [0, 200]，但搜索空间巨大，我们直接“反客为主”。
 * 预先遍历搜索空间，把 0~200 的答案全部预处理出来存进数组，查询时直接 O(1) 输出。
 * * 3. 砍掉冗余（消除对称性）：
 * 加法满足交换律，a, b, c 怎么排列和不变。我们强行规定 a <= b <= c，
 * 这一步可以直接把搜索的常数空间缩小 6 倍（3 的阶乘）。
 * * 4. 降维打击（双指针 O(N^2)）：
 * - 外层循环固定 a，枚举范围 [-5000, 5000]。
 * - 内层不再使用嵌套 for+二分，而是利用单调性使用双指针：
 * 左指针 b = a 往右走，右指针 c = 5000 往左走。
 * - 计算 sum = a^3 + b^3 + c^3：
 * 如果 sum > 200：说明整体偏大，只能缩小右边界，c--。
 * 如果 sum < 0：说明整体偏小，只能增大左边界，b++。
 * 如果 0 <= sum <= 200：命中目标区间，记录答案！
 * - 注意细节：为了防止在命中 [0, 200] 时，由于 c^3 在零点附近的差值较小而漏掉同区间的其他解，
 * 可以用一个临时变量向下稍微探测一下 c，随后让 b++ 继续探索。
 * * 复杂度：预处理时间复杂度被压至 O(N^2) 级别（最坏约 5*10^7 次运算），单次查询 O(1)，完美 1s 过题。
 */

struct node{
    int a, b, c;
    bool ok = false;
} ans[205];
void init() {
    // 规定 a <= b <= c，砍掉无意义的全排列搜索
    for(int a = -5000; a <= 5000; a++){
        int b = a;
        int c = 5000;
        int a3 = a * a * a;
        // 双指针降维扫
        while (b <= c)
        {
            int b3 = b * b * b;
            int c3 = c * c * c;
            int sum = a3 + b3 + c3;
    
            if(sum > 200){
                c--; 
            } else if (sum < 0) {
                b++;
            } 
            else  {
                // 落在 [0, 200] 的目标射程内
                if (!ans[sum].ok) ans[sum] = {a, b, c, true};
                
                // 由于连续 c 的立方差可能较小，稍微向下探一下，以防漏掉同属于 [0, 200] 的区间值
                int c1 = c - 1;
                while(c1 >= b){
                    int sum1 = a3 + b3 + c1 * c1 * c1;
                    if(sum1 >= 0){
                        if(sum1 <= 200 && !ans[sum1].ok)  ans[sum1] = {a, b, c1, true};
                        c1--;
                    } else {
                        break;
                    }
                }
                b++; // 探索当前 a 下的其他可能
            }
        }
    }
}

void solve(){
    int x;
    cin >> x;
    if (ans[x].ok) {
        cout << ans[x].a << " " << ans[x].b << " " << ans[x].c << endl;
    } else {
        cout << "impossible" << endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    init();
    cin >> T;
    while(T--)
        solve();
    return 0;
}
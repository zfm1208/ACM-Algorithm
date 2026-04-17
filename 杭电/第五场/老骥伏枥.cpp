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
 * 【核心思路与推导：位运算建图的本质】
 * * 1. 翻译建图条件（看透本质）：
 * 题目条件：popcount(i ⊕ j) == 1 意味着两点连边。
 * 异或后二进制中只有 1 个 1，说明 i 和 j 的二进制表示中【只有刚好一位不同】。
 * 换句话说，赛道上每走一步，就等价于将当前所在编号的二进制翻转其中的某一位（0变1，或1变0）。
 *
 * 2. 理想状态下的最短路：
 * 如果没有任何限制，从起点 A 走到终点 B，每次只能翻转一个二进制位。
 * 那么 A 和 B 有几个二进制位不同，就需要翻转几次。
 * 不同位的个数正好就是：popcount(A ⊕ B)。
 * 所以，从起点 1 到终点 n 的“理想最短路”长度就是 popcount(1 ⊕ n)。
 *
 * 3. 边界条件与陷阱分析（为什么不需要绕路？）：
 * 题目限制：打卡点编号是正整数（1, 2, 3...），也就是说【绝对不能走 0 号点】。
 * 我们需要验证，不走 0 号点会不会导致我们被迫绕远路？
 * 起点是 1（二进制末位为 1）。
 * - 情况 A：终点 n 是奇数（末位也是 1）。
 * 在 1 变 n 的过程中，末位的 1 始终不需要翻转，因此整个数字永远不可能是 0。
 * 可以直接按任意顺序翻转其他位，绝对安全。
 * - 情况 B：终点 n 是偶数（末位是 0）。
 * 这意味着迟早要把 1 的末位翻转成 0。如果第一步就翻转末位，1 就会变成 0，踩到陷阱。
 * 但由于 n 是【正偶数】（n >= 2），除了末位的 0，其高位必定至少含有一个 1（例如 4 是 100，4 的高位有 1）。
 * 策略：我们可以改变翻转顺序！先翻转高位那个 1（此时数字变大，绝对不为 0），
 * 最后再去翻转末位的 0。这样就完美借助了中间节点避开了 0，且步数没有丝毫增加。
 *
 * 4. 最终结论：
 * 无论终点是什么，限制条件（不能有 0）都不会增加我们的翻转次数。
 * 最短路长度恒等于理想状态的步数：popcount(1 ⊕ n)。
 * * 时间复杂度: O(1) （借助 __builtin_popcountll 内置函数）
 * 空间复杂度: O(1)
 */
void solve(){
    int n; cin >> n;
    cout << __builtin_popcountll(1LL ^ n) << endl;
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
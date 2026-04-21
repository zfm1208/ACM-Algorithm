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
// https://qoj.ac/contest/1071/problem/5303

/*
    * 因为我们可以自由决定顺序，最后的穿戴顺序可以被分为三部分
    1. 前面一批总sum <= k, 可以完全吃满
    2. 中间有一件 直接吃到之间的 强化
    3. 后面的 完全吃不到 贡献为0

    * 联想到一个背包为k的0-1背包 dp， 但有一个特权，你可以最多萱一个物品，只吃到它的一部分贡献 
    我们要记录当前是否已经用了那个“部分强化”的特权
    dp[j][0]: 当前共使用了j容量，且全是完全强化的
    dp[j][1]: 当前共使用了j容量，且已经包含了一件部分强化的最大收益

    * 状态转移
    初始化-1 表示不可达
    对于第i件装备, 基础强度为pi, 我们从容量j 倒推 0 
    A : 作为完全强化加入 此时还没用过特权
    dp[j][0] = max(dp[j][0], dp[j-pi][0] + w[i][pi])
    B : 作为唯一的 部分强化 加入 (假设消耗了c) (1 <= c < pi)
    dp[j][1] = max(dp[j][1], dp[j-c][0] + w[i][c])
    C : 作为完全强化加入, 但此时已经 使用过了 特权
    dp[j][1] = max(dp[j][1], dp[j-pi][1] + w[i][pi])

    * 最终答案
    可能一直用完全强化 没触发 特权 max(dp[j][0]) range j (0,k)
    我们触发了 特权 dp[k][1]
*/  

/*
    这道题一开始看完题会想到dp，但题目给出每个物品的贡献不少一定的，会卡思路
    在传统背包中，一个物品选与不选，它的重量和价值是死绑定的，固定的
    这就满足了dp的一个核心前提 -- 无后效性
    但这道题，物品如果触发了 "部分强化" 它的收益取决于前面选了多少东西，这就有了强烈的后效性

    为了解决这个问题，我们可以给dp升维
    既然物品的身份，会从完全强化 变成 部分强化 且整个过程只能突变一次 
    那我们就把这个是否突变过作为一种状态记录下来
    我们把dp[j] 升维 成 dp[j][0] 和 dp[j][1]
    通过来增加这个维度，我们可以把任何处于1状态的路线，必定是从某个0状态演变过来的

    还有一点，对于部分强化时候选择哪个贡献？
    如果我们去想，我要把第i个物品当作部分强化， 我得去查查前面用了多少容量，这样很难做
    因为你不知道前面是怎么组合的

    我们可以化被动为主动
    我们直接暴力假设他是占用的容量是c，提供的收益就是w[c]
    接下来只用去查看，是否合法就行

*/
void solve(){
    int n,k;cin >> n >> k;
    vector<vector<int>> dp(k+1, vector<int>(2,-1));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        int p; cin >> p;
        vector<int> w(p+1);
        for(int x = 1; x <= p; x++){
            cin >> w[x];
        }
        for(int j = k; j >= 0; j--){
            // 情况A
            if(j >= p && dp[j-p][0] != -1){
                dp[j][0] = max(dp[j][0], dp[j-p][0] + w[p]);
            }
            // 情况B
            for(int c = 1; c < p; c++){
                if(j >= c && dp[j-c][0] != -1){
                    dp[j][1] = max(dp[j][1], dp[j-c][0] + w[c]);
                }
            }
            // 情况C
            if(j >= p && dp[j-p][1] != -1){
                dp[j][1] = max(dp[j][1], dp[j-p][1] + w[p]);
            }
        }
    }
    int ans = 0;
    for(int j = 0; j <= k; j++){
        ans = max(ans, dp[j][0]);
    }
    ans = max(ans, dp[k][1]);

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
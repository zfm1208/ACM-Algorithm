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
// https://qoj.ac/problem/6602

/*
    * 题意：台阶染成 b/r，区间内 r 数量为奇数的区间个数最多，并输出这些染色方案
    区间和 -> 前缀和
    pre[k] : 前k个台阶中r的总数量
    区间[i,j] 的 r 数量 = pre[j] - pre[i-1]
    两个数相减为奇数 -> 一奇一偶
    
    ! 区间r数为奇数 == pre[j] 和 pre[i-1] 的奇偶性不同
    cnt0 , cnt1 分别表示n+1个前缀中 前缀和偶数/奇数的个数
    满足条件的区间数 = cnt0 * cnt1
    我们要让 cnt0 * cnt1 最大, 又因为 cnt0 + cnt1 == n+1
    所以cnt0 和 cnt1 要尽可能相近  


    现在题意可以变成：  构造一个 b/r 字符串
    让它对应的前缀和奇偶性，满足 c0 和 c1 最接近（最优），且按字典序输出前 100 个
    * 为什么会想到用dfs呢？
    1. 我们要逐位构造字符串 每一位改选 r 还是 b
    2. 字典序要求, 优先选b, 在选r 
    3. 要剪枝, 如果dfs时发现 cnt0 / cnt1 的数量超过 (n + 2) / 2, 那就要return了
    4. 最多输出 100 个, 构造够了也要return 

    ! dfs 可以 逐位构造, 先搜b再搜r, 剪枝

    我们发现我们要记录cnt0,cnt1的数量, 并且还要记录当前是哪一位pos
    所以dfs参数可以设置这三个

    对于奇偶性, 我们可以发现只有r会对奇偶性产生变化, b并不会
    <1> : 选 b：前缀和奇偶性不变
    <2> : 选 r：前缀和奇偶性翻转（异或 1）

    为什么这么写当pos == n+1时输出一定是对的？
    因为 if(cnt0 > (n + 2) / 2 || cnt1 > (n + 2) / 2) return;
    这个条件的意思：只要当前奇偶数量超过最优上限，直接放弃这个分支
    只有满足最优条件的方案，才能走到递归终点（pos == n+1）并输出
    所有非最优解，在递归过程中就被剪掉了，根本不会输出


    * 题目转化：区间 r 数为奇数 → 前缀和奇偶性不同
    * 最优计算：满足条件的区间数 = c0×c1，c0、c1 越接近越大
    * 构造方案：用 DFS 逐位构造字符串，优先选 b（字典序）
    * 保证最优：剪枝去掉所有不满足 c0/c1 最优的情况
    * 输出限制：构造满 100 个立即停止
    
    ! 奇偶性是解题核心，因为区间和的奇偶性由前缀和奇偶性决定
*/
void solve(){
    int n; cin >> n;
    int ans = ((n+1) / 2) * ((n+2) / 2);
    cout << ans << endl;
    vector<int> odd(n+1);
    int cnt = 0;
    auto dfs = [&] (auto& self, int cnt0, int cnt1, int pos) -> void {
        if(cnt0 > (n + 2) / 2 || cnt1 > (n + 2) / 2) return;
        if(pos == n+1){
            for(int i = 1; i <= n; i++){
                if(odd[i] == odd[i-1]) cout << "b";
                else cout << "r";
            }
            cnt++;
            cout << endl;
            return;
        }
        odd[pos] = odd[pos-1];
        if(odd[pos-1] == 0) {
            self(self,cnt0+1,cnt1,pos+1);
            if(cnt == 100) return ;
        }
        else {
            self(self,cnt0,cnt1+1,pos+1);
            if(cnt == 100) return ;
        }
        odd[pos] = odd[pos-1]^1;
        if(odd[pos-1] == 0) {
            self(self,cnt0,cnt1+1,pos+1);
            if(cnt == 100) return ;
        }
        else {
            self(self,cnt0+1,cnt1,pos+1);
            if(cnt == 100) return ;
        }
    };
    dfs(dfs,1,0,1);
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
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
// 这一题数据范围很小就是让我们dfs暴力+剪枝的
/*
    我们从(0,0)开始,一个一个格子地往右下填数字

    !填什么：
    对于当前格子，数字最小是 0，
    最大不能超过：L - 这行已有的数字之和，
    也不能超过 L - 这列已有的数字之和

    !剪枝：
    当你填到某一行的最后一列时，你不需要枚举了！
    为了让这行的和等于 L ，这个格子的数字只能是 L - 当前行已有的和
    同理，填到某一列的最后一行时，这个数字也只能是 L - 当前列已有的和

    只用猜(n-1)*(n-1)个格子即可

    我们看到这个数据范围，要想到dfs

    !怎么判断边界？（什么时候停下来？）也就是你的 if 终止条件。
    成功到达终点： 
    矩阵是从第 0 行一直填到第 N-1 行。如果现在准备填第 N 行了（r == n），
    说明前面全填满且合法了，这就产生了一种答案，ans++，然后 return（结束这条分支的探索）。
    换行逻辑： 从左往右填，当列数超过最大列数（c == n）时，说明这一行填完了，应该换到下一行的开头：dfs(r + 1, 0)

    !当前状态选什么？ 
    最小0
    题目要求每行每列和都是 L ,所以当前格子能填的极限是：
    这行还剩多少配额（L - row_sum），以及这列还剩多少配额（L - col_sum），两者取个最小值

    ! 回溯
    回溯的意义是这一条路走完了一直return到当前，不管这一条路怎么样，我们要进行下一条路，然后要把上次加的数减去
    试探 -> 递归下一步 -> 清理现场
    */
int l,n;
int row_sum[5];
int col_sum[5];
int ans = 0;
void dfs (int r, int c) {
    if(r == n){
        ans++; return;
    }
    if(c == n){
        dfs(r + 1, 0);
        return;
    }
    if(c == n-1){
        int val = l - row_sum[r];
        if(val >= 0 && col_sum[c] + val <= l){
            if(r == n - 1 && col_sum[c] + val != l) return;
            row_sum[r] += val;
            col_sum[c] += val;
            dfs(r, c + 1);     
            row_sum[r] -= val;
            col_sum[c] -= val;
        }
        return;
    }
    if(r == n - 1){
        int val = l - col_sum[c];
        if (val >= 0 && row_sum[r] + val <= l) {
            row_sum[r] += val;
            col_sum[c] += val;
            dfs(r, c + 1);
            row_sum[r] -= val;
            col_sum[c] -= val;
        }
        return;
    }
    int max_val = min(l - row_sum[r], l - col_sum[c]);
    for(int i = 0; i <= max_val; i++){
        row_sum[r] += i;
        col_sum[c] += i;
        dfs(r, c + 1);
        row_sum[r] -= i;
        col_sum[c] -= i;
    }
}
void solve(){
    cin >> l >> n;
    dfs(0,0);
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
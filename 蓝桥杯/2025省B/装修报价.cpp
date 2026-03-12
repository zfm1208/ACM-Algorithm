#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using namespace std;
const int mod = 1e9+7;
/*
    正解：
    题目让求所有可能情况得总和, 我们肯定发现不能一个一个算式去求和,
    应该观察每一个数得贡献
    横着看：
    A1 + A2 + A3 ...
    A1 + A2 - A3 ...
    A1 + A2 ^ A3 ...
    ...

    竖着看：
    我们不关心整个算式等于几,我们可考虑某个位置
    一个位置前面可以是+,也可以是-，而且几率可能都是一样的
    所以 累加起来 得贡献是0

    我们可以手玩几个样例N = 3 / 4 去找找规律,可以靠暴力解法验证

    总结：
    看到了: 求所有总和/总期望  -> 算贡献
    有+有-(或者等概率正负) -> 找有没有什么可以消掉
    没有头绪的话可以暴力找规律


    这一题我们不能单单算每种式子得和再累加
    这样肯定不合理，那我们就去看条件有+有- 是不是可以下消掉
    最后得答案和什么有关呢？ 手玩几个样例看看
    
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> p(n+1);
    p[0] = 1;
    for(int i = 1; i <= n; i++){
        p[i] = p[i-1] * 3 % mod;
    }
    int sum = 0;
    int cur = 0;
    for(int k = 1; k <= n; k++){
        cur ^= a[k];
        if(k < n){
            int t = (2 * p[n-1-k]) % mod;
            sum = (sum + cur % mod * t % mod) % mod;
        }else{
            sum = (sum + cur % mod) % mod;
        }
    }
    cout << sum << endl;
}
// 暴力 bfs每个间隙是什么符号,只能得25分
// struct node{
//     int id;
//     int sum;
//     int yh;
//     int op;
// };
// void solve(){
//     int n; cin >> n;
//     vector<int> a(n+1);
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     int tot = 0;
//     queue<node> q;
//     q.push({2,0,a[1],1});
//     while(!q.empty()){
//         node u = q.front();
//         q.pop();
//         if(u.id > n){
//             tot  = (tot + (u.sum + u.yh *  u.op) % mod + mod) % mod;
//         }else{
//             q.push({u.id + 1, u.sum, u.yh ^ a[u.id],  u.op});
//             q.push({u.id + 1, u.sum + u.op * u.yh, a[u.id],1});
//             q.push({u.id + 1, u.sum + u.op * u.yh, a[u.id],-1});
//         }
//     }
//     cout << tot << endl;
// }

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}
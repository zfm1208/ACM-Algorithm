#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
// #define endl '\n'   交互题必须关！！！
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1 << 30;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

/*
    !交互题 / 图论 / 倍增
    !题目大意：
        有一个隐形的 DAG，按字典序给出所有路径
        通过询问第 k 小的路径，在 32*(N+M) 次询问内还原所有边
    !核心思路：
        1. 询问限制分析：32 对应 log(2^30)，提示我们要对每条边进行二分或倍增查找。
        2. 字典序性质：以边 (u->v) 开头的所有路径在字典序列表中是连续的一段区间
        3. 算法流程
           - 维护全局指针 now，指向当前未处理的路径
           - 对于每个点 u：
             a. 跳过路径 [u] (now++)
             b. query(now) 得到路径 u->v...，确认边 (u, v)
             c. 利用倍增 (30次询问) 探测以 u->v 开头的路径数量 jump
                - 若 query(now + jump + (1<<k)) 仍以 u->v 开头，则 jump += (1<<k)
             d. now += jump + 1，跳过这段区间，直接寻找 u 的下一条邻边
             
    !复杂度：O(M * 30 + N) < 32*(N+M)。
*/

void solve(){
    int n; cin >> n;
    auto ask = [&](int k) -> vector<int> {
        cout << "? " << k << endl;
        int len; cin >> len;
        if(len == 0) return {};
        if(len == -1) exit(0);
        vector<int> path(len);
        for(int &x: path) cin >> x;
        return path;
    };
    vector<pii> ans;
    int now = 1;    
    for(int u = 1; u <= n; u++){
        now++;
        while(1){
            vector<int> path = ask(now);
            if(path.size() == 0 || path.size() < 2) break;
            int v = path[1];
            ans.pb({u,v});
            int jump = 0;
            for(int k = 30; k >= 0; k--){
                int tar = now + jump + (1LL << k);
                vector<int> tp = ask(tar);
                if(tp.size() >= 2 && tp[0] == u && tp[1] == v){
                    jump += (1 << k);
                }
            }
            now += (jump + 1);
        }
    }
    cout << "! " << ans.size() << endl;
    for(auto [u,v]: ans){
        cout << u << " " << v << endl;
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
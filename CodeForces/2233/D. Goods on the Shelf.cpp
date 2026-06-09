#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

/*
    题解：D. Goods on the Shelf —— 从宏观特征到局部 O(1) 差分的降维打击

    【题目核心】
    给定一个长度为 n 的货架数组，要求最多交换一次两个商品的位置，使得所有同种商品都“连续”地摆放在一起。求是否可行。

    【破局核心：寻找宏观特征量】
    处理这类“连续块”问题，最优雅的方式是寻找整体特征量。我们定义：
    1. 目标种类数 D：数组中不同元素的总种类数（例如 [1,2,1] 中 D=2）。在代码中对应 nn。
    2. 当前连续块数 B：数组中连续相同元素构成的块的数量（即满足 a[i] != a[i-1] 的次数加 1）。在代码中对应 cnt。

    神仙结论：一个货架满足要求，当且仅当 B = D。（因为每种元素至少形成一个块，只有当大家都不被割裂时，块数才等于种类数）。

    ---------------------------------------------------------

    【算法推导：破局三步走】
    想要把暴力的 O(N^2) 枚举降维，我们需要进行以下三步剪枝与优化：

    第一步：定死刑线（极限剪枝）
    每次交换两个元素（u 和 v），最多只会改变它们左右相邻的 4 个边界（u-1, u, v-1, v）。
    也就是说，一次完美的交换，最多只能消灭 4 个多余的断点。
    - 如果 B == D，已经完美，直接输出 YES。
    - 如果 B - D > 4，即使大罗金仙来做一次最完美的交换也救不回来，直接输出 NO。

    第二步：缩小范围，锁定“嫌疑人”
    既然 B - D <= 4，说明全场最多只有 4 个多余的断层，绝大部分商品都乖乖地待在自己的连续块里。
    如果要交换，必须去动那些被“割裂”的元素块（即出现次数 > 1 的块）。
    我们只需找出这些被劈开的块的边界（L 和 R），以及紧挨着边界的相邻元素（L-1 和 R+1），将其放入候选集合 S 中。
    由于多余断层 <= 4，集合 S 的大小极其有限（通常 <= 20 个元素）。这样，我们将交换的第一方 u 的枚举范围从 O(N) 降维到了极小常数 O(1)。

    第三步：局部差分，O(1) 高速校验
    现在我们枚举 u 属于 S，以及任意位置 v 属于 [1, n] 进行尝试。
    如果在每次尝试时都去遍历整个数组算一次新的 B，时间复杂度依然会超时。
    但交换是局部手术，全场 99% 的断点都不会变。我们只需检查交换受波及的 4 个缝隙：
    1. 去重并提取合法的受影响缝隙集合。
    2. 算一下交换前这些缝隙贡献了几个断点（old_local）。
    3. 模拟交换，算一下这些缝隙现在贡献了几个断点（new_local），然后还原现场。
    4. 新总块数 = 原总块数 - old_local + new_local。
    如果新总块数等于 D，则找到了绝杀方案，输出 YES。

    ---------------------------------------------------------

    【复杂度分析】
    - 预处理 D 和 B 以及候选集 S：O(N log N)（来源于 Set 和 Map 的常数，也可优化至 O(N)）。
    - 核心枚举验证：u 遍历大小 <= 20 的集合，v 遍历 1...n，内部验证 O(1)。验证总耗时 O(C * N)。
    - 整体时间复杂度：O(N log N)，空间复杂度 O(N)。在 2 * 10^5 的数据规模下轻松 AC。
*/

void solve(){
    int n; cin >> n;
    vii a(n+1);
    set<int> st;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    int nn = st.size(); // 目标的分裂个数
    vii b = a;
    sort(b.begin()+1, b.end());
    int cnt = 1; // cnt : 原本的分裂块数
    for(int i = 2; i <= n; i++){
        if(a[i] != a[i-1]){
            cnt++;
        }
    }
    if(cnt == nn){
        cout << "YES" << endl;
        return;
    }
    if(cnt - nn > 4){
        cout << "NO" << endl;
        return;
    }
    map<int, vector<pii>> cun;
    int l = 1;
    for(int r = 1; r <= n; r++){
        if(r == n || a[r] != a[r+1]){
            cun[a[l]].pb({l, r});
            l = r + 1;
        }
    }
    /*
        3 3 4 3 3 4 4 4 3 4
        [  ][][  ] [   ][][]
    */
    set<int> st1;
    for(auto& [x, qj]: cun){
        if(qj.size() == 1) continue;
        for(auto &[L, R]: qj){
            if(L - 1 >= 1) st1.insert(L - 1);
            st1.insert(L);
            st1.insert(R);
            if(R + 1 <= n) st1.insert(R + 1);
        }
    }
    auto check = [&](int u, int v) -> bool {
        vii idx = {u - 1, u, v - 1, v};
        vii cun1; 
        for(int i : idx){
            if(i >= 1 && i < n){ 
                bool ok = 0;
                for(int j : cun1){
                    if(j == i) { ok = true; break; }
                }
                if(!ok) cun1.pb(i);
            }
        }
        int cnt1 = 0;
        for(int i : cun1){
            if(a[i] != a[i+1]) cnt1++;
        }
        swap(a[u], a[v]);
        int cnt2 = 0;
        for(int i : cun1){
            if(a[i] != a[i+1]) cnt2++;
        }
        swap(a[u], a[v]);
        return (cnt - cnt1 + cnt2) == nn;
    };
    for(int u: st1){
        for(int v = 1; v <= n; v++){
            if(u != v && check(u, v)) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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
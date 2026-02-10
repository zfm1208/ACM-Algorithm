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
    题目：Nikita and LCM (Codeforces Round 950 D)
    题意：求数组 a 的最长子序列，使得该子序列的 LCM 不在数组 a 中。
    
    !【核心思路 & 切入点】
      1. 贪心判全集：
        首先计算整个数组的 LCM。如果 LCM > max(a) 或者 LCM 不在 a 中，
        说明选所有数就是最优解，直接输出 n。
      2. 关键推论 (反向思维)：
        如果全集的 LCM 在数组中（必然是 max(a)），那么最优解的 LCM 一定是 max(a) 的【因子】。
        因为子序列的 LCM 必然能整除全集的 LCM。
    ! 【算法流程】
        1. 排序数组，用 Set 记录存在的数以便 O(1) 查询。
        2. 计算全集 LCM，若不存在于 Set 中，输出 n。
        3. 若全集 LCM 存在，则遍历 max(a) 的所有因子 tar_lcm：
        - 若 tar_lcm 已经在数组中，跳过（不合法）。
        - 若 tar_lcm 不在数组中，尝试构造：
        遍历数组 a，贪心选取所有能整除 tar_lcm 的数。
        计算这些数的 now_lcm，若 now_lcm == tar_lcm，则统计长度并更新答案。
    ! 【复杂度】
        时间：O(N * d(K))，其中 K 是数组最大值，d(K) 是因子个数。
        对于 10^9 范围，因子数很少，完全可过。
 */

 /*
    如果一开始整个数组的LCM就合法,那就直接输出 n
    否则：
    不要去想怎样能凑出一个好的LCM,而是反过来想:
    假如我已经确定好了最终的LCM是tar
    为了让序列最长,我应该选哪些数？
    遍历数组,如果tar % a[i] == 0,那么这个数可以选
    最后看看选的数的lcm是否是tar即可,然后更新ans

    那这个tar可能是谁？
    我们来思考, 这个数组的LCM很好求，那他的子序列的lcm' 肯定是 LCM 的因子
    而LCM = max(a)
    所以我们可以枚举LCM的因子然后更新答案即可
 */
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    set<int> st;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    sort(a.begin()+1,a.end());
    int lcm = 1;
    auto get = [&] (int a, int b) -> int {
        return (a * b / __gcd(a,b));
    };
    for(int i = 1; i <= n; i++){
        lcm = get(lcm, a[i]);
        if(lcm > a[n]){
            cout << n << endl;
            return;
        }
    }
    if(st.find(lcm) == st.end()){
        cout << n << endl;
        return;
    }
    int mx = a[n];
    vector<int> yz;
    for(int i = 1; i * i <= mx; i++){
        if(mx % i == 0){
            yz.pb(i);
            if(i*i != mx) yz.pb(mx/i);
        }
    }
    int ans = 0;
    for(int tar_lcm: yz){
        if(st.count(tar_lcm)) continue;
        int now_lcm = 1;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(tar_lcm % a[i] == 0){
                now_lcm = get(now_lcm , a[i]);
                cnt++;
            }
        }
        if(now_lcm == tar_lcm){
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
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
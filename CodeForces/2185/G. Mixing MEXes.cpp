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
    给你n个数组，每个数组有m_i个数
    然后你可以将一个数组里面任意一个数删掉然后加到其他数组的最后面(这算一次操作)
    然后这一次的贡献就是 n的数组中各个数组mex的和
·
    目标： 求出来对于所有情况的和(所有交换情况累加的和，每次情况单独处理)

    暴力： 枚举n个数组，再枚举每个数组的数，在枚举放到其他数组，然后暴力求一下mex，最后累加，肯定超时

    根据题目的数据范围，这一题只能O(n^2)实现，也就是枚举每个数组的每个数，然后直接得到每次的答案，最后累加

    那我们就要考虑每个数对于所有数组的贡：
    对于这个数所在的数组取出来后有没有造成mex减小？
    对于其他数组有没有造成其他数组mex增大？
    增大的话增大了多少？ 
    这个数对于其他数组的哪些数组有增量？

    上述问题必须在O(1)内解决，很明白我们要预处理，要提前知道每个数组的mex，以及next_mex(可以求得增量)
    还要预处理 对于其他哪些数组有贡献

    solution：
    1. 预处理每个数组的mex和nmex
    2. 预处理所有数组一开始的mex之和 记为sum
    3. 预处理当前数组如果得到当前mex，他的下一个nmex减去当前mex的贡献，用一个 '桶' 来存
    4. 跑一编n个数组的每个数，考虑当前这个数x的贡献
    5. 当前x可以对其他n-1的数组有贡献，或者对其他某些数组有贡献？
    6. 当前x取出来对于原来数组有没有贡献，减少的话减少了多少？ 
*/
void solve(){
    int n; cin >> n;
    vector<vector<int>> a(n);
    vector<int> mex(n),nmex(n);
    auto get = [&] (int len, const vector<int> & arr) -> pii {
        vector<int> vis(len+2);
        for(int x: arr) if(x <= len + 1) vis[x] = 1;
        int mex1 = 0, mex2 = 0;
        while(vis[mex1]) mex1++;
        mex2 = mex1 + 1;
        while(vis[mex2]) mex2++;
        return {mex1, mex2};
    };
    int mx = 0;
    for(int i = 0; i < n; i++){
        int len; cin >> len;
        a[i].resize(len);
        for(int j = 0; j < len; j++){
            cin >> a[i][j];
        }
        auto [x,y] = get(len,a[i]);
        mex[i] = x;
        nmex[i] = y;
        mx = max(mx, x);
    }
    int sum = 0;
    for(int x: mex) sum += x;
    vector<int> tong(mx+1);
    for(int i = 0; i < n; i++){
        tong[mex[i]] += (nmex[i] - mex[i]);
    }
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        map<int,int> mp;
        for(int x: a[i]) if(x < mex[i]) mp[x]++;
        for(int x: a[i]){
            int cur = (n - 1) * sum;
            if(x < mex[i] && mp[x] == 1){
                cur -= (mex[i] - x) * (n - 1);
            }
            if(x < mx + 1){
                cur += tong[x];
                if(mex[i] == x){
                    cur -= (nmex[i] - mex[i]);
                }
            }
            ans += cur;
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

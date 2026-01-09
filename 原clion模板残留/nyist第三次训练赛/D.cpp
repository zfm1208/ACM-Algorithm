//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
// n  => 5e3   ---->  n^2
// 2 * n * n   ---->  5e7
void solve() {
    int n;cin >> n;
    vector<int> a(n);
    for(int &x : a)cin >> x;
    int ans = 0;
    for(int i = 0;i < n; i ++){//枚举区间左端点
        stack<pii> st;
        // st栈里面都是递增的区间
        for(int j = i; j < n; j++){//枚举区间右端点
            pii p={a[j],a[j]};//区间最小值和区间最大值
            //如果栈顶区间的最大值大于当前元素，则该元素需要与栈顶区间融合
            //也就是排序的时候需要一起排
            while(st.size()&&st.top().second>a[j]){
                p.first=min(st.top().first,p.first);//更新区间最小值
                p.second=max(st.top().second,p.second);//更新区间最大值
                st.pop();//弹出栈顶区间
            }
            st.push(p);//当栈顶区间的最大值小于当前元素或者栈中没有区间的时候
            //说明已经不需要将当前元素继续向前融合区间
            ans += j-i+1-st.size();
            // j-i+1这是当前子数组的长度
            // st.size()这是栈中区间的数量，表示当前子数组中有多少个“有序区间”
        }
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}

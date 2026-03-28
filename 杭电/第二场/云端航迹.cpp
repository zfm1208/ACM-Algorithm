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
    假设当前异或和为X
    <1>: 一开始X = 0, 先手判负

    <2>: 当前 X != 0, 且数字个数为 add
    你必须拿走一个数字y, X' -> X ^ y
    如果 X' == 0,输了
    如果 X' != 0, 你把一个局面为： 个数为even,X != 0的局面给了下一个人
    <3>: 当前 X != 0, 且数字个数为 even
    你必须拿走一个数字y, X' -> X ^ y
    要让 X ^ y == 0, 你拿走的 y == X
    如果你所有操作都会X ^ y == 0, 那么数字堆里都是X
    既然数字全是X, 有偶数个, 他们异或和 = 0， 与我们前提 X != 0,违背
    所以，里面绝对有数 != X, 你只要把 != X的数拿走，就能把必败态该对面

    
    ! 当前数个数为even,且异或和 != 0  -> 必胜态
    ! 当前数个数为 add,且异或和 != 0  -> 必败态

    对于先手而言，怎么保证他能赢呢？
    区间异或和 != 0， 可以用前缀和O(1)处理
    区间长度为偶数, 可以枚举L,R, 看看(R-L+1) 是不是偶数,然后累加个数即可

    但这样的时间复杂度是O(n^2) 会超时

    怎么优化呢？ 正难则反

    我们知道任意奇数下标 / 偶数下标 的差值都是even
    也就是说,同奇同偶下标两两配对，都是长度为even的区间
    我们假设 奇数下标有ji个,偶数下标有ou个
    tot = ji*(ji-1) / 2 + ou*(ou-1) / 2
    那么这是区间长度为偶数的区间的个数，那么怎么找区间异或和不为0的呢？

    假如在偶数下标的点集中,有两个点i,j(i< j) 且pre[j] - pre[i-1] = 0
    
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1),pre(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }
    int add = (n+1)/2, even = n/2 + 1;
    int tot = add * (add - 1) / 2 + even * (even - 1) / 2;
    map<int,int> mp[2];
    for(int i = 0; i <= n; i++){
        mp[i%2][pre[i]]++;
    }
    int count = 0;
    for(auto [x,cnt]: mp[0]){
        count += (cnt - 1) * cnt / 2;
    }
    for(auto [x,cnt]: mp[1]){
        count += (cnt - 1) * cnt / 2;
    }
    int ans1 = tot - count;
    int ans2 = (n+1) * n / 2 - ans1;
    cout << ans1 << " " << ans2 << endl;
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
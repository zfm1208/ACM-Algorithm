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
    ! 题目给了一个复杂公式，我们的第一步是要去简化公式
    ! 最恶心的公式是|b[i] - b[i+1]|, 他跟顺序有关
    <1> : 看到绝对值求和，先想排序能否消去绝对值.

    在确定了选了哪些数的·时候,中间的绝对值就变成了b_max - b_min
    sum of |b[i] - b[i+1]| = b_max - b_min (已选数中)
    so :我们要把选择的信息按b从小到大的顺序排序

    <2> : cost = sum_of a[i] + (b_max - b_min)
    数据范围2000 -> O(n^2)
    所以我们可以用枚举区间的左右端点, 这时候, b_min, b_max就确定了
    当我们固定了区间[i ~ j]
    我们可以用剩下的钱sy = (l - (b_max - b_min)) 看看区间里面选哪些数

    * -> 在i到j的范围内, 选出尽可能多的a, 使得他们的和不超过 sy
    我们肯定选a小的,由于对区间里面的数进行排序再遍历会超时
    我们优化用 '大根堆' 来实现,
    随着j向右移, 我们每次只新添加一个a[j], 我们需要维护一个当前最小a的集合
    * -> 我们把遍历到的a都加到 堆 lim, 维护他们的和, 如果和超过 sy, 我们就pop掉最大的a
    然后随着j的移动，维护一个最大的ans即可
*/
struct node{
    int a,b;
};
void solve(){
    int n,l; cin >> n >> l;
    vector<node> arr(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i].a >> arr[i].b;
    }
    sort(arr.begin(),arr.end(),[](node x, node y){
        return x.b < y.b;
    });
    int ans = 0;
    for(int i = 1; i <= n; i++){
        priority_queue<int> pq;
        int sum = 0;
        for(int j = i; j <= n; j++){
            auto [a,b] = arr[j];
            pq.push(a);
            sum += a;
            while(!pq.empty() && sum + (b - arr[i].b) > l){
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, (int)pq.size());
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
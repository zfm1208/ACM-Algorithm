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
    f[x] = a1 * x^2 + b1 * x + c1
    g[x] = a2 * x^2 + b2 * x + c2
    若两个函数不相交 
    则 f[x] = g[x] 没有实数解
    (a1-a2) * x^2 + (b1-b2) * x + (c1-c2) = 0
    判别式 < 0 :=>
    (b1-b2) * (b1-b2) < 4 * (a1-a2) * (c1-c2)
    易知 4 * (a1-a2) * (c1-c2) > 0
    则 (a1-a2), (c1-c2) 必须同号
    1: a1 > a2, c1 > c2
    2: a1 < a2, c1 < c2

    构成偏序：
    a从小到大排序，相等再排b,c
    在这个排好序的序列里面，如果不相交，那么这个关系就是单向的(只能前者 < 后者)
    这就像在数组里找 '最长上升子序列'， 只不过'上升' 的定义是那个判别式

    题目要求对于每一个f[i], 找出包含它的最大整齐子集(两两不相交的集合)
    如果把'不相交' 看作一个 '连接' 关系, 实际就是在有向无环图上找通过点i的最长的路径
    最长路径 = (以i结尾的最长链) + (以i开始的最长链) - 1
    pre[i] : 排序后以第i个抛物线结尾的最长链的长度
    suf[i] : 排序后以第i个抛物线开始的最长链的长度
*/
struct node{
    int a,b,c;
    int id;
};
void solve(){
    int n; cin >> n;
    vector<node> f(n+1);
    for(int i = 1; i <= n; i++){
        cin >> f[i].a >> f[i].b >> f[i].c;
        f[i].id = i;
    }
    sort(f.begin()+1,f.end(),[](auto x, auto y){
        if(x.a != y.a) return x.a < y.a;
        if(x.b != y.b) return x.b < y.b;
        return x.c < y.c;
    });

    auto check = [&] (auto& x, auto& y) -> bool {
        if(x.a == y.a){
            return x.b == y.b && x.c < y.c;
        }
        return (x.b - y.b) * (x.b - y.b) < 4 * (x.a - y.a) * (x.c - y.c);
    };

    vector<int> pre(n+1);
    for(int i = 1; i <= n; i++){
        pre[i] = 1;
        for(int j = 1; j < i; j++){
            if(check(f[j],f[i])){ // 这个地方必须是 j 然后是 i
                pre[i] = max(pre[i], pre[j] + 1);
            }
        }
    }
    vector<int> suf(n+1);
    for(int i = n; i >= 1; i--){
        suf[i] = 1;
        for(int j = n; j > i; j--){
            if(check(f[i],f[j])){  // 这个地方必须是 i 然后是 j
                suf[i] = max(suf[i], suf[j] + 1);
            }
        }
    }
    vector<int> ans(n+1);
    for(int i = 1; i <= n; i++){
        ans[f[i].id] = pre[i] + suf[i] - 1;
    }
    rep(i,1,n) cout << ans[i] << " \n"[i==n];
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
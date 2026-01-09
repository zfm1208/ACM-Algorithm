#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 10;
using namespace std;
int a[N],b[N];
int n,m;
struct node{
    int l;
    int r;
    int x;
}w[N];

// 检查前x个订单是否可以满足
bool check(int x){
    memset(b,0,sizeof b); // 初始化差分数组
    for(int i = 1;i <= x;i++)
        b[w[i].l] += w[i].x, b[w[i].r+1] -= w[i].x; // 差分数组处理
    for(int i = 1; i <= n; i++){
        b[i] += b[i-1]; // 累加差分数组得到实际使用量
        if(b[i] > a[i]) // 如果某一天的使用量超过可用量
            return false;
    }
    return true;
}

void solve()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i]; // 输入每天可用的教室数量
    for(int i = 1;i <= m;i++)
        cin >> w[i].x >> w[i].l >> w[i].r; // 输入每个订单的信息

    // 二分查找最多可以满足多少个订单
    int l = 0, r = m;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid; // 如果前mid个订单可以满足，继续向右查找
        else r = mid - 1; // 否则向左查找
    }

    if(r == m){ // 如果所有订单都可以满足
        cout << 0 << endl;
        return ;
    } else { // 如果有订单无法满足
        cout << -1 << endl << l + 1 << endl; // 输出-1和第一个无法满足的订单编号
        return;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("classroom.in","r",stdin);
    freopen("classroom.out","w",stdout);
    int T = 1;
    while(T--) solve();
    return 0;
}
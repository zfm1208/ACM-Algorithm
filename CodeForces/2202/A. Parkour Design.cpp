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
    每次只能三种路径
    <1>:(x,y)->(x+2,y+1)
    <2>:(x,y)->(x+3,y)
    <3>:(x,y)->(x+4,y-1)
    求是否有一种路径可以从(0,0) -> (ex,ey)
    由于ex,ey的范围1e9不能暴力去求,所以只有找规律
    假设三种操作分别进行了a,b,c次
    (1):x = 2*a + 3*b + 4*c
    (2):y = a - c
    得: x - 2*y = 3 * (b+2*c)
    x-2*y是3的倍数才行
    其次经过画图可以发现，其实能走的地方都在两条射线之间，判断一下合法区间就行
*/
void solve(){   
    int x,y; cin >> x >> y;
    if((x - 2*y) % 3 == 0 && x >= 2 * y && x >= -4 * y){
        cout << "YES" << endl;
        return;
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
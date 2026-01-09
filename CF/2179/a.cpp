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
    任选i,j,若(j-i)%x == 0,si!=sj;
    余数为1
    1,1+x,1+2x,1+3x
    2,2+x,2+2x,2+3x
    ...
    每一组的元素互不相同，最多k
    一共x组
    最大满足为x*k
    最小不满足x*k+1

*/
void solve(){
    int k, x;
    cin >> k >> x;
    cout << (k * x) + 1 << endl;
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
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
    我们可以把跳跃过程作在网格上的向量平移。
    每两步（例如先向右，再向下）为一个完整的回合。
    一个回合后，我们在行上移动了 a，在列上移动了 b。

    要覆盖所有的行 :
    如果gcd(a, n) > 1，比如 a=2, n=4，
    那么你只能访问到第 1 行和第 3 行，永远到不了 2、4 行。
    因此，必须满足 gcd(a, n) = 1。
    
    要覆盖所有的行 :
    同理，要满足gcd(b,m) = 1;

    在满足前两个条件的前提下，
    我们一个完整回合的偏移量相当于每次行 +1 且列 +1

    我们从(1,1) 开始走，什么时候再次走到(1,1) ?
    假如走了k(回合), 那么 k % n == 0 && k % m == 0
    所以k 要满足 是n,m的最小公倍数
    k = lcm(n,m) = n*m / gcd(n,m)
    不难推断，最多走了2*lcm(n,m)个不同的格子
    因为，他走的痕迹恰好是2条对角线，每一个完整的回合(一右一下)会有两个格子被覆盖
    所以 2 * lcm(n,m) >= n * m
    ==> 2 * n * m / gcd(n,m) >= n * m
    ==> gcd(n,m) <= 2

*/
void solve(){
    int n,m,a,b; 
    cin >> n >> m >> a >> b;
    if(__gcd(a,n) == 1 && __gcd(b,m) == 1){
        if(__gcd(n,m) <= 2){
            cout << "YES" << endl;
            return;
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
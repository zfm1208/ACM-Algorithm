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
    n : n个选手 两两交战一次，胜者积一分，败者不计分
    共打 n*(n-1)/2 场
    z ：在任意z+1个人中, 总存在一个人能打败其他人
    总存在一个人会被其他人所打败
    问最后会有多少种得分情况
    (n,z <= 1e18)
    观察到数据范围之后，这一题说白了就是推一个公式或者在O(1)内解决

*/
void solve() {
    int n, z; cin >> n >> z;
    if (z == 1) {
        if (n % 2 != 0) cout << 1 << "\n";
        else cout << 2 << "\n";
        return;
    }
    if (n >= 2 * z) {
        cout << n << "\n";
        return;
    }
    if (n % 2 != 0) {
        cout << 2 * n - 2 * z + 1 << "\n";
    } else {
        cout << 2 * n - 2 * z + 2 << "\n";
    }
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
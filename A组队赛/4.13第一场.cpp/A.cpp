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
// https://qoj.ac/problem/6434

/*
    思路： 将所有的袋鼠聚集到任何一个角落，都固定需要2(n-1)步
    (a,b) 到四个顶点的距离是 
    int d1 = (a - 1) + (b - 1); 
    int d2 = (a - 1) + (n - b);
    int d3 = (n - a) + (b - 1);
    int d4 = (n - a) + (n - b);
    之和为[(a - 1) + (n - a)] * 2 + [(b - 1) + (n - b)] * 2 = 4(n-1)
    根据抽屉原理（鸽巢原理），
    这四个距离的总和恰好是 4(n - 1)，
    那么这四个距离中最小的一个必定小于或等于 n - 1
    所以我们只用计算出来距离(a,b) 最近的那一个，然后到那个顶点，然后再回到(a,b)即可
*/
void solve(){
    int n, a, b; cin >> n >> a >> b;
    int d1 = (a - 1) + (b - 1); 
    int d2 = (a - 1) + (n - b);
    int d3 = (n - a) + (b - 1);
    int d4 = (n - a) + (n - b);
    int min_d = min({d1, d2, d3, d4});
    string ans = "";
    if(min_d == d1){
        ans += string(n - 1, 'U'); 
        ans += string(n - 1, 'L'); 
        ans += string(a - 1, 'D'); 
        ans += string(b - 1, 'R'); 
    } 
    else if (min_d == d2) {
        ans += string(n - 1, 'U'); 
        ans += string(n - 1, 'R'); 
        ans += string(a - 1, 'D'); 
        ans += string(n - b, 'L'); 
    } 
    else if (min_d == d3) {
        ans += string(n - 1, 'D'); 
        ans += string(n - 1, 'L'); 
        ans += string(n - a, 'U'); 
        ans += string(b - 1, 'R'); 
    } 
    else {
        ans += string(n - 1, 'D'); 
        ans += string(n - 1, 'R'); 
        ans += string(n - a, 'U'); 
        ans += string(n - b, 'L'); 
    }
    cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}
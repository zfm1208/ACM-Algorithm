#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
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
题目相当于判断：将所有满足 u<v 且 p_u <p_v的 u 和 v 连边，最后所有点是否在同一个连通块中。
我们把 p 1∼p n分成两个部分 A,B，一开始，A 里面没有数，B 里面有所有数。
然后，我们从 p 1到 p n不断地将 p i从 B 中移除，加入到 A 中。i=1 时，如果 p 1>max{B}，
那么 1 不可以和后面的任何数连边，否则可以连边。在 i=1 时可以连边： p1​<max{B} 的前提下，
i=2 时，如果 min{p1,p2}>max{B}，说明 p1<p2且 p2为 2∼n 中 pi的最大值，那么 p2不可能和后面的点连边。
*/
void solve() {
    int n;cin >> n;
    vector<int> a(n+1);
    set<int> st1,st2;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        st2.insert(a[i]);
    }
    for(int i = 1; i < n; i++){
        st1.insert(a[i]);
        st2.erase(a[i]);
        if(*st1.begin() > *st2.rbegin()){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
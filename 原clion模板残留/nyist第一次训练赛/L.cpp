//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    vector<int> x(4), y(4);
    for(int i = 0; i < 4; ++i){
        cin >> x[i] >> y[i];
    }
    int mn1 = inf, mx1 = -inf;
    for(int i = 0; i < 4; ++i){
        if(x[i] < mn1) mn1 = x[i];
        if(x[i] > mx1) mx1 = x[i];
    }
    int mn2 = inf, mx2 = -inf;
    for(int i = 0; i < 4; ++i){
        if(y[i] < mn2) mn2 = y[i];
        if(y[i] > mx2) mx2 = y[i];
    }
    int l = max(mx1 - mn1, mx2 - mn2);
    int ans = l * l;
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}

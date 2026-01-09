#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = 2 * b - c;
    if(x > 0 && x % a == 0){
        cout << "YES" << endl;
        return;
    }
    if((a + c) % 2 == 0){
        int x1 = (a + c) / 2;
        if(x1 > 0 && x1 % b == 0){
            cout << "YES" << endl;
            return;
        }
    }
    x = 2 * b - a;
    if(x > 0 && x % c == 0){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
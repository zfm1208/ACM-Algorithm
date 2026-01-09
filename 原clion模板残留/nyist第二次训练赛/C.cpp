#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 5;
void solve() {
    int n, k;
    cin >> n >> k;
//    int pos = k;
//    if(pos != (n + 1) / 2) {
//        cout << -1 << endl;
//        return;
//    }
    // 1 2 3 4 5 6 7 8 9
    // （1） （2，3，4，5，6） （7，8，9）
    //   1         4            8
    //             4
    //        4 != (n+1)/2

    if(k == 1){
        if(n != 1){
            cout << -1 << endl;
            return;
        }else if(n == 1){
            cout << 1 << endl;
            cout << 1 << endl;
            return;
        }
    }
    if(k == n){
        cout << -1 << endl;
        return;
    }
    if(k&1){
        // n = 9 , k = 5
        // 1 2 3 4 5 6 7 8 9
        // 123  4  5  6  789
        // k = 3
        // 1 2 3 4 56789
        cout << 5 << endl;
        if(k == n-1){
            cout<<"-1\n";
            return;
        }
        cout << 1 << " " << k-1 << " " << k << " " << k + 1 << " " << k + 2 << endl;
    }else{
        cout << 3 << endl;
        cout << 1 << " " << k << " " << k + 1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
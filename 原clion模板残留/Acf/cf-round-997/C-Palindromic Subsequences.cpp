#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
const int N = 2e5 + 10;
using namespace std;
void solve() {
    int n;
    cin >> n;
    cout << "1 1 ";
    for (int i = 2; i <= n - 2; i++) {
        cout << i << ' ';
    }
    cout << "1\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}


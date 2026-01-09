#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int cnt = 1;
    for(int i = 2; i <= n; i++){
        if(a[i] != a[i-1]) cnt++;
    }
    cout << cnt << endl;

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}

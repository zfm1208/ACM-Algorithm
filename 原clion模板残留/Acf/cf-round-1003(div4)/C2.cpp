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
    int n,m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b.begin(), b.end());
    bool flag = true;
    if(b[0] - a[0] < a[0]) a[0] = b[0] - a[0];
    for(int i = 1; i < n; i++)
    {
        auto pos = lower_bound(b.begin(), b.end(), a[i] + a[i-1]);
        if(pos == b.end() && a[i] < a[i-1]){
            flag = false;
            break;
        }else if(pos != b.end()){
            if(a[i] >= a[i-1]){
                if(*pos - a[i] < a[i])
                    a[i] = *pos - a[i];
            }
            else a[i] = *pos - a[i];
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
